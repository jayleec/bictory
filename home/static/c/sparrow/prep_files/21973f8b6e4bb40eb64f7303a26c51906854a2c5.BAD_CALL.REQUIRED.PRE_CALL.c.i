# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.PRE_CALL.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.PRE_CALL.c"



void LcfApError_API22();
void LcfSetUIMsg_API22();

void FuncBad(const char * x) {
 LcfSetUIMsg_API22();
 LcfApError_API22();
}

void FuncGood(const char * x) {
 LcfApError_API22();
 LcfSetUIMsg_API22();
}
