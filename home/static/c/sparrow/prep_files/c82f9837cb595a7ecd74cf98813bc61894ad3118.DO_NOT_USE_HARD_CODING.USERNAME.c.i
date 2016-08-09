# 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_HARD_CODING.USERNAME.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_HARD_CODING.USERNAME.c"
typedef struct _SQLHENV {
 int dummy;
} SQLHENV;

typedef struct _SQLHDBC {
 int dummy;
} SQLHDBC;







extern void SQLAllocHandle(int, int, SQLHENV *);
extern void SQCONNECT(SQLHDBC, char *, short *, const char *, int, char *, unsigned int);
extern unsigned int strlen(const char *);

int dbaccess(char *server, char* passwd) {
  SQLHENV henv;
  SQLHDBC hdbc;
  SQLAllocHandle(0, 10, &henv);
  SQLAllocHnadle(1, henv, &hdbc);
  SQLConnect(hdbc,
      (char*)server,
      (short)strlen(server),
      "root",
      4,
      passwd,
      strlen(passwd));
  return 0;
}
