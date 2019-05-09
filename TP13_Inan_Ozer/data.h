/*
 * data.h
 *
 *  Created on: May 8, 2019
 *      Author: Merve Unlu
 */

#ifndef DATA_H_
#define DATA_H_

typedef struct Data {
  int* dataX;
  int* dataY
} data; 

void insertion_sort(int* arritem,int size);
void read_data(char* filename,data* dt);
void get_information(int* param_list);
void sort_values(data* dt);
void find_line(data* dt,double* m,double* b);  

#endif /* DATA_H_ */
