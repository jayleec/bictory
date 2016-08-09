// @checker BAD_OPERATOR.LOGICAL_COMPARISON

int func(int x) {
	int a;
	
	// Do something ...
	
	a == x; // @violation BAD_OPERATOR.LOGICAL_COMPARISON
	return a;	
}
