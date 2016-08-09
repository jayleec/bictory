// @checker BAD_CALL.FORBIDDEN.PARAM.STRING

#define PDB_ERRORNUM_API08 0

void memcpy_API09(const char *, const char *);

void Func(const char * x) {	
	memcpy_API09(x, "hardcoded"); // @violation BAD_CALL.FORBIDDEN.PARAM.STRING
	
	// Do something ...
}
