/* MEM32-C. Detect and handle memory allocation errors */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mem32_bad1(char *input_string) {
  unsigned int size = strlen(input_string) + 1;
  char *str = (char *)malloc(size);
  strcpy(str, input_string); //@violation NULL_DEREF.MALLOC_FAILED
  /* ... */
  return; //@violation LEAK.MEMORY
}

void mem32_good1(char *input_string) {
  unsigned int size = strlen(input_string) + 1;
  char *str = (char *)malloc(size);
  if (str == 0) {
    /* Handle allocation failure and return error status */
    return -1;
  }
  strcpy(str, input_string);
  /* ... */
  free(str);
  return 0;
}

void mem32_bad2(){
  
  char *p = (char*)malloc(100);
  unsigned int new_size = 10  /* nonzero size */;
  
  p = realloc(p, new_size);
  if (p == 0)   {
    /* Handle error */
    return;
  }
  return; //@violation LEAK.MEMORY
}
