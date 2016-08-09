// @checker BAD_CALL.NOT_ALLOWED.PARAM.NAME

#define API03_COUNTER "allowed"

void memcpy_API03(const char *, const char *);

void Func(const char * x) {	
	memcpy_API03(x, "not allowed"); // @violation BAD_CALL.NOT_ALLOWED.PARAM.NAME
	memcpy_API03(x, API03_COUNTER);
	
	// Do something ...
}
