//////////////////////////////////////////////////////////////////////
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
//////////////////////////////////////////////////////////////////////

#define LOG_RUNNING_MESSAGE   "runnig .... "
#define LOG_TERMINATE_MESSAGE "terminate .... "
void run_termnate()
{
    set_step_terminate();
    output(LOG_RUNNING_MESSAGE); 
// BAD_ARGS.FORBIDDEN.AFTER_CALL
}
//////////////////////////////////////////////////////////////////////

#include <pthread.h>
#include <stdio.h>

void* worker_thread(void* dummy) {
int i;
int result;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
if((result=pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,&i)) != 0) {
// ASYNCHRONOUS_CANCEL_THREADS
/* handle error */
}
while (1) {
if ((result = pthread_mutex_lock(&mutex)) != 0) {
/* handle error */
}
//pthread_cleanup_push(mutex, NULL);
//pthread_cleanup_pop(1);
}
return NULL;
}
//////////////////////////////////////////////////////////////////////
void ensure_privilege(){
if (seteuid(getuid()) != 0) {
/* Handle error */
}
if (1) {
if (seteuid(0) != 0) {
/* Handle error */
}
}
if (setuid(getuid()) != 0) {
/* Handle error */
}
// ENSURE_PRIVILEGE_RELINQUISHMENT

}
//////////////////////////////////////////////////////////////////////
char char_type(){
   char a;
   int b;
   b = 25;
   a = b;   // INT_TO_CHAR
   printf("“int = %d char = %d\n", b, a);
return b;

}
////////////////////////////////////////////////////////////////////
void parser(char *command){
   char *token;
   token = strtok(command,"-"); // STRTOK_CHANGE_STRING
   printf("“%s\n",token);
   while(token = strtok(0,"-")){
      printf("“%s\n",token);
   }
   printf("%s\n",command);
}
////////////////////////////////////////////////////////////////////
void linkFile(char *file){
   char *buf;
   unsigned int length;
   struct stat lstat_info;
   int fd;
   if (lstat(file, &lstat_info) == -1) {
/* Handle error */
}
if (!S_ISLNK(lstat_info.st_mode)) {
fd = open(file, O_RDWR);
if (fd == -1) {
/* Handle error */
}
}
if (write(fd, buf, length) < length) {
// SYMBOLICK_LINK_RACE_CONDITION
/* Handle error */
}
}
////////////////////////////////////////////////////////////////////

static int static_a, static_b;
void foo(){
  int static_a,static_b; // REDUNDANT_NAME
}


////////////////////////////////////////////////////////////////////
