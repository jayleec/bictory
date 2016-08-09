/* CERT EXP32-C Do not access a volatile object through a nonvolatile reference.*/
#include <stdio.h>

static volatile int **ipp;
static int *ip;
static volatile int i = 0;
 
void foo(){
	printf("i = %d.\n", i);
	 
	ipp = &ip; //@violation	BAD_ACCESS_VOLATILE_OBJ
	ipp = (int**) &ip; //@violation	BAD_ACCESS_VOLATILE_OBJ
	*ipp = &i; /* valid */
	if (*ip != 0) { /* valid */
	  /* ... */
	}
}