/*
 * stack.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Merve Unlu
 */


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*
 * Parametre olarak verilen yigit
 * elemanini bellekten siler.
 * yigit zaten bos ise herhangi bir islem
 * yapmaz.
 */
void stack_free(struct stackNode **top) {
    struct stackNode *ttop = *top;
    // Her bir eleman NULL
    // olmadigi surece silme islemi yapar.
    while (ttop != NULL) {
        struct stackNode *orphan = ttop;
        ttop = ttop->next;
        free(orphan);
    }
    *top = NULL;
}

/*
 * Parametre olarak verilen yigit yapisinin
 * bos olup olmadini kontrol eder.
 * yigit bos ise 1, degilse 0 dondurur.
 */
int is_empty(struct stackNode *top){
    int result = 0;
    /*Alistirma 1.a*/
    if (top == NULL) result = 1;
    else result = 0;
    return result;
}


/*
 * Parametre olarak verilen yigit yapisinda
 * yeni veri data yapisini ekler.
 * (LIFO prensibi ile)
 */
void stack_push(struct stackNode **top, double data) {

	/* Alistirma  1.b */
	/* Yeni dugum icin gosterici olusturun
     * ve bellekte yer acin
     * Bellek icin kontrol yaptiktan sonra
     * yeni veri atamasini yapin
     * Bu atamadan sonra yigittaki
     * ilk deger guncelleyin.
    */

    struct stackNode *newNode = malloc(sizeof(struct stackNode));
    if (newNode == NULL) {
        printf("Malloc error... (New node)\n");
        exit(0);
    }

    newNode->data = data;

    if (is_empty(*top)) {
        newNode->next = NULL;
    }
    else {
        newNode->next = *top;
    }

    *top = newNode;
}


/*
 * Parametre olarak verilen yigit yapisindan
 * ilk elemani siler.
 * Eger yigit bos ise -1 degerini gonderir.
 */
double stack_pop(struct stackNode **top) {

	double retval = -1;
	/* yigiti kontrol et, bos ise -1 dondur. */
	/* Alistirma 1.c */
    /* Bos degilse ilk elemani al,
     * sonraki elemani ilk eleman olarak ata,
     * ilk eleman icin ayrilan bellegi sil.
     * ilk eleman verisini dondur.
     */

    struct stackNode *temp = *top;

    if (!is_empty(*top)) {
        retval = (*top)->data;
        *top = temp->next;
        free(temp);
    }

   // else printf("This stack is empty. YEET! \n");

    return retval;
}


/*
 * Alistirma 1.d 
 * stack_multi_pop fonksiyonunu tanimlayiniz.
 */ 
void stack_multi_pop(struct stackNode **top, int number) {
    /*
    struct stackNode *cur = malloc(sizeof(struct stackNode));
    if (cur == NULL) {
        printf("Malloc error... (Multi Pop) \n");
        exit(0);
    }
    cur = *top;

    int d = 0, i = 0;
    while(cur != NULL) {
        d++;
        cur = cur->next;
    }
    if (number > d) {
        number = d;
    }
    */
    int i = 0;
    for (i = 0; i < number; i++) {
        printf("%.0lf ", stack_pop(top));
    }
    printf("\n");
}

/*
 * Parametre olarak verilen yigit yapisini
 * ekrana basar.
 * yigit bos ise "yigit bos" mesajini gosterir.
 */
void stack_print(struct stackNode *top) {
    /* Alistirma 1.e */
	/* yigit bos mu kontrol edin
     * Bos ise ekrana mesaj basip fonksiyondan cikmali
     */
    
    if(is_empty(top)) {
        printf("This stack is empty. YEET!\n");
        exit(0);
    } 

	/* 
	 * yigit bos degilse ilk elemandan baslayarak
	 * son elemana kadar hepsini ekrana yazsin.
	 */
	//Hint: yigit yapisi bagli liste olarak tanimlandigindan
	// ekrana basma islemi de bagli listeler ile benzer olacak.

    printf("Here is your list: ");
    for(; top != NULL; top = top->next) {
        printf("%.0lf ", top->data);
    }
    printf("\n");
}


