/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.RESOURCE.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.RESOURCE.c"
struct rlimit; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float; struct rlimit {
int a;
int b;};



extern void getrlimit_FB09(int, struct rlimit *);

extern void resource_limit(); void resource_limit() {
auto struct rlimit __17_16_rlim;
getrlimit_FB09(4354, (&__17_16_rlim)); 
}
