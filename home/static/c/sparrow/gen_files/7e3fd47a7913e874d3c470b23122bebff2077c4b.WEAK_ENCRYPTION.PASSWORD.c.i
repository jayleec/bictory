/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.PASSWORD.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 8 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.PASSWORD.c"
typedef int SQLHENV;
typedef int SQLHDBC;
typedef char SQLCHAR;
typedef int RSA;
#line 397 "/usr/include/string.h"
extern size_t _Z6strlenPKc(const char *__s);
#line 14 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.PASSWORD.c"
extern void _Z10SQLConnectiPciS_iS_i(SQLHDBC hdbc, SQLCHAR *server, int serverlen, char *user, int userlen, char *pw, int pwlen);
extern char *_Z13base64_decodePc(char *pw);
extern void _Z19RSA_private_decryptiPcS_Pii(int cpwlen, char *cpw, char *pw, RSA *rsa, int opt);

extern int _Z8dbaccessPcS_S_Pi(char *server, char *user, char *cpw, RSA *rsa); int _Z8dbaccessPcS_S_Pi( char *__305_21_server,  char *__305_36_user,  char *__305_49_cpw,  RSA *__305_60_rsa) {

auto SQLHDBC __307_10_hdbc;
auto char *__308_9_pw;



__308_9_pw = (_Z13base64_decodePc(__305_49_cpw));
_Z10SQLConnectiPciS_iS_i(__307_10_hdbc, ((SQLCHAR *)__305_21_server), ((int)(_Z6strlenPKc(((const char *)__305_21_server)))), __305_36_user, ((int)(_Z6strlenPKc(((const char *)__305_36_user)))), __308_9_pw, ((int)(_Z6strlenPKc(((const char *)__308_9_pw)))));

_Z19RSA_private_decryptiPcS_Pii(((int)(_Z6strlenPKc(((const char *)__305_49_cpw)))), __305_49_cpw, __308_9_pw, __305_60_rsa, 0);
_Z10SQLConnectiPciS_iS_i(__307_10_hdbc, ((SQLCHAR *)__305_21_server), ((int)(_Z6strlenPKc(((const char *)__305_21_server)))), __305_36_user, ((int)(_Z6strlenPKc(((const char *)__305_36_user)))), __308_9_pw, ((int)(_Z6strlenPKc(((const char *)__308_9_pw)))));
return 0;
}
