/* MEM31-C. Free dynamically allocated memory exactly once */
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int mem31_bad1(unsigned int n) {
  int error_condition = 0;
 
  int *x = (int*)malloc(n * sizeof(int));
  if (x == 0)
    return -1;
 
  /* Use x and set error_condition on error. */
  
  if (x != 0) 
    error_condition = 1;
  
  if (error_condition == 1) {
    /* Handle error condition*/
    free(x);
  }
 
  /* ... */
  free(x); //@violation DOUBLE_FREE
  return error_condition;
}


int mem31_good1(unsigned int n) {
  int error_condition = 0;
  int errno;
  if (n > 256 / sizeof(int)) {
    errno = 1;
    return -1;
  }
 
  int *x = (int*)malloc(n * sizeof(int));
  if (x == 0) {
    /* Report allocation failure to caller. */
    return -1;
  }
 
  /* Use x and set error_condition on error. */
 
  if (error_condition != 0) {
    /* Handle error condition and proceed. */
  }
 
  free(x);
 
  return error_condition;
}

void mem31_bad2(){
  int size = 100;
  char *p = malloc(100);
  
/* p is a pointer to dynamically allocated memory */
  char *p2 = realloc(p, size);
  if (p2 == 0) {
    free(p); //@violation DOUBLE_FREE
    /* p may be indeterminate when (size == 0) */
    return;
  }
  free(p2);
}
