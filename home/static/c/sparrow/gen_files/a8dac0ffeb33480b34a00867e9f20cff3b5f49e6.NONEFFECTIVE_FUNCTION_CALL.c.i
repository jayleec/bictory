/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/NONEFFECTIVE_FUNCTION_CALL.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 64 "/usr/include/string.h"
extern void *memset(void *__s, int __c, size_t __n);
#line 4 "/home/kskyj/sparrow4/util/testcode/c/NONEFFECTIVE_FUNCTION_CALL.c"
extern void noneffect(); void noneffect() {
auto char __2052_9_buf[10];
memset(((void *)(__2052_9_buf)), 10, 0U); 
}
