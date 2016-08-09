# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MALLOC.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MALLOC.c"



typedef unsigned long wchar_t;
typedef wchar_t WCHAR;
typedef unsigned int size_t;


void * malloc(size_t);
size_t wcslen(const wchar_t *);
void free(void *);

void foo(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc(wcslen(str1) + 1);
    free(str2);
}

void bar(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc((wcslen(str1) + 1) * sizeof(wchar_t));
    free(str2);
}

void zoo(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc((wcslen(str1) + 1) * sizeof(WCHAR));
    free(str2);
}

void coo(){
    wchar_t str1[20];
    wchar_t *str2 = (wchar_t *)malloc((wcslen(str1) + 1) * sizeof(size_t));
    free(str2);
}

void tar(){
 wchar_t *str3 = (wchar_t *)malloc(50);
 free(str3);
}
