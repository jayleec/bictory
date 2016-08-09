/* STR31-C. Guarantee that storage for strings has sufficient space
   for character data and the null terminator */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void str31_bad1(){
  char dest[100];
  char src[100];
  unsigned int i;
  /* ... */
  for (i=0; i< 100; i++){
    src[i] = i;
  }

  for (i=0; i < 100; i++) {
    dest[i] = src[i]; 
  }
  dest[i] = '\0'; //@violation OVERRUN.STATIC
  /* ... */
}

void str31_good1(){
  char dest[100];
  char src[100];
  unsigned int i;
  /* ... */

  for (i=0; i< 100; i++){
    src[i] = 2*i - i*i;
  }

  for (i=0; src[i] && (i < sizeof(dest)-1); i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  /* ... */
}


void str31_bad2(){
  /* ... */
  char buff[256];
  char *editor = getenv("EDITOR");
  if (editor == NULL) {
    /* EDITOR environment variable not set */
  } else {
    strcpy(buff, editor); //@violation DO_NOT_ASSUME_ENV
  }
  /* ... */
}

void str31_bad3(void) {
  char buf[1024];
  fscanf(stdin, "%s", buf); 
}

void str31_bad4(const char *name) {
  char filename[128];
  sprintf(filename, "%s.txt", name);
}


void str31_good4(const char *name) {
  char filename[128];
  sprintf(filename, "%.123s.txt", name);
}


int main(int argc, char *argv[]) {
  /* ... */
  char prog_name[128];
  strcpy(prog_name, argv[0]); //@violation DO_NOT_ASSUME_ENV
  /* ... */
  return 1;
}

