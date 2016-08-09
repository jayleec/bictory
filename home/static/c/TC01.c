//TC01: inter-procedural argument passing 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ResourceLeak_TC01 (int *p)
{
	char str[10] ="STRING";
	if( p == 0)
		return -1;	
	
	strcat(p, str);
	printf(" %s \n", p);
	free(p);
	return 0;	
}

int foo()
{
  char *p;
  p = malloc(10);
  if (p == 0) return 1;
  ResourceLeak_TC01(p);
  return 0;
}


