// @checker BAD_INIT.CHAR_ARRAY

void func() {
	char a[5] = "abcde"; // @violation BAD_INIT.CHAR_ARRAY
}
