#include <stdio.h>
#include <string.h>

int main(){
  char buffer1[4];
  char buffer2[4];

  strncpy(buffer1, "1234",4); //@violation IMPROPER_NULL_TERMINATION
  strncpy(buffer2, "567",4);

  printf("length of buffer1 = %ld\n", strlen(buffer1)); // 10
  printf("length of buffer2 = %ld\n", strlen(buffer2)); // 4
  return 1;
}
