
/*	stdio.h 등의 system function 더미	-------------------------------	*/
#ifndef __cplusplus
typedef int wchar_t;
#endif
void * malloc(int size);
void * realloc(char * dest, int size);
int strcmp(char * left, char * rignt);
int strlen(char * temp);
int wcscmp(wchar_t * left, wchar_t * right);
int wcslen(wchar_t * temp);


/*	CERT_SCS_ARR31_C	-------------------------------	*/
extern int CERT_SCS_ARR31_C_int;
int * CERT_SCS_ARR31_C_int_pointer;		//	alarm
extern int CERT_SCS_ARR31_C_int_arr[];
//extern int * CERT_SCS_ARR31_C_int_dupl;

