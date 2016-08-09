#include <stdio.h>

// Dummy function
char * malloc(int size) {
	return NULL;
}

static int badCount = 100;  		/*  Violation : unused static variable */
 
char * mis04_1(void) 
{
    char *ptr_tmp = NULL;
    ptr_tmp = malloc(100);
    
    /* do something */
    
    return ptr_tmp;
}

static int badCount2 = 100;  		/*  Violation : unused static variable */
 
char * mis04_2(void) 
{
    char *ptr_tmp = NULL;
	badCount2 = badCount2 + 20;
    ptr_tmp = malloc(100);
    
    /* do something */
    
    return ptr_tmp;
}

static int goodCount = 100;

char * goodFoo(void)
{
    char *ptr_tmp = NULL;
    ptr_tmp = malloc(goodCount);
    
    /* do something */
    
    return ptr_tmp;
}
