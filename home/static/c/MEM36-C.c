/* MEM36-C. Check for alignment of memory space before calling
   realloc() function */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mem36_bad(){
  unsigned int resize = 1024;
  unsigned int alignment = 1 << 12;
  int *ptr;
  int *ptr1;
 
  if ((ptr = aligned_alloc(alignment , sizeof(int))) == 0) {
    /* Handle error */
  }
 
  /* ... */
 
  if ((ptr1 = realloc(ptr, resize)) == 0) { //@violation CHECK_ALIGNMENT_OF_MEMORY
    /* Handle error */
  }
  free(ptr1);
}

void mem36_good(){
  
  unsigned int resize = 1024;
  unsigned int alignment = 1 << 12;
  int *ptr;
  int *ptr1;
 
  if ((ptr = aligned_alloc(alignment, sizeof(int))) == 0) {
    /* Handle error */
    return;
  }
 
  /* ... */
 
  if ((ptr1 = aligned_alloc(alignment, resize)) == 0) {
    /* Handle error */
    free(ptr);
    return;
  }
 
  if (memcpy(ptr1, ptr, sizeof(int)) == 0) {
    /* Handle error */
    return;
  }
 
  free(ptr);
  free(ptr1);
}
