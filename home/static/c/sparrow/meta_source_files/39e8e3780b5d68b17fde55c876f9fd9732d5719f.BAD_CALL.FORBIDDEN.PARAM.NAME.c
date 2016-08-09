// @checker BAD_CALL.FORBIDDEN.PARAM.NAME

#define API01_COUNTER "forbidden"

void memcpy_API01(const char *, const char *);

void Func(const char * x) {	
	memcpy_API01(x, API01_COUNTER); // @violation BAD_CALL.FORBIDDEN.PARAM.NAME
	
	// Do something ...
}
