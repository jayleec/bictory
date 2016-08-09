# 1 "/home/kskyj/sparrow4/util/testcode/c/sub.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/sub.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/sub.h" 1



int sum(int a, int b);
int substract(int a, int b);
double divide(int a, int b);
long multiply(int a, int b);
# 2 "/home/kskyj/sparrow4/util/testcode/c/sub.c" 2
# 33 "/home/kskyj/sparrow4/util/testcode/c/sub.c"
struct _member
{
 int _a;
};


int sub_test()
{
 struct _member member;

 int a = 0;
 int b = 20;
 int c = 30;

 if (a == 0)
 {
  member._a = 10;
 }
 else if (a == 1)
 {
  member._a = 10;
 }
 else
 {
  switch (b)
  {
  case 0:
   member._a = 10;
   break;
  case 1:
   member._a = 10;
   break;
  default:
   member._a = 10;
   break;
  }
  member._a = 10;
 }

 return a + b + c;
}

int sum(int a, int b)
{
 return a + b;
}

int substract(int a, int b)
{
 return a - b;
}

double divide(int a, int b)
{
 if (b != 0)
  return a / b;
 return 0;
}
long multiply(int a, int b)
{
 return a * b;
}
