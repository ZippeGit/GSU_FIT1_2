/*
 * strassen.c
 *
 *  Created on: Apr 11, 2019
 *      Author: Merve Unlu
 */


#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>
#include "strassen.h"


/* Zaman olcum fonksiyonlari */
int timeval_subtract(struct timeval *result,
                     struct timeval *t2, struct timeval *t1) {
  long int diff =
    (t2->tv_usec + 1000000 * t2->tv_sec) -
    (t1->tv_usec + 1000000 * t1->tv_sec);
  result->tv_sec = diff / 1000000;
  result->tv_usec = diff % 1000000;
  return (diff < 0);
}


/* Verilen tek boyutlu diziyi rastgele
 * sayilarla doldurur.
 * Tek boyutlu dizinin bir matrisi
 * ifade etmesi icin ayrica pitch degiskeni kullaniliyor.
 * Ornegin: {2,3,4,6,7,8,1,2,3} dizisi pitch = 3 olarak
 * 3x3 luk bir matrisi ifade eder */
void matrand(int n, int pitch, double M[]) {
  const double r = 10.0;
  int i,j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      M[i*pitch + j] = r * (2*drand48() - 1);
    }
  }
}

/* Parametre olarak verilen matrisi ekrana basar.
 * Tek boyutlu oldugu icin pitch degeri kullanilir.*/
void matprint(int n, int pitch, const double M[]) {
  int i,j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      printf("%10.2f ", M[i*pitch + j]);
    }
    printf("\n");
  }
}


/* Parametre olarak verilen iki matrisin toplamini
 * yeni bir matriste saklar.
 * Verilen her matris icin pitch degeri vardir.
 * Ornek: A = | 2  3 |          B = | -3 0 |
 *            | -1 4 | Apitch=2     |  3 4 | Bpitch=2
 *
 *       Sonuc S = |-1 3 |
 *                 | 2 8 | Spitch=2
 */
void matadd(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]) {
  // TODO: Alistirma 1
  int d = 0;
  int i = 0;
  for (d = 0; d < Apitch*n; d += Apitch) {
    for (i = 0; i < Bpitch; i++) {
      S[d+i] = A[d+i] + B[d+i];
    }
  }
}



/* Parametre olarak verilen iki matrisin farkini
 * yeni bir matriste saklar.
 * Verilen her matris icin pitch degeri vardir.
 * Ornek: A = | 2  3 |          B = | -3 0 |
 *            | -1 4 | Apitch=2     |  3 4 | Bpitch=2
 *
 *       Sonuc S = |  5 3 |
 *                 | -4 0 | Spitch=2
 */
void matsub(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]) {
  // TODO: Alistirma 2
  int d = 0;
  int i = 0;
  for (d = 0; d < Apitch*n; d += Apitch) {
    for (i = 0; i < Bpitch; i++) {
      S[d+i] = A[d+i] - B[d+i];
    }
  }
}


/* MatrisVektor toplami: S = A + b */
void matvecadd(int n,
            int Apitch, const double A[],
            int bpitch, const double b[],
            int Spitch, double S[],int dim) {
  // TODO: Alistirma 3
  int d = 0;
  int i = 0;
  int a = 0;
  if (dim == 1) {
    for (d = 0; d < Apitch*n; d += Apitch) {
      for (i = 0; i < bpitch; i++) {
        S[d+i] = A[d+i] + b[a];
      }
      a++;
    }
  }

  else if (dim == 0) {
    for (d = 0; d < Apitch*n; d += Apitch) {
      for (i = 0; i < bpitch; i++) {
        S[d+i] = A[d+i] + b[i];
      }
    }
  }
}

/* A nin devrigi S matrisinde saklanacak. 
 */
void mattranspose(int n,
            int Apitch, const double A[],
            int Spitch, double S[]) {
  // TODO: Alistirma 4
  int d = 0;
  int i = 0;
  
  for(d = 0; d < Apitch; d++) {
    for(i = 0; i < n; i++) {
      S[(d*Spitch) + i] = A[(i*Apitch) + d];
    }
  }
}


