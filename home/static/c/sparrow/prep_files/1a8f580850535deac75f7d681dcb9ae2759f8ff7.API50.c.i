# 1 "/home/kskyj/sparrow4/util/testcode/c/API50.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API50.c"
int order(char x)
{
    switch(x)
    {
        case '+' :
        case '-' : return 2;
        case '%' :
        case '*' :
        case '/' : return 3;
        default : return 0;
    }
}

void another(int a) {
 if(a > 0) {
  return -1;
 } else if(a == 0) {
  return 0;
 } else {
  if(a % 2 == 0) {
   return -1;
  } else {
   return -2;
  }
 }
}
