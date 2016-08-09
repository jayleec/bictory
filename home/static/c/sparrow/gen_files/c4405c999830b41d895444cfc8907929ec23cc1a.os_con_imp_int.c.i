/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/os_con_imp_int.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 339 "/usr/include/stdio.h"
extern int printf(const char *__format, ...);
#line 604 "/usr/include/stdio.h"
extern char *fgets(char *__s, int __n, FILE *__stream);
#line 907 "/usr/include/unistd.h"
extern int sethostid(long __id);
#line 4 "/home/kskyj/sparrow4/util/testcode/c/os_con_imp_int.c"
extern void bar();



extern int strncpy();




extern int main(int argc, int *argv);
extern int malloc();
#line 23
extern int strlen();



extern int strncat();
extern int system();
extern int free();
#line 145 "/usr/include/stdio.h"
extern struct _IO_FILE *stdin;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/os_con_imp_int.c"
void bar() {
auto char *__2025_9_longString = "String signifying nothing";
auto char __2026_8_shortString[16];

strncpy((__2026_8_shortString), __2025_9_longString, 16);
printf(((const char *)"The last character in shortString is: %c %1$x\n"), ((int)((__2026_8_shortString)[15])));
0; return;
}

int main( int __2033_14_argc,  int *__2033_23_argv) {
auto int *__2034_8_pp;
auto char __2035_8_arg[80];
auto char __2036_8_cat[5] = "cat ";
auto char *__2037_9_command;
auto int __2038_7_commandLength;
#line 14
__2034_8_pp = ((int *)(malloc((__2033_23_argv[1]))));
#line 20
sethostid(((long)(__2033_23_argv[2])));

fgets((__2035_8_arg), 80, stdin);
__2038_7_commandLength = (((strlen((__2036_8_cat))) + (strlen((__2035_8_arg)))) + 1);
__2037_9_command = ((char *)(malloc(__2038_7_commandLength)));
if (__2037_9_command == ((char *)0)) return 0;
strncpy(__2037_9_command, (__2036_8_cat), __2038_7_commandLength);
strncat(__2037_9_command, (__2033_23_argv[1]), (__2038_7_commandLength - (strlen((__2036_8_cat)))));
system(__2037_9_command);
free(__2037_9_command);
free(__2034_8_pp);
return 0;

}
