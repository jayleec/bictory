# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.LIBRARY.MEMORY.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.LIBRARY.MEMORY.c"



typedef unsigned int size_t;


void * malloc_FB06(void *, size_t);
void realloc_FB06();

void memory(char * buf){
 buf = (char *)malloc_FB06(buf, sizeof(char *) * 10);
 realloc_FB06();

}
