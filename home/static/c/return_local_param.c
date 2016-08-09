#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dynamic_foo(int **x){
  *x = (int *)malloc(sizeof(int) * 100);
}

void local_foo(int **x, int n){
  int y = 7;
  if (n > 10){
    *x = &y; //@violation PARAMETER_POINTER_TO_LOCAL
  } else {
    *x = (int *)malloc(sizeof(int) * 100);
  }
}

int * issuePublicKey(){
  int publicKey[256] = {0,};
  return publicKey; //@violation RETURN_LOCAL
}

int main(){
  int *a = 0;
  int b = 1;
  a = &b;
  local_foo(&a, 30);
  dynamic_foo(&a);
  free(a);
  return 1;
}
