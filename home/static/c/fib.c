/*******************************************************************************
A function which prints the first few fibbonacci numbers
*******************************************************************************/

#include <stdio.h>

void print_fibs() {
  int max = 10;
  int x[10];
  int i;

  x[0] = 0;
  printf("%d\n", x[0]);

  x[1] = 1;
  printf("%d\n", x[1]);

  for (i = 1; i <= max; i++) {
    x[i] = x[i-1] + x[i-2];  //The last iteration, i == max, which is out of range, by 1. //@violation UNDERRUN.STATIC
    printf("%d\n", x[i]);  //The last iteration, i == max, which is out of range, by 1.
  }
}
