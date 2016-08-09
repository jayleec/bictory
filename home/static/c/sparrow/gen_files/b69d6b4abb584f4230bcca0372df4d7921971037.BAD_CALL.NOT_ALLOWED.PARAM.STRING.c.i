/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.NOT_ALLOWED.PARAM.STRING.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.NOT_ALLOWED.PARAM.STRING.c"
extern void memcpy_API02(const char *, const char *);

extern void Func(const char *x, const char *y); void Func( const char *__9_24_x,  const char *__9_40_y) {
memcpy_API02(__9_24_x, __9_40_y); 


}
