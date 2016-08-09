#include <stdio.h>
#include <memory.h>
#include <string.h>

void* aux_test_extreme(int* buf, char n) {
    buf[n+2] = 0;
}

void test_extreme() {
    char* a;

    a = malloc(12);
    aux_test_extreme(a+8, 4); // bug, O, O
    free(a);
}

int test_strcpy_dyn()
{
    char* dest;
    char buf[20];
    char buf2[9];
    dest = (char*)malloc(10);
    strcpy(dest, buf);
    strcpy(dest, buf2);
    free(dest);
    return 0;
}
