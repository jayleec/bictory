typedef float FL32;

struct st { // struct
	int   abc;
	float badFVariable;   			/* Violation : shall not be permitted. */
};

union a {
	int unionIValue;
	float unionFValue;				/* Violation : shall not be permitted. */
	double unionDValue;				/* Violation : shall not be permitted. */
};

void foo(float badFParam) {			/* Violation : shall not be permitted. */
	int sum = 30;
	FL32 badFTypedef;    			/* Violation : shall not be permitted. */
	float badFVar;		 			/* Violation : shall not be permitted. */
	float * badFPtrVar;		 		/* Violation : shall not be permitted. */
	double badDVar;		 			/* Violation : shall not be permitted. */
}