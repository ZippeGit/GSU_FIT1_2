/*************************************
 * Shell Sort
 ************************************/

void shell_sort(int *array, int size) {
  /* Sedgewick tarafindan belirlenen gap serisi */
  int gaps[] = {4193, 1073, 281, 77, 23, 8, 1};
  int i, j, k, cur, gap;

  /*TODO*/
  for (i = 0; i < 7; i++) {
    gap = gaps[i];
    for (j = gap; j < size; j++) {
      cur = array[j];
      k = j;
      while (k >= gap && array[k - gap] > cur) {
        array[k] = array[k - gap];
        k = k - gap;
      }
      array[k] = cur;
    }
  }
}

void ciura_shell_sort(int *array, int size) {
  /* Ciura tarafindan belirlenen gap serisi */
  int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
  int i, j, k, gap, cur;

  /*TODO*/
  for (i = 0; i < 8; i++) {
    gap = gaps[i];
    for (j = gap; j < size; j++) {
      cur = array[j];
      k = j;
      while (k >= gap && array[k - gap] > cur) {
        array[k] = array[k - gap];
        k = k - gap;
      }
      array[k] = cur;
    }
  }
}


