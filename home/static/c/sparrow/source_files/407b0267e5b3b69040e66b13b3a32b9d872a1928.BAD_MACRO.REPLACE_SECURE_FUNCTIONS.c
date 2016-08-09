// @checker BAD_MACRO.REPLACE_SECURE_FUNCTIONS

#define fopen_s(file, name, mode) fopen(name, mode) // @violation BAD_MACRO.REPLACE_SECURE_FUNCTIONS

// Dummy function
typedef int FILE;
FILE * fopen(const char * filename, const char * mode);

void func() {

	FILE * a;
	a = fopen_s(a, "file", "a");
}
