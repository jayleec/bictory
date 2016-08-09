#include <stdio.h>
#include <stdlib.h>
int global;

/* void foo(){ */
/*   int *ptr = __sparrow_memalign(); */
/*   __sparrow_realloc_free(ptr); */
/* } */

/* void bar(){ */
/*   int resize = 1024; */
/*   int alignment = 1 << 12; */
/*   int *ptr; */
/*   int *ptr1; */
  
/*   ptr = aligned_alloc(alignment , sizeof(int)); */
/*   ptr1 = realloc(ptr, resize); */
/*   free(ptr1); */
/* } */

void main(){
  int resize = 1024;
  int alignment = 1 << 12;
  int *ptr;
  int *ptr1;

  
  
  if ((ptr = aligned_alloc(alignment , sizeof(int))) == 0) {
    /* handle error */
    return;
  }
  
  
  /* ... */
  if ((ptr1 = realloc(ptr, resize)) == 0) { //@violation CHECK_ALIGNMENT_OF_MEMORY 
    /* handle error */
    return;
  }
  free(ptr1);
  return;

}

void pos39(){
  /* sock is a connected TCP socket */
  
  int num;
  
  if (recv(sock, (void *)&num, sizeof(uint32_t), 0) < 0) {
    return; 
  }

  /* num = ntohl(num); */

  printf("We received %u from the network!\n", (unsigned int)num); //@violation INFORMATION_LEAK
  return; //@violation USE_CORRECT_BYTE_ORDERING
}
