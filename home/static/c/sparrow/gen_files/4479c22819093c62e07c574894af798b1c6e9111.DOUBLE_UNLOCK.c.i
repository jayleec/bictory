/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/DOUBLE_UNLOCK.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE;
#line 67 "/usr/include/bits/pthreadtypes.h"
struct __pthread_internal_slist;
#line 96
union __T42508424;
#line 78
struct __pthread_mutex_s;
#line 77
union __T42507000; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 67 "/usr/include/bits/pthreadtypes.h"
struct __pthread_internal_slist {

struct __pthread_internal_slist *__next;};
typedef struct __pthread_internal_slist __pthread_slist_t;
#line 96
union __T42508424 {
int __spins;
__pthread_slist_t __list;};
#line 78
struct __pthread_mutex_s {

int __lock;
unsigned __count;
int __owner;
#line 88
int __kind;
#line 94
unsigned __nusers;
union __T42508424 __T42509104;};
#line 77
union __T42507000 {
#line 101
struct __pthread_mutex_s __data;
char __size[24];
long __align;};
typedef union __T42507000 pthread_mutex_t;
#line 249 "/usr/include/stdio.h"
extern FILE *fopen(const char *__filename, const char *__modes);
#line 688 "/usr/include/stdio.h"
extern size_t fwrite(const void *__ptr, size_t __size, size_t __n, FILE *__s);
#line 736 "/usr/include/pthread.h"
extern int pthread_mutex_lock(pthread_mutex_t *__mutex);
#line 747
extern int pthread_mutex_unlock(pthread_mutex_t *__mutex);
#line 5 "/home/kskyj/sparrow4/util/testcode/c/DOUBLE_UNLOCK.c"
extern void unlock();
#line 11
extern int some_error();
#line 5
void unlock() {
auto pthread_mutex_t __2873_17_mutex = {{0,0U,0,0,0U,{0}}};
auto FILE *__2874_7_fp;
auto char __2875_6_buf[10] = "error";
__2874_7_fp = (fopen(((const char *)"filename"), ((const char *)"w")));
pthread_mutex_lock((&__2873_17_mutex));
if (some_error()) {
fwrite(((const void *)(__2875_6_buf)), 1U, 10U, __2874_7_fp);
pthread_mutex_unlock((&__2873_17_mutex));
}
pthread_mutex_unlock((&__2873_17_mutex)); 
}
