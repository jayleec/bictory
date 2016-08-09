#include <stdio.h>

// Prototype definition for the test
void getResource();
int isUserAuthentic();

void fooBad(void) {
	char * some = NULL;
  
	getResource();  /* Violation : shall be authorized. */
  /* do something */
}

void fooNestedBad(void) {
	char * some = NULL;
  
	if(isUserAuthentic()) {
		if(isUserAuthentic()) {
			getResource();
		}
		
		getResource(); 
	}
  /* do something */
} 
