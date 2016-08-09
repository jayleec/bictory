# 1 "/home/kskyj/sparrow4/util/testcode/c/API44.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API44.c"
void badLoop(void)
{
    int i = 0;
    for (i = 0; i < 10 ; ++i) {
        int k = i;

    }

}

void goodLoop(void)
{
    int i = 0;
    int k;
    for (i = 0; i < 10 ; ++i) {
        k = i;
    }

}
