/* MEM09-C. Do not assume memory allocation functions initialize
   memory */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mem09_bad1(){
  char *str = "01234567890123456789";
  unsigned int len = strlen(str);

  if (len >= 22 - 1) {
    /* Handle string too long error */
    return;
  }
  char *buf = (char *)malloc(22);
  if (buf == 0) {
    /* Handle allocation error */
    return;
  }
  
  strncpy(buf, str, len); //@violation IMPROPER_NULL_TERMINATION
  
  /* Process buf */
 
  free(buf);
  buf = 0;
}

