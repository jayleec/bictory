#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Pair { char *x; char *y; } S_RL03;
extern int g_num;

extern int resource_leak_03_dummy();
extern char * resource_leak_03_gp;

////////////////////////////////////////////////////////////////////////////////
S_RL03 *resource_leak_03_01_sub(char *x, char *y)
{
    S_RL03 *p = (S_RL03 *)malloc(sizeof(S_RL03));
    if(p == 0) { free(x); return 0;}
    p->x = x;
    return p;
}

S_RL03 *resource_leak_03_01_main(int n)
{
    char *p = (char *)malloc(n);
    char *q = (char *)malloc(n);
    return resource_leak_03_01_sub(p,q);  //@violation LEAK.MEMORY
    // defect : leak of q
}

////////////////////////////////////////////////////////////////////////////////
int resource_leak_03_02_main()
{
    int i;
    int *p = (int *)malloc(sizeof(int)*100);

    for (i=0; i<=10; i++) {
        if (g_num < i) {
            free(p);  
            return 0;
        }
    }
    return 1; //@violation LEAK.MEMORY
    // defect : leak of p when g_num is larger than 10
}

////////////////////////////////////////////////////////////////////////////////
void resource_leak_03_03_sub2(char *p)
{
    memcpy(p,"a",1);
    printf("%c",p[0]);
}

char *resource_leak_03_03_sub(int size, int flag)
{
    int result;
    char *p;
    if (flag == 9){
        resource_leak_03_dummy();
        return 0;
    }
    p = malloc(size);
    if (p == 0) return 0;
    result = resource_leak_03_dummy();
    if (result == 1){
        free(p);
        return 0;
    }
    
    return p;
}

int resource_leak_03_03_main(int n)
{
    int size = 100;
    int x;
    char *p;
    if ( n == 9 ) {
        size = resource_leak_03_dummy();
    }

    p = resource_leak_03_03_sub(size,n);
    if ( p == 0 ) return -1;

    x = resource_leak_03_dummy();
    if ( x == 3 ){
        resource_leak_03_03_sub2(p);
        return -2;  //@violation LEAK.MEMORY
    }
    free(p);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void resource_leak_03_04_sub2(char *p)
{
    memcpy(p,"a",1);
    printf("%c",p[0]);
}

char *resource_leak_03_04_sub(int size, int flag)
{
    int result;
    char *p;
    if (flag == 9){
        return 0;
    }
    p = malloc(size);
    if (p == 0) return 0;
    return p;
}

int resource_leak_03_04_main(int n)
{
    int size = 100;
    if ( n == 9 ) {
        size = resource_leak_03_dummy();
    }
    resource_leak_03_gp = 0;

    resource_leak_03_gp = resource_leak_03_04_sub(size,n); // alloc
    if ( resource_leak_03_gp == 0 ) return -1;

    if ( n == 3 ){
        resource_leak_03_04_sub2(resource_leak_03_gp);
        resource_leak_03_gp = malloc(size);  // defect (overwrite pointer)
        return 1;
    }
    free(resource_leak_03_gp);
    return 0;
}






