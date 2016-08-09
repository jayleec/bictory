#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
int null_deref_01_01_main(char * pstr) 
{
    if( pstr == 0) ;
    pstr[0] = 'a'; //@violation NULL_DEREF.MISSING_CHECK defect
    return 0;
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_01_02_sub(char *p)
{
    p[0] = 'a'; //defect
}

void null_deref_01_02_main()
{
    char *p = 0;
    null_deref_01_02_sub(p); //@violation NULL_DEREF  
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_01_03_03(char *p)
{
    p[0] = 'a'; // defect
}

void null_deref_01_03_02(char *p)
{
    null_deref_01_03_03(p);
}

void null_deref_01_03_01(char *p)
{
    null_deref_01_03_02(p);
}

void null_deref_01_03_main()
{
    char *p = 0;
    null_deref_01_03_01(p); //@violation NULL_DEREF
}


////////////////////////////////////////////////////////////////////////////////
void null_deref_01_04_sub(char *p)
{
    p[0] = 'a'; // defect( if i is 0 )
}

void null_deref_01_04_main(int i)
{
    char *p = 0;
    char buf[10];
    memset(buf,0,sizeof(buf));
    
    if(i){
        p = buf;
    } else {
        ;
    }
    
    null_deref_01_04_sub(p); //@violation NULL_DEREF
}

