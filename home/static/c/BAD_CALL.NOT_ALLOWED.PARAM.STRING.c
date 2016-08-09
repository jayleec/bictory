// @checker BAD_CALL.NOT_ALLOWED.PARAM.STRING

void memcpy_API02(const char *, const char *);

void Func(const char * x, const char * y) {	
	memcpy_API02(x, y); // @violation BAD_CALL.NOT_ALLOWED.PARAM.STRING
	
	// Do something ...
}
