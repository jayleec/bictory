// @checker BAD_CALL.REQUIRED.PARAM

// Dummy functions
void divide(int x);

void Func(int x) {
	divide(x); // @violation BAD_CALL.REQUIRED.PARAM
	
	// Do something ...
}
