/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.LIBRARY.MEMORY.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.LIBRARY.MEMORY.c"
typedef unsigned size_t;


extern void *malloc_FB06(void *, size_t);
extern void realloc_FB06();

extern void memory(char *buf); void memory( char *__14_20_buf) {
__14_20_buf = ((char *)(malloc_FB06(((void *)__14_20_buf), 40U)));
realloc_FB06(); 

}
