/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.VARARGS.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.VARARGS.c"
extern void memcpy_API15(const char *, const char *);

extern void Func(const char *x); void Func( const char *__9_24_x) {
memcpy_API15(((const char *)"hardcoded"), ((const char *)"hardcoded")); 


}
