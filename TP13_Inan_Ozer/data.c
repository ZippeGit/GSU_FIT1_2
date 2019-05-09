#include "data.h"
#include <stdio.h>
#include <stdlib.h>

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

  int ctr = 0;
  printf("testtt\n");
  while (!feof(readFile)) {
    printf("test\n");
    fscanf(readFile, "%d , %d\n", &(dt->dataX[ctr]), &(dt->dataY[ctr]));
    ctr++;
  }

  printf("test\n");
  fclose(readFile);
}
  
void get_information(int* param_list){
  // TODO: Alistirma 2
  
  int listSize = sizeof(param_list) / sizeof(int);

  insertion_sort(param_list, listSize);
  int mini = param_list[0];
  int maxi = param_list[listSize-1];

  int ort = 0;
  for (int i = 0; i < listSize; i++) {
    ort += param_list[i];
  }
  ort = ort / listSize;

  printf("Information on the list:\n");
  printf("Number of elements: %d\n", listSize);
  printf("Mean of the list: %d\n", ort);
  printf("Minimum of the list: %d\n", mini);
  printf("Maximum of the list: %d\n", maxi);
}
 
void sort_values(data* dt){
  //TODO: Alistirma 3

  int size = sizeof(dt->dataX);

  int d, i, cur, cur2; 
  for (d = 1; d < size; d++) {
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
  int listSize = sizeof(dt->dataX);

  int sum_X = 0;
  for (int i = 0; i < listSize; i++) {
    sum_X += dt->dataX[i];
  }

  int sum_X_2 = 0;
  for (int i = 0; i < listSize; i++) {
    sum_X_2 += dt->dataX[i] * dt->dataX[i];
  }

  int sum_Y = 0;
  for (int i = 0; i < listSize; i++) {
    sum_Y += dt->dataY[i];
  }

  int sum_Y_2 = 0;
  for (int i = 0; i < listSize; i++) {
    sum_Y_2 += dt->dataY[i] * dt->dataY[i];
  }

  int sum_X_Y = 0;
  for (int i = 0; i < listSize; i++) {
    sum_X_Y += dt->dataX[i] * dt->dataY[i];
  }

  double bolen = (listSize * (sum_X_2)) - (sum_X * sum_X);
  if (bolen == 0) {
    m = 0;
    b = 0;
    return;
  }

  else {
    *m = (listSize * sum_X_Y - sum_X * sum_Y) / bolen;
    *b = (sum_Y * sum_X_Y - sum_X * sum_X_Y) / bolen; 
  }
}

