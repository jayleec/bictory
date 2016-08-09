# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.REPLACE_SECURE_FUNCTIONS.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.REPLACE_SECURE_FUNCTIONS.c"





typedef int FILE;
FILE * fopen(const char * filename, const char * mode);

void func() {

 FILE * a;
 a = fopen("file", "a");
}
