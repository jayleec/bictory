/* ARR38-C. Guarantee that library functions do not form invalid
   pointers */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void arr38_bad1() {
  char p[100];
  const unsigned int n = 100 + 1;
  if(!p) return;
  memset(p, 0, n); //@violation OVERRUN.STATIC.MEMSET
 
  /* ... */
}

void arr38_safe1(unsigned int nchars, unsigned int val){
  char *p = (char *)malloc(nchars);
  const unsigned int n = val;
  if(!p) return;
 
  if (nchars < n) {
    /* Handle Error */
  } else {
    memset(p, 0, n);
  }
  /* ... */
  free(p);
}

void arr38_bad2(int i) {
  float a[4];
  float b[100];
  const unsigned int n = sizeof(int) * 4 + 1;
  void *p = 0;
  if(i > 0){
    p = a;
  } else {
    p = b;
  }
  i= i+100;
  if (i > 100){
    memset(p, 0, n); //@violation OVERRUN.STATIC.MEMSET
  }
  return;
  /* ... */ 
}


void arr38_safe2() {
  const unsigned int ARR_SIZE = 4;
  float a[ARR_SIZE];
  const unsigned int n = sizeof(float) * ARR_SIZE;
  void *p = a;
 
  memset(p, 0, n);
  /* ... */
}


void arr38_safe3(char p[], const char *q, unsigned int size_p) {
  const unsigned int n = size_p; 
  if ((memcpy(p, q, n)) == p) {  
    /* ... */
  }
  
  /* ... */
}
