# 1 "/home/kskyj/sparrow4/util/testcode/c/FORBIDDEN_CALL.BEFORE_CALL.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/FORBIDDEN_CALL.BEFORE_CALL.c"



void umask_FBD16();
void fopen_FBD16(const char *, const char *);

void Func(int x) {
 umask_FBD16();
 fopen_FBD16("file.txt", "r");
}
