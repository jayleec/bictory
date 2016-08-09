/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/SIG30.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 84 "/usr/include/signal.h"
typedef void (*__sighandler_t)(int);
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 101 "/usr/include/signal.h"
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
#line 333 "/usr/include/stdio.h"
extern int fprintf(FILE *__stream, const char *__format, ...);
#line 471 "/usr/include/stdlib.h"
extern void *malloc(size_t __size);
#line 488
extern void free(void *__ptr);
#line 8 "/home/kskyj/sparrow4/util/testcode/c/SIG30.c"
extern void log_message(void);



extern void handler(int signum);
#line 18
extern int SIG_main(void);
#line 147 "/usr/include/stdio.h"
extern struct _IO_FILE *stderr;
#line 6 "/home/kskyj/sparrow4/util/testcode/c/SIG30.c"
extern char *info; char *info = ((char *)0);

void log_message(void) {
fprintf(stderr, ((const char *)info)); 
}

void handler( int __2402_18_signum) {
log_message();
free(((void *)info));
info = ((char *)0); 
}

int SIG_main(void) {
if ((signal(2, handler)) == ((__sighandler_t)4294967295U)) {

}
info = ((char *)(malloc(1024U)));
if (info == ((char *)0)) {

}

while (1) {


log_message();


}
return 0;
}
