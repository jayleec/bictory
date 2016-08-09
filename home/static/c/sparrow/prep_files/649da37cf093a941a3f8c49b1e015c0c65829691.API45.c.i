# 1 "/home/kskyj/sparrow4/util/testcode/c/API45.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API45.c"
void badFoo(void)
{
    unsigned char index = 0;
    int sum = 0;
    do {
        sum += index;
        index++;
    } while (index < 1000);
}

void goodFoo(void)
{
    int index = 0;
    int sum = 0;
    while (index < 1000) {
        sum += index;
        index++;
    }
}
