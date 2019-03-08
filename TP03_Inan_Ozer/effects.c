#include "effects.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Parametre olarak aldigi piksel dizisindeki her bir elemana 
 * rastgele olarak gurultu ekler. 
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 * 
 */
void effect_random_noise(unsigned char *pixels, int width, int height) {
    int nr_noisy_pixel = (width * height) / 5; // %5 oraninda noise ekle
    int i;
    // Dizideki elemanlarin %5 ine rasgele secerek 
    // gurultu ekler
    for (i = 0; i < nr_noisy_pixel; ++i ) {
        int which_pixel = (rand() % (width * height));
        pixels[which_pixel] = (rand() % 256);
    }
}

/*
 * Fotografa smooth efektini ekler. 
 * Parametre olarak piksel degerlerini icere dizi 
 * ve bu dizinin boyutlarını alır.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 */
void effect_smooth(unsigned char *pixels, int width, int height) {
    int i;
    // Her bir piksel degeri icin 
    for (i = 0; i < width * height -1; ++i) {
        // Yanyana iki degerin ortalamasını alır ve 0-255 aralıgına 
        // gore dengeler.
        pixels[i] = ((pixels[i] + pixels[i+1]) / 2) % 256;
    }
}

/* Invert efekti her pikselin degerinin tumleyenini o pikselin
 * yeni degeri olarak belirler.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 */
void effect_invert(unsigned char *pixels, int width, int height) {
    int i;
    int color;
    // TODO: Her bir piksel degerini tumleyen olarak degistiren 
    // fonksiyonu yaziniz.
    // Alistirma 3.a
    for (i=0; i<width*height; i++) {
        color = pixels[i];
        pixels[i] = 255 - color;
    }     
}

/* Belirlenen bir esik degerin altinda kalan pikselleri siyah,
 * uzerinde kalanlari ise beyaz yaparak 2 renkli bir resim olusturur.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 *        threshold: esik degeri
 * Output : void
 */
void effect_threshold(unsigned char *pixels, int width, int height, int threshold) {
    int i;
    // TODO: Her bir pikseli kontrol eder.
    // Deger thresholdan buyuk ise beyaz, degilse siyah olarak 
    // degerini gunceller.
    // Alistirma 3.b
    for (i=0; i<width*height; i++) {
        if (pixels[i] < threshold) pixels[i] = 0;
        else pixels[i] = 255;
    }
}

// Alistirma 3.c
/* Resmi y ekseninde dondurur; solunu saga, sagini sola getirir.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
*/
void effect_flip(unsigned char *pixels, int width, int height) {
    int i = 0;
    int d = 0;
    unsigned char *temp = malloc(width*height*sizeof(unsigned char));
    
    for (i=0; i<height*width; i++) {
        temp[i] = pixels[i];
    } 

    for (i=0; i<height; i++) {
        for (d=0; d<width; d++) {
            pixels[(i*width)+d] = temp[((i+1)*width)-d-1];    
        }
    }
    free(temp);
}

/* Resmin sag yarisini alip sol yairisina yapistirir.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 * (flip fonksiyonuna cok benziyorlardi sacma resimler yapmak icin koydum)
*/
void effect_mirror_right(unsigned char *pixels, int width, int height) {
    int i = 0;
    int d = 0;

    for (i=0; i<height; i++) {
        for (d=0; d<width; d++) {
            pixels[(i*width)+d] = pixels[((i+1)*width)-d-1];    
        }
    }
}

/* Resmin sol yarisini alip sag yairisina yapistirir.
 * Input: pixels : piksel degerleri iceren dizi 
 *        width  : dizinin satirm sayisi
 *        height : dizinin sutun sayisi
 * Output : void
 * (flip fonksiyonuna cok benziyorlardi sacma resimler yapmak icin koydum)
*/
void effect_mirror_left(unsigned char *pixels, int width, int height) {
    int i = 0;
    int d = 0;

    for (i=0; i<height; i++) {
        for (d=0; d<width; d++) {
            pixels[((i+1)*width)-d-1] = pixels[(i*width)+d];  
        }
    }
}
