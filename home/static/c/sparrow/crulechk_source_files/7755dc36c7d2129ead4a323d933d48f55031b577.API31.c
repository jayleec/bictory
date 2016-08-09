typedef long L32;

struct st { // struct
	int   abc;
	long badLVariable;   			/* Violation : shall not be permitted. */
};

union a {
	int unionIValue;
	long unionLValue;				/* Violation : shall not be permitted. */
};

void foo(long badLParam) {			/* Violation : shall not be permitted. */
	int sum = 30;
	L32 badLTypedef;    			/* Violation : shall not be permitted. */
	long badLVar;		 			/* Violation : shall not be permitted. */
	const long badLConst;			/* Violation : shall not be permitted. (if only not ignore const) */
	long * badLPtrVar;		 		/* Violation : shall not be permitted. */
}