# 1 "/home/kskyj/sparrow4/util/testcode/c/MIS23.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/MIS23.c"
void foo(void)
{
  int div = 0;
  int mod = 0;
  unsigned int a = 20;
  unsigned int b = 40;

  div = (b+1) / (a+1);
  mod = b % a;
  mod = (b+1) % (a+1);
}
