# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.WRAPPER.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.WRAPPER.c"



int API06_NEED_WRAPPER(int);
int API06_WRAPPER(int);

void Func(const char * x) {
 int a = API06_NEED_WRAPPER(0);
 int b = API06_WRAPPER(API06_NEED_WRAPPER(0));
}
