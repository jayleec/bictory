# 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM.c"


void do_not_use_sizeof1(int a[]){
 int i;
 for(i = 0; i< sizeof(a) / sizeof(a[0]); i++)
  a[i] = 0;
}
