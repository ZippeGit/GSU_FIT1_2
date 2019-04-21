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
#define SIZE 20

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

	int* arrRand = malloc(sizeof(int)*SIZE);
	random_array(arrRand, 20);

	/*
	 * Siralama algoritmaları için test
	 */
/*
	printf("-------------\n");
	for(i = 0; i<SIZE; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	insertion_sort(arrRand,SIZE);
	for(i = 0; i<SIZE; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	//assert(is_array_sorted(arrRand,SIZE));

	random_array(arrRand,SIZE);
	printf("--------------\n");
	for(i = 0; i<SIZE; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	selection_sort(arrRand,SIZE);
	for(i = 0; i<SIZE; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	//assert(is_array_sorted(arrRand,SIZE));

	random_array(arrRand,SIZE);
	printf("--------------\n");
	for(i = 0; i<SIZE; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	bubble_sort(arrRand,SIZE);
	for(i = 0; i<SIZE; i++) {
		printf("%d - ", arrRand[i]);
	}
	printf("\n");
	//assert(is_array_sorted(arrEx1,SIZE));
*/

	// TODO: Algoritmalar ayni dizi verildiginde
	// nasil bir performans sergiliyor?
	// Hangisi daha hizli, clock kullanarak gosteriniz.
	// Yorumunuzu sorting.c icine ekleyiniz.
/*
	clock_t time; double time_sort;

	random_array(arrRand,SIZE);
	time = clock();
	insertion_sort(arrRand,SIZE);
	time = clock() - time;
	time_sort = (double)time/CLOCKS_PER_SEC;
	printf("Insertion sort finished in: %lf seconds\n", time_sort);

	random_array(arrRand,SIZE);
	time = clock();
	selection_sort(arrRand,SIZE);
	time = clock() - time;
	time_sort = (double)time/CLOCKS_PER_SEC;
	printf("Selection sort finished in: %lf seconds\n", time_sort);

	random_array(arrRand,SIZE);
	time = clock();
	bubble_sort(arrRand,SIZE);
	time = clock() - time;
	time_sort = (double)time/CLOCKS_PER_SEC;
	printf("Bubble sort finished in: %lf seconds\n", time_sort);
*/

	// Sirali dizi ile maksimum testi
	//assert(find_maxsum_elements_sorted(arrEx1,SIZE)==146);
	printf("Sorted search for max x+y : %d\n", find_maxsum_elements_sorted(arrEx1, SIZE));
	// Sirasiz dizi ile maksimum testi
	//assert(find_maxsum_elements_unsorted(arrEx,SIZE)==146);
	printf("Unsorted search for max x+y : %d\n", find_maxsum_elements_unsorted(arrEx, SIZE));

	// Mod elemani bulan fonksiyon testi
	int arrMode[] = {3,4,6,1,3,4,3,1,3,6};
	printf("Mode of the list: %d\n", find_mode_element(arrMode, 10));
	//assert(find_mode_element(arrMode,10)==3);

	// minimum 5 eleman testi
	int arrRes[] = {0,0,0,0,0};
	int arrEx5[] = {3,4,6,1,8,12,58,0,2,55,88,9,23,5,34,15,19,7,43,10};
	minimum_k_elements(arrEx5,SIZE,5,arrRes);
	for(i=0;i<5;i++){
		//assert(arrRes[i]==arrEx5[SIZE-1-i]);
		printf("%d - ", arrRes[i]);
	}
	printf("\n");
/*	//remove_duplications testi
	int arrDup[] = {3,4,6,1,3,2,3,1,3,6};
	int* dest = malloc(10*sizeof(int));
	remove_duplications(arrDup,10,dest);
	for(i=0;i<5;i++){
		printf("%d - ", dest[i]);
	}
	printf("\n");
*/

	return 0;
}
