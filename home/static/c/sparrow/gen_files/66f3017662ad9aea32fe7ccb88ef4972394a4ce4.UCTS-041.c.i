/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/UCTS-041.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 143 "/usr/include/bits/types.h"
typedef int __pid_t;
#line 100 "/usr/include/sys/types.h"
typedef __pid_t pid_t;
#line 612 "/usr/include/stdio.h"
extern char *gets(char *__s);
#line 7 "/home/kskyj/sparrow4/util/testcode/c/UCTS-041.c"
extern pid_t vfork();

extern void f(); void f() {
auto char __1797_7_buf[100];

auto pid_t __1799_8_pid;
#line 11
gets((__1797_7_buf));
__1799_8_pid = (vfork()); 
}
