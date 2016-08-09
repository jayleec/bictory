// @checker TOO_MANY_METHODS

int func1() {
	return 1;
}

int func2() {
	return 2;
}

int func3() { // @violation TOO_MANY_METHODS
	return 3;
}
