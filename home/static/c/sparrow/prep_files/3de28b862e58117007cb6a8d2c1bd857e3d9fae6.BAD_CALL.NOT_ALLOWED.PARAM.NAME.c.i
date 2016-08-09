# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.NOT_ALLOWED.PARAM.NAME.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.NOT_ALLOWED.PARAM.NAME.c"




void memcpy_API03(const char *, const char *);

void Func(const char * x) {
 memcpy_API03(x, "not allowed");
 memcpy_API03(x, "allowed");


}
