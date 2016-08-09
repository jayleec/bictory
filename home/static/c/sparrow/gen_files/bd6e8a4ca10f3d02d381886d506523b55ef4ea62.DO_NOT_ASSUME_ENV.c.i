/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_ASSUME_ENV.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 566 "/usr/include/stdlib.h"
extern char *getenv(const char *__name);
#line 127 "/usr/include/string.h"
extern char *strcpy(char *__dest, const char *__src);
#line 5 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_ASSUME_ENV.c"
extern void do_not_assume_env(); void do_not_assume_env() {
auto char __2050_8_path[9];
strcpy((__2050_8_path), ((const char *)(getenv(((const char *)"PATH"))))); 
}
