/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/ENV04.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 363 "/usr/include/stdio.h"
extern int snprintf(char *__s, size_t __maxlen, const char *__format, ...);
#line 819 "/usr/include/stdio.h"
extern void perror(const char *__s);
#line 712 "/usr/include/stdlib.h"
extern int system(const char *__command);
#line 4 "/home/kskyj/sparrow4/util/testcode/c/ENV04.c"
extern int useruser(); int useruser() {
auto char *__1792_8_input = ((char *)0);



auto char __1796_7_cmdbuf[512];
auto int __1797_6_len_wanted; __1797_6_len_wanted = (snprintf((__1796_7_cmdbuf), 512U, ((const char *)"any_cmd \'%s\'"), __1792_8_input));


if (((unsigned)__1797_6_len_wanted) >= 512U) {
perror(((const char *)"Input too long"));
}
else  if (__1797_6_len_wanted < 0) {
perror(((const char *)"Encoding error"));
}
else  if ((system(((const char *)(__1796_7_cmdbuf)))) == (-1)) {
perror(((const char *)"Error executing input"));
} 

}
