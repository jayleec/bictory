/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.MISSING_CALL_PARAM.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.MISSING_CALL_PARAM.c"
extern void memcpy_API11(const char *, const char *, unsigned);
extern unsigned strlen_API11(const char *);

extern void Func(const char *x, const char *y); void Func( const char *__10_24_x,  const char *__10_40_y) {
memcpy_API11(__10_24_x, __10_40_y, 1U);
memcpy_API11(__10_24_x, __10_40_y, (strlen_API11(__10_24_x))); 


}
