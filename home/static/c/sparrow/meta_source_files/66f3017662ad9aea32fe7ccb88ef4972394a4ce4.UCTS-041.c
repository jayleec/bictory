// @checker DO_NOT_USE_DANGEROUS_FUNCTIONS
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 100
typedef int pid_t;

pid_t vfork();

void f() {
	char buf[BUFSIZE];
	gets(buf); // @violation DO_NOT_USE_DANGEROUS_FUNCTIONS
	pid_t pid = vfork(); // @violation DO_NOT_USE_DANGEROUS_FUNCTIONS
}
