// @checker BAD_INTEGER_CONST_DEFINITION

void func() {
	unsigned long a = 0xFF; // @violation BAD_INTEGER_CONST_DEFINITION
}
