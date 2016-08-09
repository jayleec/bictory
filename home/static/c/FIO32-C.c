#include <stdio.h>
 
void func(const char *file_name) {
  void *fp = fopen(file_name, "wb+"); 
  if (fp == 0) {
    /* Handle error */
    return;
  }

  /* Operate on the file */
  
  if (fclose(fp) == 1) {
    /* Handle error */
    return;
  }

}
