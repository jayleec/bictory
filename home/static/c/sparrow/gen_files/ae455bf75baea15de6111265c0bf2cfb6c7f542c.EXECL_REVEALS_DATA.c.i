/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/EXECL_REVEALS_DATA.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 566 "/usr/include/stdlib.h"
extern char *getenv(const char *__name);
#line 568 "/usr/include/unistd.h"
extern int execl(const char *__path, const char *__arg, ...);
#line 6 "/home/kskyj/sparrow4/util/testcode/c/EXECL_REVEALS_DATA.c"
extern void execl_error(); void execl_error() {
(void)(execl(((const char *)"login"), ((const char *)"-p"), ("-d"), ("-h"), ("-s"), (getenv(((const char *)"USER"))), 0)); 

}
