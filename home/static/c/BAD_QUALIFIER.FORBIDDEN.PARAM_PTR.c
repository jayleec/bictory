// @checker BAD_QUALIFIER.FORBIDDEN.PARAM_PTR

void Func(const char * a, int b) { // @violation BAD_QUALIFIER.FORBIDDEN.PARAM_PTR
	// Do something 
}
