#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "patient.h"

const char *priority_strings[] = {
    "Heart attack",
    "Fracture",
    "Nausea",    
    "Fever",
    "Headache",
    NULL,
};


/*
 * Parametre olarak verilen kuyruk yapisinin
 * elemanlarini ekrana basar.
 */
void print_queue(struct patientInfo *head) {
   if (!is_empty(head)) {
        printf("\nCurrent Queue:\n");
        printf("--------------\n");
        int i = 1;
        while (head) {
            printf("%2d: [%12s (priority: %d)] Social security number: %d\n", i, priority_strings[head->prio], head->prio, head->ssn);
            head = head->next;
            i += 1;
            sleep(1);
        }
        printf("\n");
    }
}

/*
 * Parametre olarak verilen kuyrugun bos olup
 * olmadigini kontrol eder.
 * Bos ise 1 degilse 0 dondurur.
 */
int is_empty(struct patientInfo *head) {
    // Alistirma 1
    if (head == NULL) return 1;
    else return 0;
}

/* Parametre olarak verilen elemanlardan
 * yeni bir hasta olusturup
 * kuyruga ekler.
 * Hastanin guvenlik numarasi ve 
 * oncelik bilgisi fonksiyon parametreleridir. 
 */
struct patientInfo* enqueue(struct patientInfo *head, enum Priority prio, int ssn) {
    struct patientInfo *newhead = malloc(sizeof(struct patientInfo));
    struct patientInfo *cur = head;
    if (newhead == NULL) printf("Malloc error... (1)\n");

    newhead->prio = prio;
    newhead->ssn = ssn;
    newhead->next = NULL;

    if (cur == NULL) {
        head = newhead;
    }

    else if (cur->next == NULL) {
        if(newhead->prio < cur->prio) {
            newhead->next = cur;
            head = newhead;
        }
        else {
            head->next = newhead;
        }
    }
    else {
        while (cur->next != NULL) {
            if (newhead->prio < cur->prio) {
                newhead->next = cur;
                head = newhead;
                break;
            }
            if (newhead->prio <= (cur->next)->prio) {
                break;
            }
            cur = cur->next;
        }
        newhead->next = cur->next;
        cur->next = newhead;
    }

    return head;
}


/*
 * Parametre olarak verilen kuyruktan ilk elemani siler
 * ve geri dondurur.
 */
struct patientInfo* dequeue(struct patientInfo **head) {
  // Alistirma 3
    struct patientInfo *temp = malloc(sizeof(struct patientInfo));
    temp = *head;
    *head = (*head)->next;

    return temp; 
}


