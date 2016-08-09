# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.IMPROPER_VARARGS.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.IMPROPER_VARARGS.c"


void Fun_API04_call(int, ...);

void Func(const char * x) {
 int p1, p2;
 Fun_API04_call(1, p1, p2);


}
