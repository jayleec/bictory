# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRUCT_MEMBER_ACCESS.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRUCT_MEMBER_ACCESS.c"


struct st {
 int a;
 int b;
};

void Func(int x) {
 struct st obj;
 int a;
 a = obj.a;
 a = obj.a;
 a = obj.a;
}
