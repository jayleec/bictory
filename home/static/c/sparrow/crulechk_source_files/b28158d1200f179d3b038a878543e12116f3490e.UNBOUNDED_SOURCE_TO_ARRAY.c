#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  char cmdline [4096];
  int i;
  cmdline[0] = '\0';
	
   for (i = 1; i < argc; ++i) {
      strcat(cmdline, argv [i]); // UNBOUNDED_SOURCE_TO_ARRAY
      strcat(cmdline, " ");
  }
	printf("Debug Info");
  return 0;
}




