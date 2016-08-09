#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
////////////////////////////////////////////////////////////////////
void mismatch_malloc_to_delete(){
char *p = (char*)malloc(10);
/*some codes here*/
delete p;  
}

//////////////////////////////////////////////////////////////////////
void mismatch_malloc_to_delete_array(){
char *p = (char*)malloc(10);
/*some codes here*/
delete []p;  
}

//////////////////////////////////////////////////////////////////////
void mismatch_new_array_to_delete(){
char *p = new char[8];
/*some codes here*/
delete p;  
}

//////////////////////////////////////////////////////////////////////
void mismatch_new_array_to_free(){
char *p = new char[8];
/*some codes here*/
free(p);  
}

//////////////////////////////////////////////////////////////////////
void mismatch_new_to_delete_array(){
char *p = new char;
/*some codes here*/
delete []p;  
}

//////////////////////////////////////////////////////////////////////
void mismatch_new_to_free(){
char *p = new char;
/*some codes here*/
free(p);  
}
