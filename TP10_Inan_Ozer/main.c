/*
 * main.c
 *
 *  Created on: Apr 18, 2019
 *      Author: Merve Unlu
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include"sorting.h"
#define SIZE1 20
#define SIZE2 20000

/*
 * Rastgele dizi elemanlari uretir.
 * Dizi boyutu parametre olarak verilir.
 * Sayilar 0-100 arasindadir.
 */
void random_array(int* arrRand,int size){
   int i=0;
   srand(time(NULL));
   for(i=0;i<size;i++){
	   arrRand[i] =  rand()%100;
   }
}

int main(int argc,char* argv[]){

	int arrEx[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	int arrEx1[] = {0,1,2,3,4,5,6,7,8,9,10,12,15,19,23,34,43,55,58,88};
	int i;

	int* arrRand = malloc(sizeof(int)*SIZE1);
	random_array(arrRand, 20);

	/*
	 * Siralama algoritmaları için test
	 */

	printf("--------------------------\n");
	printf("Insertion sort example:\n");
	for(i = 0; i<SIZE1; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	insertion_sort(arrRand,SIZE1);
	for(i = 0; i < SIZE1; i++) {
		if (i == SIZE1 - 1) {
			printf("%d\n", arrRand[i]);
		}
		else {
			printf("%d - ", arrRand[i]);
		}
	}
	//assert(is_array_sorted(arrRand,SIZE1));

	//Farkli bir arrRand isteniyorsa yorumu kaldirin:
	//sleep(1);
	random_array(arrRand,SIZE1);
	printf("--------------------------\n");
	printf("Selection sort example:\n");
	for(i = 0; i < SIZE1; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	selection_sort(arrRand,SIZE1);
	for(i = 0; i < SIZE1; i++) {
		if (i == SIZE1 - 1) {
			printf("%d\n", arrRand[i]);
		}
		else {
			printf("%d - ", arrRand[i]);
		}
	}
	//assert(is_array_sorted(arrRand,SIZE1));

	//Farkli bir arrRand isteniyorsa yorumu kaldirin:
	//sleep(1);
	random_array(arrRand,SIZE1);
	printf("--------------------------\n");
	printf("Bubble sort example:\n");
	for(i = 0; i < SIZE1; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	bubble_sort(arrRand,SIZE1);
	for(i = 0; i < SIZE1; i++) {
		if (i == SIZE1 - 1) {
			printf("%d\n", arrRand[i]);
		}
		else {
			printf("%d - ", arrRand[i]);
		}
	}
	printf("--------------------------\n");
	//assert(is_array_sorted(arrEx1,SIZE1));


	// TODO: Algoritmalar ayni dizi verildiginde
	// nasil bir performans sergiliyor?
	// Hangisi daha hizli, clock kullanarak gosteriniz.
	// Yorumunuzu sorting.c icine ekleyiniz.

	printf("Speed test for SIZE2 = %d:\n", SIZE2);

	clock_t time; double time_sort;

	random_array(arrRand,SIZE2);
	time = clock();
	insertion_sort(arrRand,SIZE2);
	time = clock() - time;
	time_sort = (double)time/CLOCKS_PER_SEC;
	printf("Insertion sort finished in: %lf seconds\n", time_sort);

	random_array(arrRand,SIZE2);
	time = clock();
	selection_sort(arrRand,SIZE2);
	time = clock() - time;
	time_sort = (double)time/CLOCKS_PER_SEC;
	printf("Selection sort finished in: %lf seconds\n", time_sort);

	random_array(arrRand,SIZE2);
	time = clock();
	bubble_sort(arrRand,SIZE2);
	time = clock() - time;
	time_sort = (double)time/CLOCKS_PER_SEC;
	printf("Bubble sort finished in: %lf seconds\n", time_sort);
	
	printf("--------------------------\n");

	// Sirali dizi ile maksimum testi
	//assert(find_maxsum_elements_sorted(arrEx1,SIZE1)==146);
	for(i = 0; i < SIZE1; i++) {
		if (i == SIZE1 - 1) {
			printf("%d\n", arrEx1[i]);
		}
		else {
			printf("%d - ", arrEx1[i]);
		}
	}
	printf("Sorted search for max x+y : %d\n", find_maxsum_elements_sorted(arrEx1, SIZE1));
	printf("--------------------------\n");
	
	// Sirasiz dizi ile maksimum testi
	//assert(find_maxsum_elements_unsorted(arrEx,SIZE1)==146);
	random_array(arrRand,SIZE1);
	for(i = 0; i < SIZE1; i++) {
		if (i == SIZE1 - 1) {
			printf("%d\n", arrRand[i]);
		}
		else {
			printf("%d - ", arrRand[i]);
		}
	}
	printf("Unsorted search for max x+y : %d\n", find_maxsum_elements_unsorted(arrRand, SIZE1));
	printf("--------------------------\n");
	
	// Mod elemani bulan fonksiyon testi
	int arrMode[] = {3,4,6,1,3,4,3,1,3,6};
	for(i = 0; i < 10; i++) {
		if (i == 9) {
			printf("%d\n", arrMode[i]);
		}
		else {
			printf("%d - ", arrMode[i]);
		}
	}
	printf("Mode of the list: %d\n", find_mode_element(arrMode, 10));
	//assert(find_mode_element(arrMode,10)==3);
	printf("--------------------------\n");
	
	// minimum 5 eleman testi
	int arrRes[] = {0,0,0,0,0};
	int arrEx5[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	for(i = 0; i < 20; i++) {
		if (i == 19) {
			printf("%d\n", arrEx5[i]);
		}
		else {
			printf("%d - ", arrEx5[i]);
		}
	}
	minimum_k_elements(arrEx5,SIZE1,5,arrRes);
	printf("Minimum 5 elements of this array: ");
	for(i = 0; i < 5; i++) {
		//assert(arrRes[i]==arrEx5[SIZE1-1-i]);
		if (i == 4) {
			printf("%d\n", arrRes[i]);
		}
		else {
			printf("%d - ", arrRes[i]);
		}
	}
	printf("--------------------------\n");

	//remove_duplications testi
	int arrDup[] = {3,4,6,1,3,2,3,1,3,6};
	int* dest = malloc(10*sizeof(int));
	for(i = 0; i < 10; i++) {
		if (i == 9) {
			printf("%d\n", arrDup[i]);
		}
		else {
			printf("%d - ", arrDup[i]);
		}
	}
	remove_duplications(arrDup,10,dest);
	printf("Without duplications: ");
	for(i = 0; i < 5; i++) {
		if (i == 4) {
			printf("%d\n", dest[i]);
		}
		else {
			printf("%d - ", dest[i]);
		}
	}
/*	for(i=1;i<=5;i++){
		assert(dest[i-1]!=dest[i]);
	}
*/
	return 0;
}
