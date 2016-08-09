/* MEM34-C. Only free memory allocated dynamically */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mem34_bad1(int argc, const char *argv[]) {
  char *str = 0;
  unsigned int len;
  
  if (argc == 2) {
    len = strlen(argv[1])+1;
    if (len > 1000) {
      /* Handle error */
    }
    str = (char *)malloc(len);
    if (str == 0) {
      /* Handle allocation error */
      goto END;
    }
    strcpy(str, argv[1]);  
  }
  else if (argc > 2) {
    str = "usage: $>a.exe [string]";
    printf("%s\n", str);
  }  
 END:
  /* ... */
  free(str); //@violation FREE_NULL_POINTER
  return;
}

#define BUFSIZE 256
  
void mem34_bad2(void) {
  char buf[BUFSIZE];
  char *p;
  /* ... */
  p = (char *)realloc(buf, 2 * BUFSIZE);  //@violation FREE_NON_HEAP
  /* ... */
  free(p);
  return;
}
