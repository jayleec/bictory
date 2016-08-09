/* MEM12-C. Consider using a Goto-Chain when leaving a function on
   error when using and releasing resources */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct object {   // A generic struct -- The contents don't matter
  int propertyA, propertyB, propertyC;
} object_t;
 
 
unsigned int mem12_bad1(void){
  void *fin1, *fin2;
  object_t *obj;
  unsigned int ret_val = 0;
   
  fin1 = fopen("some_file", "r");
  if (fin1 == 0) {
    return 1;
  }
 
  fin2 = fopen("some_other_file", "r");
  if (fin2 == 0) {
    return 1;  //@violation LEAK.RESOURCE
  }
 
  obj = malloc(sizeof(object_t));
  if (obj == 0) {
    ret_val = 0;
    fclose(fin1);
    return ret_val;  //@violation LEAK.RESOURCE
  }
 
  // ... more code ...
 
  fclose(fin1);
  fclose(fin2);
  free(obj);
  return 0;
}


void test(){
  int *x = malloc(100);
  void *f = fopen("a.txt", "r");
  if (f < 0) {
    free(x);
    return; //@violation(NOT_EXPECTED) LEAK.RESOURCE
  }

  if(x == 0) {
    return; //@violation LEAK.RESOURCE
  }
  free(x);
  fclose(f);
}

  
