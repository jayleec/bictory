#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
 
enum { MAXLINE = 1024 };
char *info = NULL;
 
void log_message(void) {
  fprintf(stderr, info);	/* Violation */
}
 
void handler(int signum) {
  log_message();	/* Violation */
  free(info);		/* Violation */
  info = NULL;
}
 
int SIG_main(void) {
  if (signal(SIGINT, handler) == SIG_ERR) {
    /* Handle error */
  }
  info = (char*)malloc(MAXLINE);
  if (info == NULL) {
    /* Handle Error */
  }
 
  while (1) {
    /* Main loop program code */
 
    log_message();
 
    /* More program code */
  }
  return 0;
}
