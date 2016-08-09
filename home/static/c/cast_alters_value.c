#include<stdio.h>
#include<stdlib.h>

void foo(){
  unsigned char x;
  x = 0x100; //@violation CAST_ALTERS_VALUE
  printf("Value is %d\n", x); 
}

void bar(){
  unsigned long x;
  x = 0xffffffff; 
  printf("Value is %ld\n", x); 
}

int a;

int zoo(){
  a = 2;
  foo();
  bar();
  return a = 1;
}

void main(){
  int a = zoo();
  int b;
  printf("Value zoo = %d\n", a = 3);
  a = b = 3;
}
