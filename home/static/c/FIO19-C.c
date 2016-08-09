#include <stdio.h>
#include <stdlib.h>

void fio19_bad1(){
  void *fp;
  long file_size;
  char *buffer;
  fp = fopen("foo.bin", "rb");
  if (fp == 0) {
    /* Handle error */
    return;
  }
  
  if (fseek(fp, 0 , SEEK_END) != 0) {
    /* Handle error */
    fclose(fp);
    return;
  }
  
  file_size = ftell(fp);
  opus1_print(file_size);
  if (file_size == -1) {
    fclose(fp);
    return;
    /* Handle error */
  }
  
  buffer = (char*)malloc(file_size); //@violation UNREASONABLE_PARAMETER
  if (buffer == 0) {
    /* Handle error */
    fclose(fp);
    return;
  }
  fclose(fp);
  free(buffer);
}

int main(){
  fio19_bad1();
  return 1;

}
