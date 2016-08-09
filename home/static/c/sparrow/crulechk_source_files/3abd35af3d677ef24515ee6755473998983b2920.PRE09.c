#define strncpy_s(buf, size, fmt, list) strncpy(buf, fmt, list)		/* Violation */

// Dummy function
void strncpy(int buf, int fmt, int list);

int PRE09_main() {
	strncpy_s(0, 0, 0, 0);
}
