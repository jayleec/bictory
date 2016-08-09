/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MALLOC.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_MALLOC.c"
typedef unsigned long wchar_t;

typedef unsigned size_t;


extern void *malloc(size_t);
extern size_t wcslen(const wchar_t *);
extern void free(void *);

extern void foo();
#line 19
extern void bar();
#line 25
extern void zoo();
#line 31
extern void coo();
#line 37
extern void tar();
#line 13
void foo() {
auto wchar_t __18_13_str1[20];
auto wchar_t *__19_14_str2; __19_14_str2 = ((wchar_t *)(malloc(((wcslen(((const wchar_t *)(__18_13_str1)))) + 1U))));
free(((void *)__19_14_str2)); 
}

void bar() {
auto wchar_t __24_13_str1[20];
auto wchar_t *__25_14_str2; __25_14_str2 = ((wchar_t *)(malloc((((wcslen(((const wchar_t *)(__24_13_str1)))) + 1U) * 4U))));
free(((void *)__25_14_str2)); 
}

void zoo() {
auto wchar_t __30_13_str1[20];
auto wchar_t *__31_14_str2; __31_14_str2 = ((wchar_t *)(malloc((((wcslen(((const wchar_t *)(__30_13_str1)))) + 1U) * 4U))));
free(((void *)__31_14_str2)); 
}

void coo() {
auto wchar_t __36_13_str1[20];
auto wchar_t *__37_14_str2; __37_14_str2 = ((wchar_t *)(malloc((((wcslen(((const wchar_t *)(__36_13_str1)))) + 1U) * 4U))));
free(((void *)__37_14_str2)); 
}

void tar() {
auto wchar_t *__42_11_str3; __42_11_str3 = ((wchar_t *)(malloc(50U)));
free(((void *)__42_11_str3)); 
}
