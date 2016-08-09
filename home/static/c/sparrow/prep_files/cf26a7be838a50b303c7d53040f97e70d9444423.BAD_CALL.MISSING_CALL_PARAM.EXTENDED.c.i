# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.MISSING_CALL_PARAM.EXTENDED.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.MISSING_CALL_PARAM.EXTENDED.c"


void memcpy_API12(const char *, const char *, unsigned int);
unsigned int strlen_API12(const char *);

void Func(const char * x, const char * y) {
 memcpy_API12(x, y, strlen_API12(y));
 memcpy_API12(x, y, strlen_API12(x));


}
