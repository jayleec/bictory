# 1 "/home/kskyj/sparrow4/util/testcode/c/FORBIDDEN_CALL.LOOP.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/FORBIDDEN_CALL.LOOP.c"



void FCINLOOP_SUB(int);

void Func(int x) {
 int a;
 for(a=0; a<x; a++) {
  FCINLOOP_SUB(a);
 }
}
