#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
int null_deref_02_01_main() {

    char ** pp = 0;
    ** pp = 'a'; //@violation NULL_DEREF defect
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int null_deref_02_02_main() {

    char * p = 0;
    char ** pp = &p;
    ** pp = 'a'; //@violation NULL_DEREF defect 
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int null_deref_02_03_main(char *ptr) {

    char * p = ptr;
    char ** pp = &p;

    if ( p == 0 ) ;
    ** pp = 'a'; //@violation NULL_DEREF.MISSING_CHECK defect
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int null_deref_02_04_main(char ** pstr) 
{
    if( pstr == 0) return 0;
    if( *pstr == 0 ) ;
    (*pstr)[0] = 'a'; //@violation NULL_DEREF.MISSING_CHECK defect
    return 0;
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_02_05_sub(char **p)
{
    **p = 'a'; // defect
}

void null_deref_02_05_main()
{
    char *p = 0;
    null_deref_02_05_sub(&p); //@violation NULL_DEREF
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_02_06_03(char **p)
{
    **p = 'a'; // defect
}

void null_deref_02_06_02(char **p)
{
    null_deref_02_06_03(p);
}

void null_deref_02_06_01(char **p)
{
    null_deref_02_06_02(p);
}

void null_deref_02_06_main()
{
    char *p = 0;
    null_deref_02_06_01(&p); //@violation NULL_DEREF
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_02_07_sub(char **p)
{
    **p = 'a'; // defect( if i is 0 )
}

void null_deref_02_07_main(int i)
{
    char **p = 0;
    char *ptr = 0;
    char buf[10];
    memset(buf,0,sizeof(buf));
    ptr = buf;
    if(i){
        p = &ptr;
    } else {
        ;
    }
    
    null_deref_02_07_sub(p); //@violation NULL_DEREF
}

