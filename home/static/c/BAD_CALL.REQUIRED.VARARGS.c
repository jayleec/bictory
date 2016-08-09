// @checker BAD_CALL.REQUIRED.VARARGS

void memcpy_API15(const char *, const char *);

void Func(const char * x) {	
	memcpy_API15("hardcoded", "hardcoded"); // @violation BAD_CALL.REQUIRED.VARARGS
	
	// Do something ...
}
