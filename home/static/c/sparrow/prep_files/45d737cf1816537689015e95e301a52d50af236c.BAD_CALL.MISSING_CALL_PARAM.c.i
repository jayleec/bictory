# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.MISSING_CALL_PARAM.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.MISSING_CALL_PARAM.c"


void memcpy_API11(const char *, const char *, unsigned int);
unsigned int strlen_API11(const char *);

void Func(const char * x, const char * y) {
 memcpy_API11(x, y, 1);
 memcpy_API11(x, y, strlen_API11(x));


}
