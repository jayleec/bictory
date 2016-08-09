typedef double newDouble;

signed char badGlobal[10];   		            /* Violation : shall use the allowed array types. */

void badFoo(void) {
	signed char badSc[10];          			/* Violation : shall use the allowed array types. */
	signed short badSh[10];               		/* Violation : shall use the allowed array types. */
	unsigned short int badUshi[10];        		/* Violation : shall use the allowed array types. */
	newDouble badArr[10];						/* Violation : shall use the allowed array types. */
}

void goodFoo(void) {
	signed char c;  
	signed short ssh;
	unsigned short int ushi;
	newDouble td;
}
