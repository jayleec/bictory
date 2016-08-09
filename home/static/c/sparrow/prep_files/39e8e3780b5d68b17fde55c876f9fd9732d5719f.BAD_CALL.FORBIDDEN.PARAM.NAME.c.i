# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.PARAM.NAME.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.PARAM.NAME.c"




void memcpy_API01(const char *, const char *);

void Func(const char * x) {
 memcpy_API01(x, "forbidden");


}
