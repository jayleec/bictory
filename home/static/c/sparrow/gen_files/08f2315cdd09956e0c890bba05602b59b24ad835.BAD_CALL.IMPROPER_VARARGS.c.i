/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:51 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.IMPROPER_VARARGS.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.IMPROPER_VARARGS.c"
extern void Fun_API04_call(int, ...);

extern void Func(const char *x); void Func( const char *__9_24_x) {
auto int __10_6_p1; auto int __10_10_p2;
Fun_API04_call(1, __10_6_p1, __10_10_p2); 


}
