# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.SIGNAL.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.SIGNAL.c"




void signal_FB10(int, void(*)());
void handler();

void signal_handler(){
 signal_FB10(0, handler);
}
