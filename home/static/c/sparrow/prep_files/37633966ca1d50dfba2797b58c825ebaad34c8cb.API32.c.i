# 1 "/home/kskyj/sparrow4/util/testcode/c/API32.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API32.c"
typedef int S32;

int * badFuncProto(S32 * badProtoParam);
S32 * goodFuncProto(int * goodProtoParam);

struct _badStruct {
 int * badVar;
 S32 * goodVar;
} badStruct;

static long * badContent;
void badFoo(long * badNum) {
    int * badCount;

}

static S32 * goodContent;
void goodFoo(S32 * goodNum) {
    S32 * goodCount;

}
