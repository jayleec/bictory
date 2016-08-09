#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void check_assign(){
size_t resize = 1024;
size_t alignment = 1 << 12;
int *ptr;
int *ptr1;
if ((ptr = aligned_alloc(alignment , sizeof(int))) == NULL) {
/* handle error */
}
if ((ptr1 = realloc(ptr, resize)) == NULL) {  // CHECK_ALIGNMENT_OF_MEMORY
/* handle error */
}
}



