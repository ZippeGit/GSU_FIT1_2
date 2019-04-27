/*************************************
 * Selection Sort
 ************************************/

void swap_function(int *var1, int *var2) {
    int temp;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void selection_sort(int *arritem,int size){
    //TODO
    int d, i, mini, cursor;
    for (d = 0; d < size; d++) {
        mini = arritem[d];
        cursor = d;
        for (i = d; i < size; i++) {
            if (arritem[i] < mini) {
                mini = arritem[i];
                cursor = i;
            }
        }
        swap_function(&arritem[d] , &arritem[cursor]);
    }
}