#include <stdio.h>

void flp05_test(){
  float x = 1/3.0;
  printf("Original      : %le\n", x);
  x = x * 7e-10;
  printf("Denormalized? : %le\n", x);
  x = x / 7e-10;
  printf("Restored      : %le\n", x);
}

void flp05_bad(){
  float x = 1/3.0;
  printf("Original      : %e\n", x);
  x = x * 7e-45;
  printf("Denormalized? : %e\n", x);
  x = x / 7e-45;
  printf("Restored      : %e\n", x);
}

void flp05_good(){
  double x = 1/3.0;
  printf("Original      : %e\n", x);
  x = x * 7e-45;
  printf("Denormalized? : %e\n", x);
  x = x / 7e-45;
  printf("Restored      : %e\n", x);
}

void main(){
  flp05_bad();
  flp05_good();
  printf("\n");
  flp05_test();
}
