// @checker BAD_CALL.REQUIRED.WRAPPER

// Dummy functions
int API06_NEED_WRAPPER(int);
int API06_WRAPPER(int);

void Func(const char * x) {	
	int a = API06_NEED_WRAPPER(0); // @violation BAD_CALL.REQUIRED.WRAPPER
	int b = API06_WRAPPER(API06_NEED_WRAPPER(0));
}
