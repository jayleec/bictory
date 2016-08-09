/* FIO02-C. Canonicalize path names originating from tainted sources */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int verify_file(char*){return 1;}
int main(int argc, char* argv[]){
  char *x = 0;
  /* Verify argv[1] is supplied */
  
  if (!verify_file(argv[1])) {
      /* Handle error */
    }

  x = argv[1];
  
  if (fopen(x, "w") == 0) { //@violation PATH_TRAVERSAL
    /* Handle error */
    return 0;
  }
  
  /* ... */
  fcloseall();
  return 1;
}
