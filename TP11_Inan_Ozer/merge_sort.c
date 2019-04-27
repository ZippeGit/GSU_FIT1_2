#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int low, int middle, int high) {
 
  int *temp = malloc((high-low+1)*sizeof(int));

  /* TODO: Sol yarim listenin boyunu hesaplayin */
  int left = middle - low + 1;

  /* TODO: Sag yarim listenin boyunu hesaplayin */
  int right = high - middle;

  /* TODO: Sol ve sag yarim liste icin dizi tanimlayin */
  int left_arr[left];
  int right_arr[right];

  /* TODO: Sol yarim listeyi sinirlarina gore doldurun */
  for (int d = 0; d < left; d++) {
    left_arr[d] = array[low + d];
  }

  /* TODO: Sag yarim listeyi sinirlarina gore doldurun */
  for (int d = 0; d < right; d++) {
    right_arr[d] = array[d + middle + 1];
  }

  /* TODO: Birlestirme: Sol ve sag yarim listeleri kendi aralarinda
   * karsilastirarak listenin ilgili yerine yerlestirin.
   * iki yarim listeden birinin sonuna gelindiginde donguden cikilmalidir. */
  int d = 0, i = 0, j = 0;
  while ((d < left) && (i < right)) {
    if (left_arr[d] <= right_arr[i]) {
      temp[j] = left_arr[d];
      d++;
    }
    else {
      temp[j] = right_arr[i];
      i++;
    }
    j++; 
  }

  /* TODO: Yarim listelerin tum elemanlari listenin ilgili yerine
   * sokulmadiysa, kalan elemanlari yerlestirin. */
  while (d < left) {
    temp[j] = left_arr[d];
    j++;
    d++;
  }
  while (i < right) {
    temp[j] = right_arr[i];
    j++;
    i++;
  }

  for (int d = low; d <= high; d++) {
    array[d] = temp[d - low];
  }

}

/* Bolme ve birlestirme metodunu gerceklestiren fonksiyon */
void merge_sort(int *array, int low, int high) {
  /* Eger elde kalan liste tek elemanli degilse */
  if (low < high) {
     // TODO 
    /* Orta noktayi bul */
    int middle = low + (high - low) / 2;

    /* Sol tarafi ozyinelemeli olarak sirala */
    merge_sort(array, low, middle);
  
    /* Sag tarafi ozyinelemeli olarak sirala */
    merge_sort(array, middle + 1, high);

    /* Siralanmis listeleri birlestir */
    merge(array, low, middle, high);
  }
}

void merge_sort_wrapper(int *array, int size) {
  merge_sort(array, 0, size - 1);
}
