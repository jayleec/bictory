// FIO37-C. Do not assume that fgets() or fgetws() returns a nonempty string when successful
void fio37_bad(int n){
  char buf[10];
  int index = 0;
  if(fgets(buf,sizeof(buf), stdin) == 0){
	return;
 }
 
  if(n > 10){
    strcpy(buf, "abc");
  }
  index = strlen(buf);
  n = n - 10;
  if (n <= 0){
    index = 100/ index;  //@violation DIV_BY_ZERO
  } else {
    buffer[index - 1] = '\0';
  }
}

void fio37_good(void) {
  char buf[1024];
  char *p;
 
  if (fgets(buf, sizeof(buf), stdin)) {
    p = strchr(buf, '\n');
    if (p) {
      *p = '\0';
    }
  } else {
    /* Handle error */
  }
}
