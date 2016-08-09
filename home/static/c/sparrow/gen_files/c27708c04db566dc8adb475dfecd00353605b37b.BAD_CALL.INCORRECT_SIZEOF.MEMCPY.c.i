/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.INCORRECT_SIZEOF.MEMCPY.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.INCORRECT_SIZEOF.MEMCPY.c"
extern void memcpy(const char *, const char *, int);

extern void foo(); void foo() {
auto char __11_7_a[100];
auto char __12_7_b[100];
auto int *__13_8_ref; __13_8_ref = ((int *)(__11_7_a));

memcpy(((const char *)(__11_7_a)), ((const char *)(__12_7_b)), 4);
memcpy(((const char *)(__11_7_a)), ((const char *)(__12_7_b)), 4); 
}
