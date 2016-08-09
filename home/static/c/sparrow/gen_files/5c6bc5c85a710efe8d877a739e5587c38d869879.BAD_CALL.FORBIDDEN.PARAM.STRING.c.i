/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.PARAM.STRING.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 5 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.PARAM.STRING.c"
extern void memcpy_API09(const char *, const char *);

extern void Func(const char *x); void Func( const char *__11_24_x) {
memcpy_API09(__11_24_x, ((const char *)"hardcoded")); 


}
