/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:51 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.PROCESS.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.PROCESS.c"
typedef int pid_t;


extern pid_t fork_FB08();

extern void terminate_process();



extern int exit();
#line 9
void terminate_process() {
auto int __14_9_counter = 0;
auto pid_t __15_11_pid;
__15_11_pid = (fork_FB08());
exit(1); 
}
