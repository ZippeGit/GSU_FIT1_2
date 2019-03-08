/*
 * linkedlist.c
 *
 *  Created on: Mar 7, 2019
 *      Author: Merve Unlu
 */
#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>

/* 10, 20, 30 elemanlarindan olusan basit bir liste
 * olusturan fonksiyon. */
// TODO: Alistirma 1
struct node* create_sample_list(void) {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    if ((head == 0) || (second == 0) || (third == 0)) {
        printf("Malloc error...\n");
    }

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    return head;
}

/* Bagli listenin elemanlarini ekrana yazdiran fonksiyon. */
void Print(struct node* head) {
    struct node* cur = head;
    for (; cur != NULL; cur = cur->next) {
        printf("%d -> ", cur->data);
    }
    puts("NULL");
}

/* Bir listenin belli bir icerige sahip olup olmadigini
 * dogrulayan test fonksiyonu. */
int verifyList(struct node* head, int *values) {
    struct node* cur = head;
    int d = 0;
    for (; cur != NULL; cur = cur->next) {
        if (cur->data != values[d]) {
            return 0;
        }
        d++;
    }
    return 1;
}

/* Parametre olarak verilen
 * head'in gosterdigi listede kac dugum oldugunu
 * hesaplayip geriye dondurun. */
int Length(struct node* head) {
    // TODO Alistirma 4
    struct node* cur = head;
    int d = 0;
    for (; cur != NULL; cur = cur->next) {
        d++;
    }
    return d;
}
/* Listenin herhangi bir yerine dugum ekleyen asagidaki
 * fonksiyonu doldurun.
 * position == 0 ise listenin basina,
 * position == -1 ise listenin sonuna,
 * position baska bir deger ise araya ekleme yapacaksiniz.
 * Ornegin liste
 *      5, 10, 15
 * dugumlerinden olussun.
 *
 * position == 0  ise yeni liste: 20, 5, 10, 15
 * position == -1 ise yeni liste: 5, 10, 15, 20
 * position == 1  ise yeni liste: 5, 20, 10, 15
 * position == 2 ise yeni liste: 5, 10, 20, 15
 * 
 * olmalidir.
 */
void Insert(struct node** head, int new_value, int position) {
    // TODO Alistirma 5
    /* En one ekleme: position == 0
     * En sona ekleme: position == -1
     * Diger degerler, aralara ekleme.
     * (Position listenin uzunlugundan fazlaysa dogal olarak
     * en sona eklemis olacaksiniz) */
    int d = 0;
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) printf("Malloc error...\n");
    new->data = new_value;
    struct node *cur = *head;
    for (; cur != NULL; cur = cur->next) {
        d++;
    }
    if (position > d) position = d;

    switch (position) {
        case 0:
            new->next = *head;
            *head = new;
            break;

        case -1:
            for (; cur != NULL; cur = cur->next) {
                if (cur->next == NULL) {
                    cur->next = new;
                    new->next = NULL;
                }
            }
            break;

        default:
            cur = *head;
            for (d=0; d<position; d++) {
                cur = cur->next;
            }
            new->next = cur;
            cur = *head;
            for (d=0; d<position-1; d++) {
                cur = cur->next;
            }
            cur->next = new;
            break;
    }
}

/* head'in gosterdigi listenin butun dugumlerini
 * free() ile temizleyin. */
void Free(struct node* head) {
   // TODO Alistirma 6
    int d = 0;
    struct node* cur = head;
    int length = Length(head);
    for (; cur != NULL; cur = cur->next) {
        free(cur);
        d++;
    }
    if (d == length) printf("The memory is free now! Vive la liberte!\n");
}
/* position ile verilen pozisyondaki elemani *result
 * pointeriyla verilen yere yazin.
 * Eger olmayan bir pozisyon istendiyse fonksiyon 1 dondurmeli, liste sinirlari
 * dahilinde kalindi ve basarili olunduysa 0 dondurmelidir. */
int GetAt(struct node* head, int position, int *result) {
   // TODO: Alistirma 7
    int d = 0;
    struct node* cur = head;
    for (; cur != NULL; cur = cur->next) {
        d++;
    }
    cur = head;
    if (d < position) return 1;
    else {
        for (d = 1; d < position; d++) {
            cur = cur->next;
        }
        *result = cur->data; 
        return *result;
    }
}
/* Listede value degerinin kac defa
 * yer aldigini hesaplayip geri donduren fonksiyonu yazin. */
int Count(struct node* head, int value) {
  // TODO: Alistirma 8
    int d = 0;
    struct node* cur = head;
    for (; cur != NULL; cur = cur->next) {
        if (value == cur->data) {
            d++;
        }
    }
    return d;
}

/*  head = NULL; bir ise yaramiyor, yine son terime 10 basıyor.
    free(head); yapinca da program calismiyor (mantiken).
    headi kaybetmeden ve listenin ustune yazmadan listeyi sifirlayip 
    sifirdan eleman istemeyi tek bir fonksiyonda yapamadim, */
void Empty(struct node* head) {
    head->next = NULL;  
}



