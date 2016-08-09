// @checker BAD_CALL.FORBIDDEN.PARAM.LITERAL

void memset_API13(const char *, unsigned int, unsigned int);

void Func(const char * x) {	
	memset_API13("hardcoded", 0, 9); // @violation BAD_CALL.FORBIDDEN.PARAM.LITERAL
	
	// Do something ...
}
