# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_PRIVILEGE_RELINQUISHMENT.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_PRIVILEGE_RELINQUISHMENT.c"





int setuid(int);
int setgid(int);
int getuid();
int getgid();

void func() {
 if(setuid(getuid()) == -1){

 }
 if(setgid(getgid()) == -1){

 }
}
