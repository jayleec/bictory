// @checker BAD_ERROR.MISSING_RETURN

// Dummy function
void SET_ERR_API21(const char *);

void Func(const char * x) {	
	SET_ERR_API21("ERR0012");	
} // @violation BAD_ERROR.MISSING_RETURN
