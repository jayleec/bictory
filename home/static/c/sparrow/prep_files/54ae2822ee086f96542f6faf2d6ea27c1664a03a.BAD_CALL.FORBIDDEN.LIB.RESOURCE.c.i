# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.RESOURCE.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.RESOURCE.c"



struct rlimit {
 int a;
 int b;
};


void getrlimit_FB09(int, struct rlimit *);

void resource_limit(){
 struct rlimit rlim;
 getrlimit_FB09(4354, &rlim);
}
