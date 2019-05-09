/*
 * heap.c
 *
 *  Created on: May 2, 2019
 *      Author: Merve Unlu
 */
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"heap.h"


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

/*
 * Parametre olarak verilen
 * yigini ekrana basar.
 * size: boyutu
 */
void print_heap(int* array,int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d ",array[i]);
	printf("\n");
}


/*
 * Parametre olarak verilen yiginin
 * maksimum yigin ozelligi tasimasini saglar.
 * size   : yigin boyutu
 * indeks : ozelligi bozan degerin indeksi
 */
void max_heapify_recursive(int *array,int indeks,int size){
  // TODO
  int leftC = 2 * indeks + 1;
  int rightC = 2 * indeks + 2;
  int max = indeks;
  int tmp;

  if (leftC < size && array[leftC] > array[indeks]) {
    max = leftC;
  }

  if (rightC < size && array[rightC] > array[max]) {
    max = rightC;
  }

  if (max != indeks) {
    tmp = array[max];
    array[max] = array[indeks];
    array[indeks] = tmp;
    max_heapify_recursive(array, max, size);
  }

}


/*
 * Verilen bir diziden maksimum yigin
 * ozelliginde bir dizi olusturur.
 * size : dizinin boyutu
 */
void build_max_heap(int *array,int size){
	// TODO
  for (int d = (size / 2) - 1; d >= 0; d--) {
    max_heapify_recursive(array, d, size);
  }
}

/*
 * Verilen sirasiz bir diziyi
 * yigin siralama kullanarak siralar.
 */
void heap_sort(int *array,int size){
  build_max_heap(array, size);

  int tmp;

  for (int d = size - 1; d >= 0; d--) {
    tmp = array[0];
    array[0] = array[d];
    array[d] = tmp;
    max_heapify_recursive(array, 0, d);
  }
}
