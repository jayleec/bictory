/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/INCORRECT_PERMISSION.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 214 "/usr/include/stdio.h"
extern int fclose(FILE *__stream);
#line 249 "/usr/include/stdio.h"
extern FILE *fopen(const char *__filename, const char *__modes);
#line 73 "/usr/include/fcntl.h"
extern int open(const char *__file, int __oflag, ...);
#line 9 "/home/kskyj/sparrow4/util/testcode/c/INCORRECT_PERMISSION.c"
extern void sfunc();
#line 15
extern int func();


extern int close();

extern int umask();
#line 9
void sfunc() {
auto FILE *__1847_9_fp;
__1847_9_fp = (fopen(((const char *)"file.txt"), ((const char *)"w")));
fclose(__1847_9_fp); 
}

int func() {
auto int __1853_6_fd; auto int __1853_10_ret;
__1853_6_fd = (open(((const char *)"file.txt"), 0x2));
__1853_10_ret = (close(__1853_6_fd));

umask(0);

__1853_6_fd = (open(((const char *)"file.txt"), 0x2));
__1853_10_ret = (close(__1853_6_fd));
sfunc();

umask(0x3f);

return 0;
}
