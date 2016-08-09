// @checker BAD_STRING_MANAGEMENT

// Dummy functions
void _mbscpy(char * str1, char * str2) {}
void _mbscpy_s(char * str1, int size, char * str2) {}
void _mbscat(char * str1, char * str2) {}
void _mbscat_s(char * str1, char * str2) {}

void f(char * str1, int size, char * str2) {
	_mbscpy(str1, str2); // @violation BAD_STRING_MANAGEMENT
	_mbscpy_s(str1, size, str2);
	_mbscat(str1, str2); // @violation BAD_STRING_MANAGEMENT
	_mbscat_s(str1, str2);
}
