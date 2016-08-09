#include <stdio.h>
#include <stdlib.h>

int MSC32_main() {
	FILE * fp = fopen("testfile.txt", "w");		/* Violation */
	fclose(fp);
}
