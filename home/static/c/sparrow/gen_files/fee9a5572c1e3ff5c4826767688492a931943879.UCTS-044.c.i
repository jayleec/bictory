/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:58 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/UCTS-044.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 5 "/home/kskyj/sparrow4/util/testcode/c/UCTS-044.c"
typedef int SQLHENV;
typedef int SQLHDBC;
typedef char SQLCHAR;
#line 397 "/usr/include/string.h"
extern size_t strlen(const char *__s);
#line 10 "/home/kskyj/sparrow4/util/testcode/c/UCTS-044.c"
extern void SQLConnect(SQLHDBC hdbc, SQLCHAR *server, int serverlen, char *user, int userlen, char *pw, int pwlen);

extern int dbaccess(char *server, char *user); int dbaccess( char *__299_21_server,  char *__299_36_user) {

auto SQLHDBC __301_10_hdbc;



SQLConnect(__301_10_hdbc, ((SQLCHAR *)__299_21_server), ((int)(strlen(((const char *)__299_21_server)))), __299_36_user, ((int)(strlen(((const char *)__299_36_user)))), "asdf", 4);
return 0;
}
