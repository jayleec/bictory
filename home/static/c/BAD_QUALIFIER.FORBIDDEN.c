// @checker BAD_QUALIFIER.FORBIDDEN

int func(int x) {
	const int a; // @violation BAD_QUALIFIER.FORBIDDEN
	
	// Do something ...
	return a;	
}
