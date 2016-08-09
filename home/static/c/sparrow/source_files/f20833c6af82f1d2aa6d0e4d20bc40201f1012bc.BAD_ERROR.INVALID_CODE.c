// @checker BAD_ERROR.INVALID_CODE

// Dummy function
void SET_ERR_API19(const char *);

void Func(const char * x) {	
	SET_ERR_API19("INVALIDERR"); // @violation BAD_ERROR.INVALID_CODE
	SET_ERR_API19("ERR0012");
}
