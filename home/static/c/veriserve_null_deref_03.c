#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
int null_deref_03_01_main() {

    char *** ppp = 0; 
    *** ppp = 'a';   //@violation NULL_DEREF defect
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int null_deref_03_02_main() {

    char ** pp = 0;
    char *** ppp = &pp;
    *** ppp = 'a';       //@violation NULL_DEREF defect
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int null_deref_03_03_main() {

    char * p = 0;
    char ** pp = &p;
    char *** ppp = &pp;
    *** ppp = 'a';       //@violation NULL_DEREF defect
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int null_deref_03_04_main(char *ptr) {

    char * p = ptr;
    char ** pp = &p;
    char *** ppp = &pp;
    if ( p == 0 ) ;
    *** ppp = 'a';       //@violation NULL_DEREF.MISSING_CHECK defect
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
int null_deref_03_05_main(char *** ppp) 
{
    if( ppp == 0) return 0;
    if( *ppp == 0) return 0;
    if( **ppp == 0 ) ;
    (**ppp)[0] = 'a'; // defect
    return 0;
}

#if 0
////////////////////////////////////////////////////////////////////////////////
void null_deref_03_05_sub(char **p)
{
    **p = 'a'; // defect
}

void null_deref_03_05_main()
{
    char *p = 0;
    null_deref_03_05_sub(&p); //@violation NULL_DEREF
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_03_06_03(char **p)
{
    **p = 'a'; // defect
}

void null_deref_03_06_02(char **p)
{
    null_deref_03_06_03(p);
}

void null_deref_03_06_01(char **p)
{
    null_deref_03_06_02(p);
}

void null_deref_03_06_main()
{
    char *p = 0;
    null_deref_03_06_01(&p); //@violation NULL_DEREF
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_03_07_sub(char **p)
{
    **p = 'a'; // defect( if i is 0 )
}

void null_deref_03_07_main(int i)
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
    
    null_deref_03_07_sub(p); //@violation NULL_DEREF
}
#endif
