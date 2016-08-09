/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:51 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/MSC34.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 214 "/usr/include/stdio.h"
extern int fclose(FILE *__stream);
#line 249 "/usr/include/stdio.h"
extern FILE *fopen(const char *__filename, const char *__modes);
#line 4 "/home/kskyj/sparrow4/util/testcode/c/MSC34.c"
extern int MSC32_main(); int MSC32_main() {
auto FILE *__1792_9_fp; __1792_9_fp = (fopen(((const char *)"testfile.txt"), ((const char *)"w")));
fclose(__1792_9_fp); 
}
