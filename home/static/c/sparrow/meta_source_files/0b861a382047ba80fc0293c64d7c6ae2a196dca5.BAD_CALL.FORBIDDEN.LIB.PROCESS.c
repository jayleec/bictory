// @checker BAD_CALL.FORBIDDEN.LIB.PROCESS

// Dummy typedef
typedef int pid_t;

// Dummy function
pid_t fork_FB08();

void terminate_process(){
    int   counter  = 0;
    pid_t pid;
    pid = fork_FB08();  // @violation BAD_CALL.FORBIDDEN.LIB.PROCESS
    exit(1);
}
