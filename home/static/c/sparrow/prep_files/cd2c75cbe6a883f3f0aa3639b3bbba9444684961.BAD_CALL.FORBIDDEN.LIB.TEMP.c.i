# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.TEMP.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.TEMP.c"



void mktemp_FB12(const char *);

void make_temp(char * fname){
 if(fname != 0x00)
  mktemp_FB12(fname);
}
