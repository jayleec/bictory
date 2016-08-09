// @checker BAD_CALL.MISSING_CALL_PARAM

void memcpy_API11(const char *, const char *, unsigned int);
unsigned int strlen_API11(const char *);

void Func(const char * x, const char * y) {	
	memcpy_API11(x, y, 1); // @violation BAD_CALL.MISSING_CALL_PARAM
	memcpy_API11(x, y, strlen_API11(x));
	
	// Do something ...
}
