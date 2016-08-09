# 1 "/home/kskyj/sparrow4/util/testcode/c/API29.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API29.c"
typedef int S32;

int badFuncProto(S32 badProtoParam[]);
S32 goodFuncProto(int goodProtoParam[]);

struct _badStruct {
 int badVar[10];
 S32 goodVar[10];
} badStruct;

static long badContent[10];
void badFoo(long badNum) {
    int badCount[10];

}

static S32 goodContent[10];
void goodFoo(S32 goodNum) {
    S32 goodCount[10];

}
