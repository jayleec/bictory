// This include file includes the body of goodHeaderFunc()
#include "70556c0c420e47f7ee75b64fad7fdbb7bfabab7c.MIS10.h"

void goodFunc(void);
void goodHeaderFunc(void);			/* Ok since the header file has the body of this function */
void badFunc(void);					/* Violation : needs function definition */
extern void badExternFunc(void);	/* Violation if only include-extern option is true */

void goodFunc(void) {
	/* do something */
}
