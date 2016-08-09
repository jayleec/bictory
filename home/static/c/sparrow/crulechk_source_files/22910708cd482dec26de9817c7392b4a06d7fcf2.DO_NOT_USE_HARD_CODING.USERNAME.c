typedef struct _SQLHENV {
	int dummy;
} SQLHENV;

typedef struct _SQLHDBC {
	int dummy;
} SQLHDBC;

#define SQL_HANDLE_ENV 0
#define SQL_HANDLE_DBC 1
#define SQL_NULL_HANDLE 10
#define SQLCHAR char
#define SQLSMALLINT short

extern void SQLAllocHandle(int, int, SQLHENV *);
extern void SQCONNECT(SQLHDBC, SQLCHAR *, SQLSMALLINT *, const char *, int, char *, unsigned int);
extern unsigned int strlen(const char *);

int dbaccess(char *server, char* passwd) {
  SQLHENV henv;
  SQLHDBC hdbc;
  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  SQLAllocHnadle(SQL_HANDLE_DBC, henv, &hdbc);
  SQLConnect(hdbc,
	     (SQLCHAR*)server,
	     (SQLSMALLINT)strlen(server),
	     "root", // violation @ DO_NOT_USE_HARD_CODING.USERNAME
	     4,
	     passwd,
	     strlen(passwd));
  return 0;
}
