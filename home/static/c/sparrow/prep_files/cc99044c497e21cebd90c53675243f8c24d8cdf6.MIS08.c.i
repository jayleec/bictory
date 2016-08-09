# 1 "/home/kskyj/sparrow4/util/testcode/c/MIS08.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/MIS08.c"
volatile int badGlobal;

void foo(void) {
  const int badVar = 0;
}

void fooParam(volatile int badParam) {
  int sum = 1;
}
