#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern void opus1_print(int vla[]){};

int func(int size){ // problem 
  int vla[size];
  opus1_print(vla);
  vla[0] = size + 1;
  vla[1] = size - 100;
  vla[2] = size - 100;
  vla[3] = size - 100;
  vla[4] = size - 100;
  vla[5] = size - 100;
  vla[6] = size - 100;
  return vla[1]; 
}

int main(){
  int i = func(0); // OK
  printf("Result=%d\n", i);

  i = func(-10); // run but problematic 
  printf("Result=%d\n", i);

  i = func(10); // problem 
  printf("Result=%d\n", i);
  return 1;
}
