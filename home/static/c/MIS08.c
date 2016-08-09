volatile int badGlobal;					/* Violation : shall not be permitted. */

void foo(void) {
  const int badVar = 0;					/* Violation : shall not be permitted. */  
}

void fooParam(volatile int badParam) {	/* Violation : shall not be permitted. */
  int sum = 1;
}