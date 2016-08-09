#define EXCLUDED(STR) printf("%s",STR);    	/* It's ok if this macro has been excluded */
#define BADPRINT(STR) printf("%s",STR);    	/* Violation : shall not end with a semicolon */

void badTest() {
	EXCLUDED("excluded")
	BADPRINT("test")
}

#define GOODPRINT(STR) printf("%s",STR)

void goodTest() {
	GOODPRINT("test");
}
