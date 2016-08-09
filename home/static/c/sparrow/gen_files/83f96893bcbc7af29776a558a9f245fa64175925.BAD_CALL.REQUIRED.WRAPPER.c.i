/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.WRAPPER.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.WRAPPER.c"
extern int API06_NEED_WRAPPER(int);
extern int API06_WRAPPER(int);

extern void Func(const char *x); void Func( const char *__11_24_x) {
auto int __12_6_a;
auto int __13_6_b;
#line 8
__12_6_a = (API06_NEED_WRAPPER(0));
__13_6_b = (API06_WRAPPER((API06_NEED_WRAPPER(0)))); 
}
