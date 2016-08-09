// @checker BAD_CALL.TYPE_MISMATCH.STRING

// Dummy typedef
typedef unsigned int size_t;
typedef short wchar_t;

void wcsncpy(void *, void *, size_t);

void func() {
	char str1[] = "Hello";
	char str2[] = "00000";
	wcsncpy(str2, str1, 5); // @violation BAD_CALL.TYPE_MISMATCH.STRING
}
