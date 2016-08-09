/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_HARD_CODING.USERNAME.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_HARD_CODING.USERNAME.c"
struct _SQLHENV;



struct _SQLHDBC; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1
struct _SQLHENV {
int dummy;};
typedef struct _SQLHENV SQLHENV;

struct _SQLHDBC {
int dummy;};
typedef struct _SQLHDBC SQLHDBC;
#line 15
extern void SQLAllocHandle(int, int, SQLHENV *);

extern unsigned strlen(const char *);

extern int dbaccess(char *server, char *passwd);



extern int SQLAllocHnadle();
extern int SQLConnect();
#line 19
int dbaccess( char *__23_20_server,  char *__23_34_passwd) {
auto SQLHENV __24_11_henv;
auto SQLHDBC __25_11_hdbc;
SQLAllocHandle(0, 10, (&__24_11_henv));
SQLAllocHnadle(1, __24_11_henv, (&__25_11_hdbc));
SQLConnect(__25_11_hdbc, ((char *)__23_20_server), ((int)((short)(strlen(((const char *)__23_20_server))))), ("root"), 4, __23_34_passwd, (strlen(((const char *)__23_34_passwd))));
#line 31
return 0;
}
