#include <stdlib.h>
#include <stdio.h>

struct RL04S2 {
    int i;
    long l;
    char c;
    char *pc;
};

struct RL04S1 {
    struct RL04S2 * ps2;
    int i;
    long l;
    char c;
};


extern int resource_leak_04_dummy(char *);

////////////////////////////////////////////////////////////////////////////////
char *resource_leak_04_01_sub(int size)
{
    char *p = malloc(size * 10);
    return p;
}

int resource_leak_04_01_main(int x, int y)
{
    if ( y == 0 ) return -1;
    else {
        char *p;
        p = resource_leak_04_01_sub(x + y);
        if ( p == 0 )
            return -1;
        if ( (x + y) > 50 ){
            p[50] = 0x00;
            resource_leak_04_dummy(p);
            free(p);
        }
    }       // defect (leak if (x+y)<=50)
    return 0; //@violation LEAK.MEMORY
}

////////////////////////////////////////////////////////////////////////////////
int resource_leak_04_02_main(int x, int y)
{
    struct RL04S1 rl04s1;
    if( x <= 0 )
        return -1;
    
    rl04s1.ps2 = malloc(sizeof(struct RL04S2));
    if (rl04s1.ps2 == 0)
        return -2;
    
    rl04s1.ps2->pc =malloc(x);
    if (rl04s1.ps2->pc == 0 ){
        free(rl04s1.ps2);
        return -3;
    }
    //
    free(rl04s1.ps2);
    return 0;  //@violation LEAK.MEMORY
    // defect (leak rl04s1.ps2->pc)
}

