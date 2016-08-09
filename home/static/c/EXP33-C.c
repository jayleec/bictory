#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_negative(int number) {
  int sign;
  int *sign_flag = &sign;

  if (number > 0)
    *sign_flag = 1;
  else if (number < 0)
    *sign_flag = -1; 
  
  return sign < 0; //@violation UNINIT
}

 
int do_auth(void) {
  char *username;
  char *password;
 
  /* Get username and password from user, return -1 if invalid */
  return -1;
}
 
void report_error(const char *msg) {
  const char *error_log;
  char buffer[24];
 
  sprintf(buffer, "Error: %s", error_log);
  printf("%s\n", buffer);
}
 
int main(void) {
  if (do_auth() == -1) {
    report_error("Unable to login");
  }
  return 0;
}

void EXP33_g(double *a, unsigned int n) {
  unsigned int i;
  a = (double *)realloc(a, (n * 2 + 1) * sizeof(double));
  if (a != 0) {
    for (i = 0; i != n * 2 + 1; ++i) {
      if (a[i] < 0) {  //@violation UNINIT
        a[i] = -a[i]; //@violation UNINIT 
      }
    }
  
    /* ... */
    free(a);
  }
}
