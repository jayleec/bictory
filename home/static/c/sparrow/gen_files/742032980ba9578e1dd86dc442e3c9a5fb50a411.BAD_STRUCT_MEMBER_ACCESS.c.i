/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRUCT_MEMBER_ACCESS.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRUCT_MEMBER_ACCESS.c"
struct st; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float; struct st {
int a;
int b;};


extern void Func(int x); void Func( int __12_15_x) {
auto struct st __13_12_obj;
auto int __14_6_a;
__14_6_a = (__13_12_obj.a);
__14_6_a = (__13_12_obj.a);
__14_6_a = (__13_12_obj.a); 
}