/* Parametre olarak verilen iki matris
 * carpimini geri dondurur.
 * Klasik Matris carpimi algoritmasi: C = A * B
 * Ornek: A = | 2  3 |          B = | -3 0 |
 *            | -1 4 | Apitch=2     |  3 4 | Bpitch=2
 *
 *       Sonuc S = |  3 12 |
 *                 | 15 16 | Spitch=2
 * 
*/
void matmult(int n,
             int Apitch, const double A[],
             int Bpitch, const double B[],
             int Cpitch, double C[]) {
  // TODO: Alistirma 6
  int d = 0;
  int i = 0;
  int a = 0;
  int res = 0;

  for (d = 0; d < Apitch*n; d += Apitch) {
    for (i = 0; i < Bpitch; i++) {
      for (a = 0; a < Bpitch; a++) {
        res += A[d+a] * B[(a*Bpitch)+i]; 
      }
      C[d+i] = res;
      res = 0;
    }
  }
}



// TODO: Alistirma 7 
/* Parametre olarak verilen iki matris
 * carpimini geri dondurur.
 * Klasik Matris carpimi algoritmasi: C = A * B
 * Ornek: A = | 2  3 |          B = | -3 0 |
 *            | -1 4 | Apitch=2     |  3 4 | Bpitch=2
 *
 *       Sonuc S = |  3 12 |
 *                 | 15 16 | Spitch=2
 * Algoritma icin kullanilacak denklemler:
 *     X = | A  B |    Y = | E F |
           | C  D |        | G H |

       P0 = A * (F - H)
       P1 = (A + B) * H
       P2 = (C + D) * E
       P3 = D * (G - E)
       P4 = (A + D) * (E + H)
       P5 = (B - D) * (G + H)
       P6 = (A - C) * (E + F)
          _                                            _
     Z = | (P3 + P4) + (P5 - P1)   P0 + P1              |
         | P2 + P3                 (P0 + P4) - (P2 + P6)|
          -                                            -
 */
