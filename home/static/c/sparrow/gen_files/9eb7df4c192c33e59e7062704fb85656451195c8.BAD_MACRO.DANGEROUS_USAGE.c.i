/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.DANGEROUS_USAGE.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 5 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.DANGEROUS_USAGE.c"
extern void dangerous_macro_usage(); void dangerous_macro_usage() {
auto int __10_6_b = 3;
auto int __11_6_c; __11_6_c = (24 * (__10_6_b * __10_6_b)); 
}
