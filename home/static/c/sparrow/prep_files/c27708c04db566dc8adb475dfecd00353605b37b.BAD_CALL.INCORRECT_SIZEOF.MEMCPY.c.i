# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.INCORRECT_SIZEOF.MEMCPY.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.INCORRECT_SIZEOF.MEMCPY.c"



void memcpy(const char *, const char *, int);

void foo(){
 char a[100];
 char b[100];
 int * ref = a;

 memcpy(a,b,sizeof(ref));
 memcpy(a,b,sizeof(10 * 10));
}
