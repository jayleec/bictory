/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:58 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.TYPE_MISMATCH.SPRINTF.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 341 "/usr/include/stdio.h"
extern int sprintf(char *__s, const char *__format, ...);
#line 5 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.TYPE_MISMATCH.SPRINTF.c"
extern void func(); void func() {
auto char __842_7_dest[100];
auto char __843_7_src1[100];
auto char __844_7_src2[100];
sprintf((__842_7_dest), ((const char *)"%50s%100s"), (__843_7_src1), (__844_7_src2)); 
}
