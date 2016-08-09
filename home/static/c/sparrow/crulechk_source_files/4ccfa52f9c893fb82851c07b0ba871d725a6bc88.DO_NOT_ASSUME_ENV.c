#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_MAX 9
void do_not_assume_env() {
  char path[PATH_MAX]; 
  strcpy(path, getenv("PATH")); // DO_NOT_ASSUME_ENV
}
