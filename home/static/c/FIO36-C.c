/* FIO36-C. Do not assume a newline character is read when using
   fgets() */
void fio36_bad1(){

char buf[BUFSIZ + 1];
 
if (fgets(buf, sizeof(buf), stdin)) {
  if (*buf) { /* see FIO37-C */
    buf[strlen(buf) - 1] = '\0';
  }
}
else {
  /* Handle error condition */
}
}

void fio36_good1(){
char buf[BUFSIZ + 1];
char *p;
 
if (fgets(buf, sizeof(buf), stdin)) {
  p = strchr(buf, '\n');
  if (p) {
    *p = '\0';
  }
}
else {
  /* Handle error condition */
}
}
