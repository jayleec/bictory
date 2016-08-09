#include <stdio.h>
#include <stdlib.h>

struct node {
  int v;
};

int gn;

int divide(int y, struct node *x){
  if(y > 0)
    return y/(x->v);
  else return 10;
}

void example(){
  int a = 0, b = 1;
  struct node *x = malloc(sizeof(struct node));
  if(x == 0) return;
  x->v = b; 
  b = divide(a, x);
  a = b - 10;
  if(b > 0) x->v = a; 
  b = divide(b, x);  //@violation DIV_BY_ZERO Floating point exception: 8
  free(x);
  return; 
}

void int_calc(int x){
  int y = x - x;
  printf("%d\n", y);
  printf("%d\n", 100/y); //@violation DIV_BY_ZERO
}

void float_calc(float x){
  float y = x - x;
  printf("%f\n", y);
  printf("%f\n", 100/y);
}

void double_calc(double x){
  double y = x - x;
  printf("%g\n", y);
  printf("%g\n", 100/y);
}

int main(){
  float_calc(1.0001);
  double_calc(1.0001);
  int_calc(1);
  example();
  return 1;
}

int divide2(int z, struct node n){
  if(z > 0)
    return z/(n.v);
  else return 1;
}

int foo(){
  int x = 0, y = 1;
  struct node n;
  n.v = y;
  z = divide2(y - 2, n);
  if(z > 0) n.v = x;
  z = z + 10;
  z = divide2(z,n); //@violation DIV_BY_ZERO
  return 0;
}

void foo2(int x){
  int a = 0;
  int b = x;
  
  if (gn > 10){
    b = a;
  } 

  if (b == 0)
    return;
  else {
    a = x/b; //@violation(NOT_EXPECTED) DIV_BY_ZERO
  }

  return;
}

int dangerous_division_bad(int input){
  char *x = getenv("PATH");
  int n = atoi(x);
  return input/n; //@violation DIV_BY_ZERO.MISSING_CHECK
}
  

int dangerous_division_good(int input){
  char *x = getenv("PATH");
  int n = atoi(x);
  if (n != 0) return input/n;
  
  return 0;
}

int dangerous_division_bad2(int input){
  char *x = getenv("PATH");
  int n = atoi(x);
  if (n <= 50) return input/n; //@violation DIV_BY_ZERO.MISSING_CHECK
  
  return 0;
}

int dangerous_division_good2(int input){
  char *x = getenv("PATH");
  int n = atoi(x);
  if (n >= 10) return input/n;
  
  return 0;
}
