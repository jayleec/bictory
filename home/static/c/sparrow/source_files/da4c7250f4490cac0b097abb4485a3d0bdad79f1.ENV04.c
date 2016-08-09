#include <stdio.h>
#include <stdlib.h>

int useruser() {
	char *input = NULL;
	 
	/* input gets initialized by user */
	 
	char cmdbuf[512];
	int len_wanted = snprintf(
	  cmdbuf, sizeof(cmdbuf), "any_cmd '%s'", input
	);
	if (len_wanted >= sizeof(cmdbuf)) {
	  perror("Input too long");
	}
	else if (len_wanted < 0) {
	  perror("Encoding error");
	}
	else if (system(cmdbuf) == -1) {		/* Violation */
	  perror("Error executing input");
	}

}
