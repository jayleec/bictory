/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:51 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.TYPE_MISMATCH.STRING.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.TYPE_MISMATCH.STRING.c"
typedef unsigned size_t;


extern void wcsncpy(void *, void *, size_t);

extern void func(); void func() {
auto char __14_7_str1[6] = "Hello";
auto char __15_7_str2[6] = "00000";
wcsncpy(((void *)(__15_7_str2)), ((void *)(__14_7_str1)), 5U); 
}
