/*
 * main.c
 *
 *  Created on: Mar 7, 2019
 *      Author: Merve Unlu
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"linkedlist.h"

int main(int argc, char *argv[])
{
    int test[] = {5, 1024, 10, 20, 30, 100, 2048};
    int test1[] = {10, 20, 30};
    int tmp, vrfy = 0, length = 0;
    int d = 0;
    char answer[1];

    /* TODO :Alistirma 2 Basit listeyi yarat
     *           Ekrana bas */
    printf("Creating sample list...\n");
    struct node *list = create_sample_list();
    Print(list);

    /*TODO: Alistirma 3 verifyTest() fonksiyonu icin test */
    vrfy = verifyList(list, test1);
    if (vrfy == 1) printf("The list is verified.\n");
    else printf("Nope, they are different lists.\n");

    /* TODO: Alistirma 4 Length() fonksiyonu icin test */
    // printf("Listenin uzunlugu: %d\n", Length(list));

    // Print(list);
    length = Length(list);
    printf("Length of the list is: %d\n", length);

    /*TODO: Alistirma 5 Listeye test teki elemanlari ekle. */
    //Insert(&list, 15, 2);
    Empty(list);
    for (d = 0; d < 7; d++) {
        Insert(&list, test[d], d);
    }
    /* Su an liste: 5, 1024, 10, 20, 30, 100, 2048 */
    // Print(list);
    Print(list);
    length = Length(list);
    printf("Length of the second list is: %d\n", length);

    /* TODO Alistirma 7 GetAt() fonksiyonu icin testler */
    int fetch = 0;
    printf("Just say which position and I will bring them here: ");
    scanf("%d", &fetch);
    GetAt(list, fetch, &tmp) ;
    if (tmp == 0) {
        printf("Here it is: A big zero for you, well deserved.\n");
    }
    else {
        printf("Here it is: %d\n", tmp);
    }

    /* TODO Alistirma 8 Count() fonksiyonu icin testler */
    int search = 0;
    printf("Which value are you looking for? ");
    scanf("%d", &search);
    int number = Count(list, search);
    printf("The value you are looking for (%d) appears %d time(s).\n", search, number);

    /* Bagli listeyi temizleyin */
    printf("Free the memory?[Y/N] ");
    scanf("%d", &d);
    printf("Trick question, we will free it anyway.\n");
    Free(list);

    return 0;
}
