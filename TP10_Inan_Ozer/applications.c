/*
 * applications.c
 *
 *  Created on: Apr 18, 2019
 *      Author: Merve Unlu
 */
#include "sorting.h"

/*Parametre olarak verilen dizinin sirali
 * olmadigini kontrol eder.
 * Dizi sirali ise 1, degilse 0 doner.
 */
int is_array_sorted(int* arritem,int size){
    int i=0;
	while(arritem[i]<=arritem[i+1] && i<size)
		i++;
	return (i==size-1);
}

/*
 * Sirali verilen bir dizide max(x+y) degerini
 * karsilayan ikilinin toplamini bulur.
 * Ornek: dizi = {4,5,8,2,10}
 *        sonuce = 18
 */
int find_maxsum_elements_sorted(int* arritem,int size){
    int maxsum;
    // TODO
	maxsum = arritem[size-1] + arritem[size-2];
	return maxsum;
}

/*
 * Sirasiz verilen bir dizide max(x+y) degerini
 * karsilayan ikilinin toplamini bulur.
 * Ornek: dizi = {2,4,5,8,10}
 *        sonuce = 18
 */
int find_maxsum_elements_unsorted(int* arritem,int size){
    int maxsum;
    // TODO
	// Sorting kullanarak:
	/*
	insertion_sort(arritem, size);
	maxsum = arritem[size-1] + arritem[size-2];
	*/

	//Sorting kullanmadan:	
	int d;
	int max1 = arritem[0];
	int max2 = arritem[1];
	for (d = 0; d < size; d += 2) {
	}
	maxsum = max1 + max2;
	return maxsum;
}

/*
 * Parametre olarak verilen dizide en cok
 * bulunan elemani(mode) geri dondurur.
 * Ornek: dizi = {2,3,6,1,3,1,4,3}
 *        sonuc = 3
 */
int find_mode_element(int* arritem,int size){
	int mode;
	// TODO
	int d, max_count = 0, count = 0;

	insertion_sort(arritem, size);
	for (d = 0; d < size; d++) {
		if (arritem[d] == arritem[d+1]) {
			count++;
		}
		else {
			if (max_count < count) {
				max_count = count;
				mode = arritem[d];
			}
			count = 0;
		}
	}
	return mode;
}

/*
 * Parametre olarak verilen dizide elemanlardan
 * minimum k tanesini gonderir.
 * arritem: parametre olarak verilen dizi
 *   size : dizi boyutu
 *     k  : en kucuk kac eleman
 *  arrRes: en kucuk k elemani tasiyan dizi
 * Ornek: dizi={2,1,6,9,4,7}
 *        en kucuk 3 eleman: {1,2,4}
 */
void minimum_k_elements(int* arritem,int size,int k,int arrRes[k]){
	// TODO
	//Sorting kullanarak: (ama calismiyor neden bilmiyorum)
/*
	int d;
	insertion_sort(arritem, size);
	for (d = 0; d < k; d++) {
		arrRes[d] = arritem[d];
	}
*/
	//Sorting kullanmadan:
	
}

/*
 * Parametre olarak verilen bir diziden yeni bir dizi
 * olusturur. Yeni dizi tekrar eden sayilari icermez.
 * Diger sayilar da sirali olarak dizilir.
 * arritem : ayni elemanlari iceren dizi
 *    size : dizinin eleman sayisi
 *    dest : sonucta olusan dizi
 * Ornek: dizi = {2,3,5,1,7,2,3,5}
 *        sonuc= {1,2,3,5,7}
 */
void remove_duplications(int* arritem,int size,int* dest){
	//TODO
	int d = 0, i = 0;
	insertion_sort(arritem, size);
	while (d < size) {
		dest[i] = arritem[d];
		while (arritem[d] == arritem[d+1]) {
			d++;
		}
		i++;
	}	
}

