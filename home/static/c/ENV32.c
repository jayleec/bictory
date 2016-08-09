#include <stdio.h>
#include <stdlib.h>
 
void exit1(void) {
  /* ...cleanup code... */
  return;
}
 
void exit2(void) {
  if (1) {
    /* ...more cleanup code... */
    exit(0);		/* Violation */
  }
  return;
}

void func2(void) {
	exit1();
	exit2();
}

void func1(void) {
	func2();
}
 
int env(void) {
  if (atexit(func1) != 0) {
    /* Handle error */
  }
  if (atexit(func2) != 0) {
    /* Handle error */
  }
  /* ...program code... */
  exit(0);
}
