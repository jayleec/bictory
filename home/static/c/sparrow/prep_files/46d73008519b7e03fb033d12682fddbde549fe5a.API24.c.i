# 1 "/home/kskyj/sparrow4/util/testcode/c/API24.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API24.c"

void strcpy(char * dest, char * src) {
 return;
}

char * getSSS() {
 return 0;
}

void badFoo(void) {
 char * TB_Feild;

 strcpy(TB_Feild, "SSS");
 strcpy(TB_Feild, "NOT_TARGET");
}

void goodFoo(void) {
 char *TB_Feild;

 strcpy(TB_Feild, getSSS());
}
