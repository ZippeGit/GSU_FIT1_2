#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

//(Bknz. TP10 -> sorting.c -> insertion)
void insertion_sort(int* arritem,int size){
  int d, i, cur; 
  for (d = 1; d < size; d++) {
    i = d - 1;
    cur = arritem[d];
    while ((arritem[i] > cur) && (i >= 0)) {
      arritem[i+1] = arritem[i];
      i--;
    }
    arritem[i+1] = cur;
  } 
}

void read_data(char* filename,data* dt){
  // TODO: Alistirma 1

  FILE* readFile = fopen(filename, "r");
  if (readFile == NULL) {
    printf("Error file not found...\n");
    return;
  }

  int ctr = 0;  
  while (!feof(readFile)) {
    fscanf(readFile, "%d , %d\n", &(dt->dataX[ctr]), &(dt->dataY[ctr]));
    ctr++;
  } 

  fclose(readFile);
}
  
void get_information(int* param_list){
  // TODO: Alistirma 2

  insertion_sort(param_list, SIZE);
  int mini = param_list[0];
  int maxi = param_list[SIZE-1];

  int ort = 0;
  for (int i = 0; i < SIZE; i++) {
    ort += param_list[i];
  }
  ort = ort / SIZE;

  printf("Information on the list:\n");
  printf("Number of elements: %d\n", SIZE);
  printf("Mean of the list: %d\n", ort);
  printf("Minimum of the list: %d\n", mini);
  printf("Maximum of the list: %d\n", maxi);
}
 
void sort_values(data* dt){
  //TODO: Alistirma 3

  int d, i, cur, cur2; 
  for (d = 1; d < SIZE; d++) {
    i = d - 1;
    cur = dt->dataX[d];
    cur2 = dt->dataY[d];
    while ((dt->dataX[i] > cur) && (i >= 0)) {
      dt->dataX[i+1] = dt->dataX[i];
      dt->dataY[i+1] = dt->dataX[i];
      i--;
    }
    dt->dataX[i+1] = cur;
    dt->dataY[i+1] = cur2;
  }


}

 
void find_line(data* dt,double* m,double* b){
  //TODO: Alistirma 4
  double sum_X = 0;
  for (int i = 0; i < SIZE; i++) {
    sum_X += dt->dataX[i];
  }

  double sum_X_2 = 0;
  for (int i = 0; i < SIZE; i++) {
    sum_X_2 += dt->dataX[i] * dt->dataX[i];
  }

  double sum_Y = 0;
  for (int i = 0; i < SIZE; i++) {
    sum_Y += dt->dataY[i];
  }

  double sum_Y_2 = 0;
  for (int i = 0; i < SIZE; i++) {
    sum_Y_2 += dt->dataY[i] * dt->dataY[i];
  }

  double sum_X_Y = 0;
  for (int i = 0; i < SIZE; i++) {
    sum_X_Y += dt->dataX[i] * dt->dataY[i];
  }

  double bolen = (SIZE * (sum_X_2)) - (sum_X * sum_X);
  //printf("bolen = %.2lf\n", bolen);
  
  if (bolen == 0) {
    m = 0;
    b = 0;
    return;
  }

  else {
    *m = (SIZE * sum_X_Y - sum_X * sum_Y) / bolen;
    *b = (sum_Y * sum_X_Y - sum_X * sum_X_Y) / bolen; 
  }
}

