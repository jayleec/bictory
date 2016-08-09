static char badChGlobal;			/* Violation : using char */

struct {
	char badChField;				/* Violation : using char */
} badSt;

void foo(char * badChParam) {  		/* Violation : using char */
    char badChVar;         			/* Violation : using char */
	char badChArray[10];			/* Violation : using char */
    /* do something */
}   