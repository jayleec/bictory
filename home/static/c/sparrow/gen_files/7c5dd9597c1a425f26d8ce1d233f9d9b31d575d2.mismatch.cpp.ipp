/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/mismatch.cpp"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t; extern void *_Znwj(unsigned); extern void _ZdlPv(void *); extern void *_Znaj(unsigned); extern void _ZdaPv(void *);
#line 51 "/usr/include/malloc.h"
extern void *malloc(size_t __size);
#line 66
extern void free(void *__ptr);
#line 6 "/home/kskyj/sparrow4/util/testcode/c/mismatch.cpp"
extern void _Z25mismatch_malloc_to_deletev(void);
#line 13
extern void _Z31mismatch_malloc_to_delete_arrayv(void);
#line 20
extern void _Z28mismatch_new_array_to_deletev(void);
#line 27
extern void _Z26mismatch_new_array_to_freev(void);
#line 34
extern void _Z28mismatch_new_to_delete_arrayv(void);
#line 41
extern void _Z20mismatch_new_to_freev(void);
#line 6
void _Z25mismatch_malloc_to_deletev(void) {
auto char *__2690_7_p; __2690_7_p = ((char *)(malloc(10U)));

_ZdlPv(((void *)__2690_7_p)); 
}


void _Z31mismatch_malloc_to_delete_arrayv(void) {
auto char *__2697_7_p; __2697_7_p = ((char *)(malloc(10U)));

_ZdaPv(((void *)__2697_7_p)); 
}


void _Z28mismatch_new_array_to_deletev(void) {
auto char *__2704_7_p; __2704_7_p = ((char *)(_Znaj(8U)));

_ZdlPv(((void *)__2704_7_p)); 
}


void _Z26mismatch_new_array_to_freev(void) {
auto char *__2711_7_p; __2711_7_p = ((char *)(_Znaj(8U)));

free(((void *)__2711_7_p)); 
}


void _Z28mismatch_new_to_delete_arrayv(void) {
auto char *__2718_7_p; __2718_7_p = ((char *)(_Znwj(1U)));

_ZdaPv(((void *)__2718_7_p)); 
}


void _Z20mismatch_new_to_freev(void) {
auto char *__2725_7_p; __2725_7_p = ((char *)(_Znwj(1U)));

free(((void *)__2725_7_p)); 
}
