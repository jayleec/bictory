/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_PRIVILEGE_RELINQUISHMENT.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 6 "/home/kskyj/sparrow4/util/testcode/c/BAD_PRIVILEGE_RELINQUISHMENT.c"
extern int setuid(int);
extern int setgid(int);
extern int getuid();
extern int getgid();

extern void func(); void func() {
if ((setuid((getuid()))) == (-1)) {

}
if ((setgid((getgid()))) == (-1)) {

} 
}
