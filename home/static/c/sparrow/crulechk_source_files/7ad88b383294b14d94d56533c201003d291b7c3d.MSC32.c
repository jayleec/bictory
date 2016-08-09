#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void msc32() {
	srand(time(NULL)); /* Create seed based on current time */
	int i=0;
	for (i=0; i<10; i++) {
	printf("%d, ", rand()); /* Generates different sequences at different runs */
	}
}
