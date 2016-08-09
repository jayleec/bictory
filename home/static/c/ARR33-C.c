/* ARR33-C. Guarantee that copies are made into storage of sufficient
   size */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void arr33_bad1(const int *src) {
  int dest[255];
  int num_elem = 100;
  int i;
  for(i=0; i<100; i++){
    num_elem = 2*i;
  }
  if(i > 50){
    num_elem = 300;
  }

  memcpy(dest, src, num_elem * sizeof(int)); //@violation OVERRUN.STATIC.MEMSET

  if(i < 10){
    memcpy(dest, src, num_elem * sizeof(int)); //@violation(NOT_EXPECTED) OVERRUN.STATIC.MEMSET
  }
}

void arr33_bad1_call(){
  int src[500];
  arr33_bad1(src);
}

void arr33_good1(const int *src, int num_elem) {
  int *dest;
  if (num_elem > 1000/sizeof(int)) {
   /* Handle integer overflow */
  }
  dest = (int *)malloc(sizeof(int) * num_elem);
  if (dest == 0) {
    return;
     /* Couldn't get the memory - recover */
  }
  memcpy(dest, src, sizeof(int) * num_elem); //@violation(NOT_EXPECTED) OVERRUN.STATIC.MEMSET
 
  /* ... */
 
  free(dest);
}

void arr33_main(){
  arr33_bad1_call();
  arr33_bad1("10000000");
}
