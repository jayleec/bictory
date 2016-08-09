# 1 "/home/kskyj/sparrow4/util/testcode/c/FBD15.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/FBD15.c"
void badFoo(void)
{
  int badA[5];
  int i = 3;
  badA[2] = 10;
  badA[i] = 10;
}

void goodFoo(void)
{
  int goodA[5]={0,1,2,3,4};
  *goodA = 10;
}
