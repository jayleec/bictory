#include <stdio.h>
 
void func(const char *file_name) {
  void *fp = fopen(file_name, "wb+");
  if (fp == 0) {
    /* Handle error */
    return;
  }

  fclose(fp);
}
