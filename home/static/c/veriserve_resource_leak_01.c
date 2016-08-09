#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int resource_leak_01_01_main(unsigned int size){

    char *p_str, *p_str1;
    char *p_strback, *p_strback1;

    p_str = malloc(size);
    if(p_str == 0)  return 1;
    p_strback = p_str;
    p_str1 = malloc(size);
    if(p_str1 == 0){
        free(p_str);
        return 2;
    }

    p_strback1 = p_str1;
    p_str = p_str1;

    free(p_strback1);
    return size;   //@violation LEAK.MEMORY
}

////////////////////////////////////////////////////////////////////////////////
int resource_leak_01_02_sub(const char *name, void **pf) {
  void *f = fopen(name, "r");
    if (!f) {
      return -1;
    }
    *pf = f;
    return 0;
}

int resource_leak_01_02_main(const char *name) {
    void *dummy;
    if (resource_leak_01_02_sub(name, &dummy) == -1) {
        fprintf(stderr, "Problem with: %s\n", name);
        return 0;
    }
    return 1;  //@violation LEAK.RESOURCE
}

////////////////////////////////////////////////////////////////////////////////
int resource_leak_01_03_main(unsigned int size){

    struct SRL0103 {
        char *p;
    } srl;

    srl.p = malloc(size);
    if(srl.p == 0)  return 1;

    if(size > 100){
        free(srl.p);
        return 2;
    }

    return size;   //@violation LEAK.MEMORY
}

