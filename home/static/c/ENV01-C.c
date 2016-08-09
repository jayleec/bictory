#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f() {
  char path[100]; /* requires PATH_MAX to be defined */
  strcpy(path, getenv("PATH"));  //@violation DO_NOT_ASSUME_ENV 
}

void f2() {
  char *path = 0;
  /* avoid assuming $PATH is defined or has limited length */
  const char *temp = getenv("PATH");
  if (temp != 0) {
    path = (char*) malloc(strlen(temp) + 1);
    if (path == 0) {
      return;
      /* Handle error condition */
    } else {
      strcpy(path, temp); 
    }
    /* use path */
    free(path);
  }
}

/* Improper Null Termination */
void secure_coding_16(){
  char buf[10];
  char *inputbuf=unknown();
  read(1, inputbuf, 10);
  strcpy(buf,inputbuf); //@violation DO_NOT_ASSUME_ENV 
}

void main(){
  f();
}

