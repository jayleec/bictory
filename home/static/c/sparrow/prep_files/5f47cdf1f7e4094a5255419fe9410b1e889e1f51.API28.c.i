# 1 "/home/kskyj/sparrow4/util/testcode/c/API28.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API28.c"



void funcOne(int o);
void funcTwo(int t);

extern void badUsage(void) {
    funcOne(1);
    catch :
    funcTwo(2);

}

extern void goodUsage(void) {
    funcOne(1);
    funcTwo(2);
    catch :
   funcOne(1);

}
