typedef struct bad {
	char a;
} bad_t;

void badFoo(void) {
	struct bad badVar;   	/* Violation : shall use the allowed elaborated types. */
	bad_t badVarTypeDef;  	/* Violation : shall use the allowed elaborated types. */
	
	struct {
		char b;
	} badAnonymous;			/* Violation : shall use the allowed elaborated types. (this is an anonymous type) */
}

typedef struct good {
	char a;
} good_t;

void goodFoo(void) {
	struct good goodVar;
	good_t goodVarTypeDef;
}
