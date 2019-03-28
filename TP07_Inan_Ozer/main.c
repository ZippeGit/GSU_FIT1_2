#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hash.h"
#define CREATE 1 
#define NCREATE 0

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Kullanim: %s <dosya_adi>\n", argv[0]);
        exit(1);
    }

    Key *w = NULL;
    char word[1024];

    /* Her elemani bir bagli liste olan hash tablosu */
    Key *hash_table[MAXBUCKETS];

    /* Bellek alanini sifirla */
    memset(hash_table, 0, sizeof(hash_table));

    /* Dosyayi ac */
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("%s dosyasi bulunamadi.\n", argv[1]);
        exit(1);
    }

    /* Sonsuz dongu icerisinde dosyadan kelime kelime
     * okuma yapalim. Okudugumuz kelimeyi hash'ta
     * arayalim yoksa ekleyelim. Son olarak elimize gecen
     * dugumun count uyesini 1 artiralim. */
    while (1) {
        if (fscanf(fp, "%s", word) != 1)
            break;

        w = hash_lookup(hash_table, word, CREATE);
        w->count++;
    }

    /* Dosyayi kapat */
    fclose(fp);
    
     // Alistirma 4
    char answr[25];
    printf("Please enter a word to see how many words have the same hash code: ");
    scanf("%s", answr);
    printf("%d words have the same hash code as '%s' (including multiple appearences of the same word)\n", hash_count_word(hash_table, answr), answr);
    printf("These words have the same has code as the one you entered: ");
    hash_same_code(hash_table, answr);

    /* 100'den fazla gecen kelimeleri ekrana yazdir */
    printf("\nDo you want how many times each word appears to be printed?\n");
    printf("A) Yes\nB) Of course\nC) Sure\n");
    scanf("%s", answr);
    printf("\nOk, printing the table in\n3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);

    hash_dump(hash_table, 100);
    
     // Alistirma 5 
    int cnt_array[3] = {120,30,20};
    
     // hash_dump fonksiyonunu bir dongu icerisinde cagiriniz. 
    printf("\nDo you want 3 tables to be printed? (R.I.P. terminal)\n");
    printf("A) YES\nB) More = Better\nC) I LOVE tables\n");
    scanf("%s", answr);
    printf("\nWell if you say so, printing 3 tables in\n3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    int d = 0;
    for (d = 0; d < 3; d++) {
        hash_dump(hash_table, cnt_array[d]);
        if (d != 2) {
            printf("Printing the next one...\n");
            sleep(1);
        }
        else {
            printf("We're done here, exiting program...\n");
        }
    }

    /* hash'i temizle */
    hash_free(hash_table);
    return 0;
}
