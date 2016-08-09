/* MEM30-C. Do not access freed memory */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mem30_bad1(const char *argv[]){
  char *buff;
  
  buff = (char *)malloc(256);
  if (!buff) {
    /* Handle error condition */
    return;
  }
  /* ... */
  free(buff);
  /* ... */
  strncpy(buff, argv[1], 256-1); //@violation USE_AFTER_FREE //@violation USE_AFTER_FREE
  return;
}

char global[100];

char * mem30_bad2(int n){
  char *p;
  
  if (n > 10) {
    p = malloc(100);
  } else {
    p = global;
  }
  
 
  if (n > 10) {
    free(p);
    return p; //@violation RETURN_FREE
  } 

  return p; 
}


