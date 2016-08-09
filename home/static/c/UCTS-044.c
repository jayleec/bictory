// @checker DO_NOT_USE_HARD_CODING.PASSWORD
#include <string.h>

// Dummy types
typedef int SQLHENV;
typedef int SQLHDBC;
typedef char SQLCHAR;

// Dummy function
void SQLConnect(SQLHDBC hdbc, SQLCHAR * server, int serverlen, char * user, int userlen, char * pw, int pwlen);

int dbaccess(char * server, char * user) {
	SQLHENV henv;
	SQLHDBC hdbc;
	
	// Do something
	
	SQLConnect(hdbc, (SQLCHAR *)server, strlen(server), user, strlen(user), "asdf", 4); // @violation DO_NOT_USE_HARD_CODING.PASSWORD
	return 0;
}
