/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.REPLACE_SECURE_FUNCTIONS.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 6 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.REPLACE_SECURE_FUNCTIONS.c"
typedef int FILE;
extern FILE *fopen(const char *filename, const char *mode);

extern void func(); void func() {

auto FILE *__15_9_a;
__15_9_a = (fopen(((const char *)"file"), ((const char *)"a"))); 
}
