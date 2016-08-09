// @checker BAD_CALL.MISSING_CALL_PARAM.EXTENDED

void memcpy_API12(const char *, const char *, unsigned int);
unsigned int strlen_API12(const char *);

void Func(const char * x, const char * y) {	
	memcpy_API12(x, y, strlen_API12(y)); // @violation BAD_CALL.MISSING_CALL_PARAM.EXTENDED
	memcpy_API12(x, y, strlen_API12(x));
	
	// Do something ...
}
