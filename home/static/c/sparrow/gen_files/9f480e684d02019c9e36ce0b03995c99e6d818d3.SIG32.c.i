/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/SIG32.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 30 "/usr/include/bits/sigset.h"
struct __T42753720;
#line 35 "/usr/include/setjmp.h"
struct __jmp_buf_tag;
#line 5 "/home/kskyj/sparrow4/util/testcode/c/SIG32.c"
enum __T43107720 { MAXLINE = 1024}; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 34 "/usr/include/bits/setjmp.h"
typedef int __jmp_buf[6];
#line 30 "/usr/include/bits/sigset.h"
struct __T42753720 {
unsigned long __val[32];};
typedef struct __T42753720 __sigset_t;
#line 35 "/usr/include/setjmp.h"
struct __jmp_buf_tag {
#line 41
__jmp_buf __jmpbuf;
int __mask_was_saved;
__sigset_t __saved_mask;};
#line 49
typedef struct __jmp_buf_tag jmp_buf[1];
#line 84 "/usr/include/signal.h"
typedef void (*__sighandler_t)(int);
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 65 "/usr/include/setjmp.h"
extern int _setjmp(struct __jmp_buf_tag *__env);
#line 82 "/usr/include/setjmp.h"
extern void longjmp(struct __jmp_buf_tag *__env, int __val);
#line 101 "/usr/include/signal.h"
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
#line 8 "/home/kskyj/sparrow4/util/testcode/c/SIG32.c"
extern void handler(int signum);



extern void log_message(char *info1, char *info2);
#line 34 "/home/kskyj/sparrow4/util/testcode/c/SIG32.c"
extern int SIG32_main(void);
#line 6 "/home/kskyj/sparrow4/util/testcode/c/SIG32.c"
static jmp_buf env;

void handler( int __1772_18_signum) {
longjmp(env, 1); 
}

void log_message( char *__1776_24_info1,  char *__1776_37_info2) {
static char *__1777_16_buf = ((char *)0);
static size_t __1778_17_bufsize;
auto char __1779_8_buf0[1024];

if (__1777_16_buf == ((char *)0)) {
__1777_16_buf = (__1779_8_buf0);
__1778_17_bufsize = 1024U;
}
#line 29 "/home/kskyj/sparrow4/util/testcode/c/SIG32.c"
if (__1777_16_buf == (__1779_8_buf0)) {
__1777_16_buf = ((char *)0);
} 
}

int SIG32_main(void) {



auto char *__1795_9_info1;
auto char *__1796_9_info2;
#line 35
if ((signal(2, handler)) == ((__sighandler_t)4294967295U)) {

}
#line 43
if ((_setjmp(env)) == 0) {
while (1) {

log_message(__1795_9_info1, __1796_9_info2);

}
}
else  {
log_message(__1795_9_info1, __1796_9_info2);
}

return 0;
}
