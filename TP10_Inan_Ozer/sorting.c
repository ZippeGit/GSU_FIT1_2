/*
 * sorting.c
 *
 *  Created on: Apr 18, 2019
 *      Author: Merve Unlu
 */


#include"sorting.h"

/* En hizli yontem insertion sort. 
 * Ozellikle dizinin uzunlugu arttikca bu fark belli oluyor:
 * SIZE = 20000 icin 5 olcum ortalamasi:
 * Insertion: 0.48s (Eskisi 1.42s)
 * Selection: 0.62s
 * Bubble: 2.98s
 * 
 * Bubble elemanlari her seferinde sadece 1 ileri/geri
 * atiyor. Bu yuzden cok dongu donmesi gerekiyor.
 * 
 * Selectionda ise elemanlar sirali olsa bile kontrol
 * etmek icin donguye giriyor, bosa zaman kaybediyor.
 * 
 * */

/*
 * Parametre olarak verilen dizi elemanlarini
 * insertion sort kullanarak siralar.
 * Sirali dizi olarak donus yapar.
 */
void insertion_sort(int* arritem,int size){
	//TODO 
    int d, i, cur;
 
    for (d = 1; d < size; d++) {
        //Yeni
        i = d - 1;
        cur = arritem[d];

        while ((arritem[i] > cur) && (i >= 0)) {
            arritem[i+1] = arritem[i];
            i--;
        }
        arritem[i+1] = cur;
        
        //Eski
        /*
        if (arritem[d] > arritem[d+1]) {
            for (i = d+1; i > 0; i--) {
                if (arritem[i] < arritem[i-1]) {
                    swap_function(&arritem[i], &arritem[i-1]);
                }
            }
        } 
        */ 
    } 
}


/*
 * Parametre olarak verilen diziyi
 * selection_sort kullanarak siralar.
 * Sirali dizi olarak donus yapar.
 */
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

/*
 * Parametre olarak verilen diziyi
 * kabarcik siralamasi (bubble sort)
 * kullarak siralar.
 * Sirali dizi olarak donus yapar.
 */
void bubble_sort(int* arritem,int size){
    //TODO
    int d, swap = 1;
    int temp;
    while(swap) {
        swap = 0;
        for (d = 0; d < size - 1; d++) {
            if (arritem[d] > arritem[d+1]) {
                swap_function(&arritem[d], &arritem[d+1]);
                swap = 1;
            }
        }
    }
}

void swap_function(int *var1, int *var2) {
    int temp;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}