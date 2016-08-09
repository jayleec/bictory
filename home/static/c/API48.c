#define TRUE 1
#define FALSE 0

int IsBadReturn(const char path) {
    /* do something */
    return FALSE;   
}

int IsAnotherBadReturn(const char path) {
	/* do something */
	int a = 3;
	return a + 1;	/* Violation : return value is not a constant */
}

int IsGoodReturn(const char path) {
    /* do something */
    return 0;		/* Violation : not allowed constant 0 */
}
