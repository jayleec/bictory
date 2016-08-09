// @checker INCORRECT_PERMISSION
#include <stdio.h>
#include <stdlib.h>	
#include <sys/types.h>
#include <fcntl.h>

typedef unsigned int mode_t;

void sfunc() {
	FILE * fp;
	fp = fopen("file.txt", "w");
	fclose(fp);
}

int func() {
	int fd, ret;
	fd = open("file.txt", O_RDWR);
	ret = close(fd);
	
	umask(0); 
	
	fd = open("file.txt", O_RDWR); // @violation INCORRECT_PERMISSION
	ret = close(fd);
	sfunc(); // @violation INCORRECT_PERMISSION
	
	umask(077);

	return 0;
}

