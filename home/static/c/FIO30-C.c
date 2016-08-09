/* FIO30-C. Exclude user input from format strings */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void fio30_bad1() {
  int ret;
  const char *user = getenv("USER");
  /* User names are restricted to 256 characters or less */
  static const char msg_format[] = "%s cannot be authenticated.\n";
  unsigned int len = strlen(user) + sizeof(msg_format); //@violation NULL_DEREF.RETURN_NULL
  char *msg = (char *)malloc(len);
  if (msg == 0) {
    /* Handle error */
  }
  ret = snprintf(msg, len, msg_format, user);
  if (ret < 0) /* Handle error */ ;
  else if (ret >= len) /* Handle truncated output */ ;
 
  fprintf(stderr, msg); //@violation INFORMATION_LEAK
  free(msg);
}


void fio30_good1() {
  int ret;
  /* User names are restricted to 256 characters or less */
  const char *user = getenv("USER");
  static const char msg_format[] = "%s cannot be authenticated.\n";
  unsigned int len = strlen(user) + sizeof(msg_format); //@violation NULL_DEREF.RETURN_NULL
  char *msg = (char *)malloc(len);
  if (msg == 0) {
    /* Handle error */
  }
  ret = snprintf(msg, len, msg_format, user);
  if (ret < 0) /* Handle error */ ;
  else if (ret >= len) /* Handle truncated output */ ;
 
  if (fputs(msg, stderr) == 0) {
    /* Handle error */
  }
  free(msg);
}
