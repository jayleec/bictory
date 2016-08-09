/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:58 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/FORBIDDEN_CALL.LOOP.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/FORBIDDEN_CALL.LOOP.c"
extern void FCINLOOP_SUB(int);

extern void Func(int x); void Func( int __10_15_x) {
auto int __11_6_a;
for (__11_6_a = 0; (__11_6_a < __10_15_x); __11_6_a++) {
FCINLOOP_SUB(__11_6_a);
} 
}
