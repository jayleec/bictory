# 1 "/home/kskyj/sparrow4/util/testcode/c/API30.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API30.c"
typedef double newDouble;

signed char badGlobal[10];

void badFoo(void) {
 signed char badSc[10];
 signed short badSh[10];
 unsigned short int badUshi[10];
 newDouble badArr[10];
}

void goodFoo(void) {
 signed char c;
 signed short ssh;
 unsigned short int ushi;
 newDouble td;
}
