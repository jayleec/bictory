/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_GETLOGIN_IN_MULTI_THREAD.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_GETLOGIN_IN_MULTI_THREAD.c"
struct passwd; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float; struct passwd {
int pw_gid;};

extern int getlogin();
extern struct passwd *getpwnam(int);
extern int isTrustedGroup(int);

extern int foo(); int foo() {
auto struct passwd *__13_19_pwd; __13_19_pwd = (getpwnam((getlogin())));
if (isTrustedGroup((__13_19_pwd->pw_gid)))
return 1;

else  return 0;
}
