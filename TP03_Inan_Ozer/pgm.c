#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "pgm.h"

/* PGM dosyasinin baslik bilgilerini ekrana yazdiran fonksiyon */
void pgm_print_header(PGMInfo pgm_info) {
    printf("This is a %s type PGM image containing %d x %d pixels\n",
           pgm_info.signature,
           pgm_info.width,
           pgm_info.height);
}

/*
 * Parametre olarak verilen dosya adini bagli dosyayi acar, 
 * herhangi bir hata olusmama durumunda fotograf icerik degiskeni 
 * dondurur.
 * Input : char filename dosya adini
 * Output: struct PGMInfo tipinde degisken
 */
PGMInfo pgm_read(const char *filename) {
    
    /* PGMInfo turunden bir degisken yaratip, 
     *error uyesini 0 yaptik. 
     */
    PGMInfo pgm_info = {.error = 0};

    /* Dosyadaki satirlari okumak icin bir tampon. */
    char line[LIN_MAX]; //Neden LINE_MAX yerine LIN_MAX? Bknz: pgm.h
    int i = 0;
    int read = 0;

    /* Dosyayi acin. Eger dosya acilamazsa pgm_info'nun error
     * uyesini PGM_ERROR_READ yapip fonksiyonu dondurun.
     */
    // TODO: Dosya acma ve hatali durum islemlerinizi burada yaziniz. 
    // Alistirma 1.a
    // acilan dosya pgm icinde tutulmali
    FILE *pgm;
    pgm = fopen(filename, "r"); 
    if (pgm == NULL) {
        pgm_info.error = 1;
    }

    /* Dosyadan tam bir satiri line tamponuna okur*/
    fgets(line, sizeof(line), pgm);

    /* Daha sonra sscanf() ile bu tampondan "%s " ile okuma yapalim.*/
    sscanf(line, "%s ", pgm_info.signature);

    /* PGM imzasi P2 veya P5 degilse dosyayi kapatin, error'u
     * PGM_ERROR_SIGNATURE yapip fonksiyonu dondurun\.
     */
    //TODO: Dosya imza kontrol islemlerinizi burada yaziniz.  
    // Alistirma 1.b
    if ((strcmp(pgm_info.signature, "P2") != 0) && (strcmp(pgm_info.signature, "P5") != 0)) {
        pgm_info.error = 2;
    }
    
    /* Yorum satirini oku. */
    fgets(pgm_info.comment, sizeof(line), pgm);

    /* En ve boyu oku */
    fgets(line,sizeof(line),pgm);
    sscanf(line,"%d %d",&pgm_info.width, &pgm_info.height);

    /* Max piksel degerini oku */
    fgets(line,sizeof(line),pgm);
    sscanf(line,"%u",&pgm_info.max_pixel_value);
   
    /* pgm_info.pixels icin malloc() ile yer ayiralim.
     * Bir piksel 1 bayt yer istiyor, unutmayalim.
     */
   
    // TODO: malloc islemlerinizi burada yaziniz.    
    /* malloc() ile yer ayrilamazsa dosyayi kapatin, error'u
     * PGM_ERROR_MALLOC yapip fonksiyonu return ettirin.*/
    int pixel_num = pgm_info.width * pgm_info.height;
    pgm_info.pixels = malloc(pixel_num * sizeof(unsigned char));

    // TODO: malloc icin hata kontrolunu burada yaziniz.
    // Alistirma 1.c
    if (pgm_info.pixels == NULL) {
        pgm_info.error = 3;
        return pgm_info;
    } 
    
    /* 2 farkli dosya bicimi, 2 farkli okuma bicimi.
     * P2 yani ASCII olanda dosyayi fgets() ile satir satir okuyoruz.
     * Okudugumuz satirin sonundaki '\n' karakterini kaldiriyoruz
     * ve elimizde kalan string'i atoi() ile sayiya cevirip pixels
     * dizisine kaydediyoruz.
     *
     * P5 yani binary olanda ise dogrudan fread() ile bir kerede pixels'e
     * okuma yapiyoruz.
     */
    // Alistirma 1.d
    int fcheck;
    switch (pgm_info.signature[1]) {
        case '2':
            /* TODO: ASCII PGM dosyalarda piksel okuma islemlerinizi 
	     * burada yaziniz. */
	    // Ipucu: for dongusu icinde fgets !! 
            for(i=0; i<pixel_num; i++) {
                fgets(line, sizeof(line)-1, pgm);
                pgm_info.pixels[i] = atoi(line);
                read++;
            }
            break;
        case '5':
            /* TODO: Binary PGM dosyalarinda piksel okuma 
	     islemleriniz burada yaziniz. */
	    // Ipucu : for dongusu olmadan tek satirda fread !!
            fcheck = fread(pgm_info.pixels, sizeof(unsigned char), pixel_num, pgm);
            read = fcheck*sizeof(unsigned char);
            break;
    }
    fclose(pgm);

    /* Eger dogru okuma yapamadiysaniz programiniz assert() sayesinde
     * yarida kesilecek. */
    printf("Read %d bytes. (Should be: %d)\n", read, pgm_info.width * pgm_info.height);
    assert(read == (pgm_info.width * pgm_info.height));

    return pgm_info;
}

/*
 * Fonksiyon parametre olarak aldigi PGMInfo tipindeki 
 * degiskenin icerisindeki degerleri filename dosya adiyla kaydeder.
 * Input: filename : kaydedilecek dosya adi
 *        pgm_info : kaydedilecek dosya icerigi
 * Output: basarili ise 0, degilse 1
 */

int pgm_write(const char *filename, PGMInfo pgm_info) {
    int d = 0;

    /* Dosyayi write kipinde acin. Acma basarisiz olursa fonksiyon
     * 1 dondurerek sonlanmalidir. */

    // TODO: Dosya acma islemlerinizi burada yaziniz.
    // Alistirma 2.a
    FILE *pgm;
    pgm = fopen(filename, "w");
    if (pgm == NULL) {
        return 1;
    }

    /* Baslik yapisini fprintf() ile dosyaya yazin */
    //TODO:  Baslik dosyasini filename dosyasina kaydetme 
    // islemini burada yapiniz. 
    // Alistirma 2.b
    fprintf(pgm, "%s\n %s\n %d %d\n %u\n", pgm_info.signature, pgm_info.comment, pgm_info.width, pgm_info.height, pgm_info.max_pixel_value);
    
    /* 2 farkli dosya bicimi, 2 farkli yazma bicimi */
    // Alistirma 2.c

    switch (pgm_info.signature[1]) {
        case '2':
            /* TODO: ASCII PGM (ipucu: fprintf) her piksel sira ile yazilacak*/
            for(d=0; d<pgm_info.height*pgm_info.width; d++) {
                fprintf(pgm, "%u", pgm_info.pixels[d]);
                fprintf(pgm, "\n");
            }            
            break;
        case '5':
            /* TODO: Binary PGM (ipucu: fwrite) */
            fwrite(pgm_info.pixels, sizeof(unsigned char), pgm_info.width*pgm_info.height, pgm);
            break;

    }
    /* Dosyayi kapatalim. */
    fclose(pgm);
    return 0;
}
