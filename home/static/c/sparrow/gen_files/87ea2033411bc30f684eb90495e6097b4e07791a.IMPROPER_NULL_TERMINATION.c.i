/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/IMPROPER_NULL_TERMINATION.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 339 "/usr/include/stdio.h"
extern int printf(const char *__format, ...);
#line 64 "/usr/include/string.h"
extern void *memset(void *__s, int __c, size_t __n);
#line 127 "/usr/include/string.h"
extern char *strcpy(char *__dest, const char *__src);


extern char *strncpy(char *__dest, const char *__src, size_t __n);
#line 397 "/usr/include/string.h"
extern size_t strlen(const char *__s);
#line 14 "/home/kskyj/sparrow4/util/testcode/c/IMPROPER_NULL_TERMINATION.c"
extern void foo1(char *source);
#line 22
extern void foo2(char *source);
#line 30
extern void bar1(char *source);
#line 37
extern void bar2(char *source);
#line 53
extern void xman();
#line 14
void foo1( char *__2049_17_source) {
auto char __2050_8_ntbs[5];
((__2050_8_ntbs)[4U]) = ((char)0);

strncpy((__2050_8_ntbs), ((const char *)__2049_17_source), 5U);
printf(((const char *)"foo1: %s\n"), (__2050_8_ntbs)); 
}

void foo2( char *__2057_17_source) {
auto char __2058_8_ntbs[5];

memset(((void *)(__2058_8_ntbs)), 0, 4U);
strncpy((__2058_8_ntbs), ((const char *)__2057_17_source), 4U);
printf(((const char *)"foo2: %s\n"), (__2058_8_ntbs)); 
}

void bar1( char *__2065_17_source) {
auto char __2066_8_ntbs[5];
strncpy((__2066_8_ntbs), ((const char *)__2065_17_source), 4U);
((__2066_8_ntbs)[4U]) = ((char)0);
printf(((const char *)"bar1: %s\n"), (__2066_8_ntbs)); 
}

void bar2( char *__2072_17_source) {
auto char __2073_8_ntbs[5];

if (__2072_17_source) {
if ((strlen(((const char *)__2072_17_source))) < 5U) {
strcpy((__2073_8_ntbs), ((const char *)__2072_17_source));
}
else  {

}
} else  {

}
printf(((const char *)"bar2: %s\n"), (__2073_8_ntbs)); 
}

void xman() {
auto char *__2089_9_a = "aa";
auto char *__2090_9_b = "123456789";
foo1(__2089_9_a);
foo1(__2090_9_b);
foo2(__2089_9_a);
foo2(__2090_9_b);
bar1(__2089_9_a);
bar1(__2090_9_b);
bar2(__2089_9_a);
bar2(__2090_9_b); 
}
