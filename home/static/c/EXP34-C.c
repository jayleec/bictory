#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void EXP34_1(char *input_str){
  char *str;
  int size = strlen(input_str)+1;
  str = (char *)malloc(size);
  memcpy(str, input_str, size); //@violation NULL_DEREF.MALLOC_FAILED
  /* ... */
  free(str);
  str = 0;
}

void simple(int x, int b) {
  char *p1, *p2, *p3;
  char c = 0;
  p1 = &c;
  p2 = &c;
  p3 = &c;

  if (x > 0) {
    p1 = (char *)0;
  }
  if (x > 2) {
    *p1 = '1';  //@violation NULL_DEREF
    c = *p1;    //@violation NULL_DEREF
  }

  if (b) {
    p2 = (char *)0;
  }
  if (!b) {
    c = *p2;    //@violation(NOT_EXPECTED) NULL_DEREF
  }

  if (b) {
    p3 = (char *)0;
  }
  if (b == 0) {
    c = *p3;    //@violation(NOT_EXPECTED) NULL_DEREF
  }
}


int n;

int intra_1_1(int level) {
  int *x = (int *)0;
  if (level > 0)
    x = &n;
  if (level < /* > */ 4)
    return *x; //@violation NULL_DEREF
  return 0;
}
int intra_1_2(int level) {
  int *x = (int *)0;
  if (level > 0)
    x = &n;
  if (level /* < */ > 4)
    return *x; //@violation(NOT_EXPECTED) NULL_DEREF
  return 0;
}

int intra_2_1(int b) {
  int *x = (int *)0;
  if (b)
    x = &n;
  if (!b /* b */)
    return *x; //@violation NULL_DEREF
  return 0;
}
int intra_2_2(int b) {
  int *x = (int *)0;
  if (b)
    x = &n;
  if (/* !b */ b)
    return *x; //@violation(NOT_EXPECTED) NULL_DEREF
  return 0;
}

int intra_3_1(int *x) {
  int *y = (int *)0;
  if (x != (int *)0)
    y = &n;
  if (y != (int *)0)
    return *x + *y; //@violation(NOT_EXPECTED) NULL_DEREF

  else
    return *x /* 0 */; //@violation NULL_DEREF.MISSING_CHECK
}
int intra_3_2(int *x) {
  int *y = (int *)0;
  if (x != (int *)0)
    y = &n;
  if (y != (int *)0)
    return *x + *y; //@violation(NOT_EXPECTED) NULL_DEREF

  else
    return /* *x */ 0; //@violation(NOT_EXPECTED) NULL_DEREF

}

int intra_4_1(int b) {
  int *x = (int *)0;
  int *y = (int *)0;
  int _x = 0, _y = 0;
  if (b)
    x = &_x;
  if (x != (int *)0)
    y = &_y;
  if (y != (int *)0)
    return *x + *y; //@violation(NOT_EXPECTED) NULL_DEREF

  else
    return *x /* 0 */; //@violation NULL_DEREF
}
int intra_4_2(int b) {
  int *x = (int *)0;
  int *y = (int *)0;
  int _x = 0, _y = 0;
  if (b)
    x = &_x;
  if (x != (int *)0)
    y = &_y;
  if (y != (int *)0)
    return *x + *y; //@violation(NOT_EXPECTED) NULL_DEREF

  else
    return /* *x */ 0; //@violation(NOT_EXPECTED) NULL_DEREF

}

int intra_5(int *x) {
  if (x == (int *)0)
    return *x; //@violation NULL_DEREF.MISSING_CHECK
  return 0;
}

int intra_6(int *x) {
  if (x == (int *)0) {
    int *y = x;
    return *y; //@violation NULL_DEREF.MISSING_CHECK
  }
  return 0;
}

int null_deref(int *p, int n){
  int m = n + 10;
  if (n > 0) {
    *p = 10;
    if(m > 0){
      *p = n / (m - n); 
    }
    log("sparrow fly %d",m);
    return 10;
  } 
  return m;
}
    
void caller1(int k, int *p2){
  int *p = malloc(100);
  int m;
  if(p == 0) return;
  if(k > 0){
    m = null_deref(p,0);
    k = k/m;
  } else {
    m = null_deref(p2,k);
    k = k/m;
  }

  free(p);
}

void exp34_bar(int *p){
  if (p != 0) {
    *p = 100;
  }
}

void exp34_foo(){
  int *p = 0;
  exp34_bar(p);
}

void exp34_complex_path(int a){
  int *p = &a;
  if (a > 10){
    p = 0;
  } 

  if (a < 10) *p = 10; //@violation(NOT_EXPECTED) NULL_DEREF


  if (a > 0) *p = 5; //@violation NULL_DEREF
  return; 
}

