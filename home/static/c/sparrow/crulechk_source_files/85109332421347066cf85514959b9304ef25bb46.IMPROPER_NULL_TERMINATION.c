#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NTBS_SIZE 5

/* void problem(){ */
/*   char *x = "abcdefg"; */
/*   char y[8]; */
/*   __sparrow_strncpy(x,5); */
/*   __sparrow_strncpy(y,5); */
/* } */

void foo1(char *source){
  char ntbs[5];
  ntbs[sizeof(ntbs)-1] = '\0';

  strncpy(ntbs, source, sizeof(ntbs));
  printf("foo1: %s\n", ntbs);
}

void foo2(char *source){
  char ntbs[5];
  
  memset(ntbs, 0, sizeof(ntbs)-1);
  strncpy(ntbs, source, sizeof(ntbs)-1);
  printf("foo2: %s\n", ntbs);
}

void bar1(char *source){
  char ntbs[5];
  strncpy(ntbs, source, sizeof(ntbs)-1);
  ntbs[sizeof(ntbs)-1] = '\0';
  printf("bar1: %s\n", ntbs);
}

void bar2(char *source){
  char ntbs[5];
  /* ... */
  if (source) {
    if (strlen(source) < sizeof(ntbs)) {
      strcpy(ntbs, source);
    }
    else {
      /* handle string too large condition */
    }
  } else {
    /* handle NULL string condition */
  }
  printf("bar2: %s\n", ntbs);
}

void xman(){
  char *a = "aa";
  char *b = "123456789";
  foo1(a);
  foo1(b);
  foo2(a);
  foo2(b);
  bar1(a);
  bar1(b);
  bar2(a);
  bar2(b);
}
