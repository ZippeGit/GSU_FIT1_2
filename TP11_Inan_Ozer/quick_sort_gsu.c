#include <stdlib.h>
#include <stdio.h>

void swapper(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *array, int low, int high) {
    // TODO
    int pivot = high;
    int new_pivot = low;
    int d;
    for (d = low; d < high; d++) {
        if (array[d] < array[pivot]) {
            swapper(&array[d], &array[new_pivot]);
            new_pivot++;
        }
    }
    swapper(&array[new_pivot], &array[pivot]);
    return new_pivot;
}


/*
void quick_sort_gsu(int *array, int size) {
    // TODO
    //Ne kadar denediysem de olmadi, 2 parametre ile yapamadim
    //3 parametreli versiyonu asagida.
    int p;
    int low = 0;
    int high = size - 1;
    if (low < high) {
        p = partition(array, low, high);
        quick_sort_gsu(array, p);
        quick_sort_gsu(array, size - p);
    }
}
*/

void quick_sort_unwrapper(int *array, int low, int high) {
    // TODO
    int p;
    if (low < high) {
        p = partition(array, low, high);
        quick_sort_unwrapper(array, low, p-1);
        quick_sort_unwrapper(array, p+1, high);
    }
}

void quick_sort_gsu(int *array, int size) {
    quick_sort_unwrapper(array, 0, size-1);
}


