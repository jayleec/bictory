/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/UNBOUNDED_SOURCE_TO_ARRAY.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 135 "/usr/include/string.h"
extern char *strcat(char *__dest, const char *__src);
#line 339 "/usr/include/stdio.h"
extern int printf(const char *__format, ...);
#line 3 "/home/kskyj/sparrow4/util/testcode/c/UNBOUNDED_SOURCE_TO_ARRAY.c"
extern int main(int argc, char **argv); int main( int __1096_14_argc,  char **__1096_26_argv) {
auto char __1097_8_cmdline[4096];
auto int __1098_7_i;
((__1097_8_cmdline)[0]) = ((char)0);

for (__1098_7_i = 1; (__1098_7_i < __1096_14_argc); ++__1098_7_i) {
strcat((__1097_8_cmdline), ((const char *)(__1096_26_argv[__1098_7_i])));
strcat((__1097_8_cmdline), ((const char *)" "));
}
printf(((const char *)"Debug Info"));
return 0;
}
