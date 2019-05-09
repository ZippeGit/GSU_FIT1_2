#include"data.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv){
  // TODO AListirma 5

  data mainData;
  int X[100];
  int Y[100];
  mainData.dataX=X;
  mainData.dataY=Y;

  read_data(argv[1], &mainData);
  
  get_information(mainData.dataX);
  get_information(mainData.dataY);

  sort_values(&mainData);

  FILE* sortedData = fopen("sorted_data", "w");
  
  for (int i = 0; i < 100; i++) {
    fprintf(sortedData, "%d , %d\n", mainData.dataX[i], mainData.dataY[i]);
  }
  fclose(sortedData);

  double* a; 
  double* b;
  find_line(&mainData, a, b);
  printf("Parameters:\n\t%d\n\t%d", a, b);

  return 0;
}
