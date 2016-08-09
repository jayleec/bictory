// @checker BAD_OPERATOR.ASSIGNMENT_IN_COND

void func(int x) {
	if(x = 0) { // @violation BAD_OPERATOR.ASSIGNMENT_IN_COND
		// Do something ...
	} else {
		// Do something ...
	}
}