void matmult_fast(int n,
                  int Xpitch, const double X[],
                  int Ypitch, const double Y[],
                  int Zpitch, double Z[], int min_mat_recurse) {
  /* min_mat_recurse'e kucuk esik bir
   * matris geldiyse klasik algoritmayi kullan */
  if (n <= min_mat_recurse) {
    matmult(n, Xpitch, X, Ypitch, Y, Zpitch, Z);
    return;
  }

  /* Bu cagridaki alt-matrislerin boylari n/2 olacak */
  const int new_n = n/2;

  const int sz = new_n*new_n*sizeof(double);
  double *P[7];
  /* TODO: 7 adet Px hesabi icin yer ayirin
   * boyutlari sz olacak*/
  int d = 0;
  for (d = 0; d < 7; d++) {
    P[d] = malloc(sz);
    if (P+d == NULL) {
      printf("Malloc error when using matmult_fast...\n");
      break;
      return;
    }
  }

  /* TODO: Toplama ve cikarmalar icin gecici T ve U matrisleri
   * icin yer ayirin, boyutlari sz olacak */
  double *U = malloc(sz);
  double *T = malloc(sz);

  if ((U == NULL) || (T == NULL)) {
   printf("Malloc error when using matmult_fast...\n");
   return;     
  }

  /* TODO: A-B-C-D matrislerinin baslangic adreslerini ayarlayin
   * (Hepsi X matrisinin icerisinde gomulu) */
  const double *A = X;
  const double *B = X + new_n;
  const double *C = X + Xpitch * new_n;
  const double *D = X + new_n + Xpitch * new_n;

  /* TODO: E-F-G-H matrislerinin baslangic adreslerini ayarlayin
   * (Hepsi Y matrisinin icerisinde gomulu) */
  const double *E = Y;
  const double *F = Y + new_n;
  const double *G = Y + Ypitch * new_n;
  const double *H = Y + new_n + Xpitch * new_n;

  /* TODO: P0 = A*(F - H) */
  matsub(new_n, new_n, F, new_n, H, new_n, U); 
  matmult_fast(new_n, new_n, A, new_n, U, new_n, P[0], 2); 
  
  printf("TEST TEST\n");
  matprint(new_n, new_n, A);
  matprint(new_n, new_n, B);
  matprint(new_n, new_n, F);
  matprint(new_n, new_n, H);
  matprint(new_n, new_n, U);
  matprint(new_n, new_n, P[0]);
  printf("END OF THE TEST\n"); 

  /* TODO: P1 = (A + B)*H */
  matadd(new_n, new_n, A, new_n, B, new_n, T); 
  matmult_fast(new_n, new_n, H, new_n, T, new_n, P[1], 2); 

  /* TODO: P2 = (C + D)*E */
  matadd(new_n, new_n, C, new_n, D, new_n, U); 
  matmult_fast(new_n, new_n, E, new_n, U, new_n, P[2], 2); 

  /* TODO: P3 = D*(G - E) */
  matsub(new_n, new_n, G, new_n, E, new_n, T); 
  matmult_fast(new_n, new_n, D, new_n, T, new_n, P[3], 2); 

  /* TODO: P4 = (A + D)*(E + H) */
  matadd(new_n, new_n, A, new_n, D, new_n, U); 
  matadd(new_n, new_n, E, new_n, H, new_n, T); 
  matmult_fast(new_n, new_n, T, new_n, U, new_n, P[4], 2); 

  /* TODO: P5 = (B - D)*(G + H) */
  matsub(new_n, new_n, B, new_n, D, new_n, U); 
  matadd(new_n, new_n, G, new_n, H, new_n, T); 
  matmult_fast(new_n, new_n, T, new_n, U, new_n, P[5], 2); 

  /* TODO: P6 = (A - C)*(E + F) */
  matsub(new_n, new_n, A, new_n, C, new_n, U); 
  matadd(new_n, new_n, E, new_n, F, new_n, T); 
  matmult_fast(new_n, new_n, T, new_n, U, new_n, P[6], 2); 

  /* Sonucun hesaplanmasi */
  /* TODO: Z sol ust = (P3 + P4) + (P5 - P1) */
  matadd(new_n, new_n, P[3], new_n, P[4], new_n, U); 
  matsub(new_n, new_n, P[5], new_n, P[1], new_n, T);
  
  printf("TEST TEST\n");
  matprint(new_n, new_n, U);
  matprint(new_n, new_n, T);
  printf("END OF THE TEST\n"); 
  
  matadd(new_n, new_n, T, new_n, U, new_n, Z);

  printf("TEST TEST\n");
  matprint(new_n, new_n, Z);
  printf("END OF THE TEST\n"); 

  /* TODO: Z sol alt = (P2 + P3) */
  matadd(new_n, new_n, P[2], new_n, P[3], new_n, Z + Zpitch * new_n); 

  /* TODO: Z sag ust = (P0 + P1) */
  matadd(new_n, new_n, P[0], new_n, P[1], new_n, Z + new_n); 

  /* TODO: Z sag alt = (P0 + P4) - (P2 + P6) */
  matadd(new_n, new_n, P[0], new_n, P[4], new_n, U); 
  matadd(new_n, new_n, P[2], new_n, P[6], new_n, T); 
  matsub(new_n, new_n, U, new_n, T, new_n, Z + (Zpitch + 1) * new_n);  

  /* TODO: Gecici pointerlar U ve T'yi free() edin */
  free(U);
  free(T);
  /* TODO: P[] dizisindeki bellek alanlarini free() edin */
  for (d = 0; d < 7; d++) {
    free(P[d]);
    P[d] = NULL;
  }

}
