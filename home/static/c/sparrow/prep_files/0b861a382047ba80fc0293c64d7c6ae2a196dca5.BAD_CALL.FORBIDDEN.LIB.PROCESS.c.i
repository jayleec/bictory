# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.PROCESS.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.PROCESS.c"



typedef int pid_t;


pid_t fork_FB08();

void terminate_process(){
    int counter = 0;
    pid_t pid;
    pid = fork_FB08();
    exit(1);
}
