// @checker BAD_NAME.VARIABLE

void Func(int x) {
	int FBNVariable; // @violation BAD_NAME.VARIABLE
	int OKVariable;	
	
	// Do something ...
}
