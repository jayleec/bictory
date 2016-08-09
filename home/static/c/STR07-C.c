/* STR07-C. Use the bounds-checking interfaces for remediation of
   existing string manipulation code */

/* The following noncompliant code overflows its buffer if msg is too long, and it has undefined behavior if msg is a null pointer. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str07_bad1(const char *msg) {
  static const char prefix[] = "Error: ";
  static const char suffix[] = "\n";
  char buf[10];
  char local_msg[100];
  strcpy(local_msg,msg);
  strcpy(buf, prefix); 
  strcat(buf, local_msg);     //@violation OVERRUN.STATIC.STRCPY
  strcat(buf, suffix);
  fputs(buf, stderr); 
}


void str07_good1(const char *msg) {
  int err;
  static const char prefix[] = "Error: ";
  static const char suffix[] = "\n";
  char buf[10];
 
  err = strcpy_s(buf, sizeof(buf), prefix);
  if (err != 0) {
    /* Handle error */
  }
 
  err = strcat_s(buf, sizeof(buf), msg);
  if (err != 0) {
    /* Handle error */
  }
 
  err = strcat_s(buf, sizeof(buf), suffix);
  if (err != 0) {
    /* Handle error */
  }
 
  fputs(buf, stderr);
}

void str07_call(){
  str07_bad1("12345678901234567890");
  str07_bad1(0);
}


void main(){
  str07_call();
}
