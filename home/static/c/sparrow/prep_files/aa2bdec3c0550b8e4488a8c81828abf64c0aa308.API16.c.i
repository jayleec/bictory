# 1 "/home/kskyj/sparrow4/util/testcode/c/API16.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API16.c"
char * getSSS() {
 return 0;
}


void strcpy(char * dest, char * src) {
 return;
}

int badFoo(void) {
 char * TB_Feild;
 int var = 1;
 const int con = 1;

 TB_Feild = "SSS";

 if(var < 1) {
  var = var + 1;
 }

 strcpy(TB_Feild, "SSS");

 return 1;
}

void goodFoo(void) {
 char *TB_Feild;

 strcpy(TB_Feild, getSSS());
}
