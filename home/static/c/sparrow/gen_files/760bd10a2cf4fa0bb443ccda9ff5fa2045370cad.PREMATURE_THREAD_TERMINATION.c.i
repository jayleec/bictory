/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/PREMATURE_THREAD_TERMINATION.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/PREMATURE_THREAD_TERMINATION.c"
typedef unsigned pthread_t;


extern int pthread_create(pthread_t *, void *, void *(*)(void *), void *);

extern void *foo(void *data);



extern int foo2();
#line 9
void *foo( void *__13_19_data) {
return __13_19_data;
}

int foo2() {
auto pthread_t __18_12_pth;
auto int __19_6_a = 1;

if ((pthread_create((&__18_12_pth), ((void *)0), foo, ((void *)(&__19_6_a)))) < 0) {

}

return 0;
}
