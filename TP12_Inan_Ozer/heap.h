/*
 * heap.h
 *
 *  Created on: May 2, 2019
 *      Author: Merve Unlu
 */

#ifndef HEAP_H_
#define HEAP_H_

void print_heap(int* array,int size);
void max_heapify_recursive(int *array,int indeks,int size);
void build_max_heap(int *array,int size);
void heap_sort_wrapper(int *array, int size);

#endif /* HEAP_H_ */
