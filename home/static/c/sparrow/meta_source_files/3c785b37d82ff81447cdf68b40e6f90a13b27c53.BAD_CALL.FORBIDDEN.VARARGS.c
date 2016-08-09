// @checker BAD_CALL.FORBIDDEN.VARARGS

void memcpy_API14(const char *, const char *);

void Func(const char * x) {	
	memcpy_API14(x, "hardcoded"); // @violation BAD_CALL.FORBIDDEN.VARARGS
	
	// Do something ...
}
