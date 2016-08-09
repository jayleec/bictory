# 1 "/home/kskyj/sparrow4/util/testcode/c/API35.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API35.c"
typedef double newDouble;

void badFoo(void) {
  signed char sc[10];
  signed short ssh[10];
  unsigned short int ushi[10];
  newDouble td[10];
}

void goodFoo(void) {
  char c[10];
  short sh[10];
  int i[10];
}
