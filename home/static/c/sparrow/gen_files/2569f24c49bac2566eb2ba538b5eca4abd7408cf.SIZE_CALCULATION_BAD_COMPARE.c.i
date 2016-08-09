/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/SIZE_CALCULATION_BAD_COMPARE.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 471 "/usr/include/stdlib.h"
extern void *malloc(size_t __size);
#line 4 "/home/kskyj/sparrow4/util/testcode/c/SIZE_CALCULATION_BAD_COMPARE.c"
extern int getuid();


extern int geteuid();


extern void func();
#line 16
extern void function(int length);
#line 4
int getuid() {
return 0;
}
int geteuid() {
return 0;
}
void func() {
if ((getuid == ((int (*)())0)) || (geteuid == ((int (*)())0))) {

} 
}

void function( int __2060_20_length) {
auto double *__2061_14_p;
__2061_14_p = ((double *)(malloc((((unsigned)__2060_20_length) * 4U)))); 
}
