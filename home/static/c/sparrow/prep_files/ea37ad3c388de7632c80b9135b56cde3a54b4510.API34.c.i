# 1 "/home/kskyj/sparrow4/util/testcode/c/API34.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API34.c"
typedef int S32;

struct badTag {
    int weight;
 int * weightPointer;
};

struct goodTag {
    S32 weight;
 S32 weightPointer[10];
};
