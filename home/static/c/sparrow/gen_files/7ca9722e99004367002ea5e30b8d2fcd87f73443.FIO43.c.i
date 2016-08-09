/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/FIO43.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 186 "/usr/include/stdio.h"
extern char *_Z6tmpnamPc(char *__s);
#line 249 "/usr/include/stdio.h"
extern FILE *_Z5fopenPKcS0_(const char *__filename, const char *__modes);
#line 4 "/home/kskyj/sparrow4/util/testcode/c/FIO43.c"
extern int _Z10fio43_mainv(void); int _Z10fio43_mainv(void) {
auto char __1792_7_file_name[20] = "fileName.txt";
auto FILE *__1793_8_fp;

if (!(_Z6tmpnamPc((__1792_7_file_name)))) {

}



__1793_8_fp = (_Z5fopenPKcS0_(((const char *)(__1792_7_file_name)), ((const char *)"wb+")));
if (((void *)__1793_8_fp) == ((void *)0)) {

} 
}
