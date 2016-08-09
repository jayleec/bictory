#include <stdlib.h>
#define RANDOM (rand() % 2)

struct A {
  int *third;
};

struct B {
  struct A second[20];
};

struct C {
  struct B first;
};

void test(struct C *outputArg){
  int c;
  outputArg->first.second[5].third = &c;
  /* This stack address will not be valid after the function exits,
  but it is being exported. */
}
