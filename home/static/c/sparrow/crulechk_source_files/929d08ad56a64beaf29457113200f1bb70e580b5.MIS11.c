char * ptrGlobal, badGlobal; /* Violation : different type(Global) */

void testFunc() {
	char * cptr, badc; 				/* Violation : different type */
	char * cptr2, badc2, * goodc; 	/* Violation badc2 only : different type */
	char c1, c2;
}