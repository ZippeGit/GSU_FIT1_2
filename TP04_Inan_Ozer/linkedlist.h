/*
 * linkedlist.h
 *
 *  Created on: Mar 7, 2019
 *      Author: Merve Unlu
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/* Listenin dugumlerini temsil eden yapi
 * @data: O dugumde tutulan tamsayi turunden veri
 * @next: Sonraki dugume isaret edecek gosterici
 */
struct node {
    int data;
    struct node* next;
};

struct node* create_sample_list(void) ;void Print(struct node* head);
int verifyList(struct node* head, int *values) ;
int Length(struct node* head);
void Insert(struct node** head, int new_value, int position) ;
void Free(struct node* head);
int GetAt(struct node* head, int position, int *result) ;
int Count(struct node* head, int value) ;
void Empty(struct node* head);


#endif /* LINKEDLIST_H_ */
