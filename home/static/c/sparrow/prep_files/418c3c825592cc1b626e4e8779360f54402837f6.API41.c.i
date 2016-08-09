# 1 "/home/kskyj/sparrow4/util/testcode/c/API41.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API41.c"



void badFoo(void)
{
    int abc = 0;
 int edf = 1;

    if(abc == 1) {
        abc = 20;
    } else if(abc == (edf - 1)) {
  abc = 30;
 }
}

void goodFoo(void)
{
    int abc = 0;

    if(abc != 0) {
        abc = 20;
    }
}
