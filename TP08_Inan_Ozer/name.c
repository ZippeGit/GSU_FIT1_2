/*
 * name.c
 *
 *  Created on: Mar 28, 2019
 *      Author: Merve Unlu
 */


#include "name.h"
#include<string.h>

/*
 * Parametre olarak verilen
 * veri yapisina bagli dizideki
 * elemanlari ekrana basar.
 */
// TODO: ex1
void print_db(struct dbName d){
	int ind;
	for(ind=0;ind<d.currentSize;ind++){
        printf("%s ,%d \n",d.db[ind].name,d.db[ind].value);
	}
	// Karmasikligi O(n). Cunku fonksiyon d.currentSize kadar donecek.
	// Her dongude 1 adet printf var. Yani n * 1 = n. Bu da n'e esit.
}

/*
 * Parametre olarak verilen dosyayi acar,
 * ve icindeki sirali elemanlari veri yapisina
 * bagli dizide saklar.
 */
void read_name_file(struct dbName* d,char* filename){
    FILE * fp=fopen(filename,"r");
    if(fp){
    	// Dosya hatasiz aciliyorsa
    	char line[MAXSIZE];
    	// Her bir satiri oku
    	while(fgets(line,MAXSIZE,fp)!=NULL){
    	  //Okunan isim degerini diziye ekler.
          strcpy(d->db[d->currentSize].name,line);
          // Dizi indeksini arttirir.
          printf("%s \n",d->db[d->currentSize].name);
          d->currentSize = d->currentSize + 1;
    	}
    }
    fclose(fp);
	// Karmasikligi O(n). while dongusunun n kadar dondugunu varsayalim.
	// Icinde 3 islem var, 3n. if'in icinde 1 islem daha var. if'ten once
	// ve sonra bir islem daha var. 3n+3 olur. Bunu n olarak gosteririz.
}


/*
 * Deger dosyasini acip, icindeki sayilari
 * dizideki sirasi ile dizi elemanlarini gunceller.
 */
void read_value_file(struct dbName* d,char* filename){
   // TODO: ex2
    //filename dosyasini satir
    // satir okuyup her satirin denk geldigi
    // degeri d->db[satir].value degiskenine
	// atayin.
	// Dosya okuma icin: fgets
	// Tip donusumleri icin : atoi
	int i = 0;

	FILE *fo = fopen(filename, "r");

	if (fo) {
		char line[5];

		while((fgets(line,5,fo) != NULL)) {
			d->db[i].value = atoi(line);
			i++;
		}
	}
}

/*
 * Dogrusal arama islemini yapar.
 * Verilen veri yapisina bagli dizide,
 * istenen isimi arar. Isim bulundugunda
 * dizideki yerini, isim yoksa -1 dondurur.
 */
int search_uniform(struct dbName d, char* name){
    // TODO: ex3
	// Dogrusal arama fonksiyonu
	// name ve d->db[i].name karsilastirmasi icin:
	// int result = strncmp(d.db[i].name,name,strlen(name))
	int i = 0;

	for (i = 0; i < d.currentSize; i++) {
		if (!strncmp(d.db[i].name,name,strlen(name))) {
			return i;
		}
	}

	return -1;
}


/*
 * Ikili arama islemi yapar.
 * Verilen veri yapisina bagli dizide,
 * istenen ismi ikili(binary) olarak
 * arar. Isim bulundugunda dizideki yerini,
 * isim yoksa -1 dondurur.
 */
int search_binary(struct dbName d,char* name){
	// TODO: ex5
    // İkili - Binary arama fonksiyonu
	// Hint: strcmp fonksiyonunun dondurdugu degere gore alfabetik
	// sira kontrolu yapilabilir.
	// int result = strncmp(d.db[i].name,name,strlen(name))
    //     if result = 0 , ayni
	//     if result > 0 ilk karakter daha buyuk degere sahip
	//     if result < 0 ilk karakter daha kucuk degere sahip
	int first = 0; 
	int last = d.currentSize - 1;
	int mid;
	int res; 

	while (first <= last) {
		mid = (first + last) / 2;
		res = strncmp(d.db[mid].name,name,strlen(name));

		if (!res) {
			return mid;
		}

		else if (res > 0) {
			last = mid;
		}

		else {
			first = mid;
		}
	}

	return -1;
}

/*
 * Verilen dizide elemanlarin deger degiskenlerine bakarak diziyi
 * boler. Deger degiskeni 1 ise Good, deger degiskeni 0 ise Bad
 * olarak atanir.
 */
void split_names(struct dbName* dAll,struct dbName* dGood,struct dbName* dBad){
   int ind;
   for(ind=0;ind<dAll->currentSize;ind++){
	   if(dAll->db[ind].value == 1){
		   strcpy(dGood->db[dGood->currentSize].name,dAll->db[ind].name);
		   dGood->db[dGood->currentSize].value = dAll->db[ind].value;
		   dGood->currentSize++;
	   }else{
		   strcpy(dBad->db[dBad->currentSize].name,dAll->db[ind].name);
		   dBad->db[dBad->currentSize].value = dAll->db[ind].value;
		   dBad->currentSize++;
	   }
   }
}

/*
 * Verilen iki veri yapisinda ismi oncelikle ilk
 * veri yapisi dizisinde, sonra da ikinci veri yapisi
 * dizisinde arar. Isim bulunamadiginda -1, bulundugunda
 * yerini geri gonderir.
 */
int search_good_bad(struct dbName dGood, struct dbName dBad,char* name){
    int result = -1;
    // TODO: ex7
    // Once dGood icerisinde, sonra dBad icerisinde arayiniz.
	result = search_binary(dGood, name);

	if (result == -1) {
		result = search_binary(dBad, name);
	}

    return result;
}


