/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/crulcheck.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 120 "/usr/include/time.h"
struct timespec;
#line 67 "/usr/include/bits/pthreadtypes.h"
struct __pthread_internal_slist;
#line 96
union __T38869600;
#line 78
struct __pthread_mutex_s;
#line 77
union __T38868160;
#line 43 "/usr/include/bits/stat.h"
struct stat;
#line 201 "/usr/include/pthread.h"
enum __T39209320 {
PTHREAD_CANCEL_DEFERRED,

PTHREAD_CANCEL_ASYNCHRONOUS}; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 57 "/usr/include/bits/types.h"
typedef unsigned long long __u_quad_t;
#line 134 "/usr/include/bits/types.h"
typedef __u_quad_t __dev_t;
typedef unsigned __uid_t;
typedef unsigned __gid_t;
typedef unsigned long __ino_t;

typedef unsigned __mode_t;
typedef unsigned __nlink_t;
typedef long __off_t;
#line 149
typedef long __time_t;
#line 164
typedef long __blksize_t;




typedef long __blkcnt_t;
#line 180
typedef int __ssize_t;
#line 110 "/usr/include/sys/types.h"
typedef __ssize_t ssize_t;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 120 "/usr/include/time.h"
struct timespec {

__time_t tv_sec;
long tv_nsec;};
#line 67 "/usr/include/bits/pthreadtypes.h"
struct __pthread_internal_slist {

struct __pthread_internal_slist *__next;};
typedef struct __pthread_internal_slist __pthread_slist_t;
#line 96
union __T38869600 {
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
union __T38869600 __T38870240;};
#line 77
union __T38868160 {
#line 101
struct __pthread_mutex_s __data;
char __size[24];
long __align;};
typedef union __T38868160 pthread_mutex_t;
#line 43 "/usr/include/bits/stat.h"
struct stat {

__dev_t st_dev;

unsigned short __pad1;


__ino_t st_ino;




__mode_t st_mode;
__nlink_t st_nlink;




__uid_t st_uid;
__gid_t st_gid;



__dev_t st_rdev;

unsigned short __pad2;


__off_t st_size;



__blksize_t st_blksize;

__blkcnt_t st_blocks;
#line 88 "/usr/include/bits/stat.h"
struct timespec st_atim;
struct timespec st_mtim;
struct timespec st_ctim;
#line 106 "/usr/include/bits/stat.h"
unsigned long __unused4;
unsigned long __unused5;};
#line 263 "/usr/include/sys/stat.h"
extern int lstat(const char *__file, struct stat *__buf);
#line 363 "/usr/include/unistd.h"
extern ssize_t write(int __fd, const void *__buf, size_t __n);
#line 692 "/usr/include/unistd.h"
extern __uid_t getuid(void);
#line 717 "/usr/include/unistd.h"
extern int setuid(__uid_t __uid);
#line 727
extern int seteuid(__uid_t __uid);
#line 73 "/usr/include/fcntl.h"
extern int open(const char *__file, int __oflag, ...);
#line 10 "/home/kskyj/sparrow4/util/testcode/c/crulcheck.c"
extern void run_termnate();

extern int set_step_terminate();
extern int output();
#line 484 "/usr/include/pthread.h"
extern int pthread_setcanceltype(int __type, int *__oldtype);
#line 736 "/usr/include/pthread.h"
extern int pthread_mutex_lock(pthread_mutex_t *__mutex);
#line 339 "/usr/include/stdio.h"
extern int printf(const char *__format, ...);
#line 21 "/home/kskyj/sparrow4/util/testcode/c/crulcheck.c"
extern void *worker_thread(void *dummy);
#line 39
extern void ensure_privilege();
#line 55
extern char char_type();
#line 65
extern void parser(char *command);

extern int strtok();
#line 75
extern void linkFile(char *file);
#line 97
extern void foo();
#line 10 "/home/kskyj/sparrow4/util/testcode/c/crulcheck.c"
void run_termnate()
{
set_step_terminate();
output(("runnig .... ")); 

}
#line 21 "/home/kskyj/sparrow4/util/testcode/c/crulcheck.c"
void *worker_thread( void *__3591_27_dummy) {
auto int __3592_5_i;
auto int __3593_5_result;
auto pthread_mutex_t __3594_17_mutex = {{0,0U,0,0,0U,{0}}};
if ((__3593_5_result = (pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, (&__3592_5_i)))) != 0) {


}
while (1) {
if ((__3593_5_result = (pthread_mutex_lock((&__3594_17_mutex)))) != 0) {

}


}
return ((void *)0);
}

void ensure_privilege() {
if ((seteuid((getuid()))) != 0) {

}
if (1) {
if ((seteuid(0U)) != 0) {

}
}
if ((setuid((getuid()))) != 0) {

} 


}

char char_type() {
auto char __3626_9_a;
auto int __3627_8_b;
__3627_8_b = 25;
__3626_9_a = ((char)__3627_8_b);
printf(((const char *)"\342\200\234int = %d char = %d\n"), __3627_8_b, ((int)__3626_9_a));
return (char)__3627_8_b;

}

void parser( char *__3635_19_command) {
auto char *__3636_10_token;
__3636_10_token = ((char *)(strtok(__3635_19_command, ("-"))));
printf(((const char *)"\342\200\234%s\n"), __3636_10_token);
while (__3636_10_token = ((char *)(strtok(0, ("-"))))) {
printf(((const char *)"\342\200\234%s\n"), __3636_10_token);
}
printf(((const char *)"%s\n"), __3635_19_command); 
}

void linkFile( char *__3645_21_file) {
auto char *__3646_10_buf;
auto unsigned __3647_17_length;
auto struct stat __3648_16_lstat_info;
auto int __3649_8_fd;
if ((lstat(((const char *)__3645_21_file), (&__3648_16_lstat_info))) == (-1)) {

}
if (!(((__3648_16_lstat_info.st_mode) & 61440U) == 40960U)) {
__3649_8_fd = (open(((const char *)__3645_21_file), 0x2));
if (__3649_8_fd == (-1)) {

}
}
if (((unsigned)(write(__3649_8_fd, ((const void *)__3646_10_buf), __3647_17_length))) < __3647_17_length) {


} 
}



void foo() { 

}
