/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:53 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.PARAM.LITERAL.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.PARAM.LITERAL.c"
extern void memset_API13(const char *, unsigned, unsigned);

extern void Func(const char *x); void Func( const char *__9_24_x) {
memset_API13(((const char *)"hardcoded"), 0U, 9U); 


}
