#include"data.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

int main(int argc, char const *argv[]){
  // TODO AListirma 5

  data mainData;
  int tmpX[SIZE];
  int tmpY[SIZE];
  mainData.dataX=tmpX;
  mainData.dataY=tmpY;

  read_data(argv[1], &mainData);

  get_information(mainData.dataX);
  printf("-----------------\n");
  get_information(mainData.dataY);
  printf("-----------------\n");

  sort_values(&mainData);

  FILE* sortedData = fopen("sorted_data.txt", "w");
  
  for (int i = 0; i < SIZE; i++) {
    fprintf(sortedData, "%d , %d\n", mainData.dataX[i], mainData.dataY[i]);
  }
  fclose(sortedData);

  double a; 
  double b;
  find_line(&mainData, &a, &b);
  printf("Parameters:\n\tm = %.2lf\n\tb = %.2lf\n", a, b);

  return 0;
}
