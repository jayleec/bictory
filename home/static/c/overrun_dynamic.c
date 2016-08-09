void overrun_dynamic(int c){
  int *x;
  int *y;
  if(c > 0){
    y = malloc(sizeof(int) * 1);
    if(y == 0) return;
  } else {
    y = malloc(sizeof(int) * 10);
    if(y == 0) return;
  }
  x = y;
  *(x + 5) = 'c'; //@violation OVERRUN.DYNAMIC
  
  free(y);
  return;
}

void setting(char *b){
  int i;
  for(i=0;i<10;i++){
    b[i] = 'a';
  }
}

void overrun_strcpy(int c){
  char buf[10];
  int buf2[10];
  int n;
  n = strlen(buf);
  opus1_print(n);
  n = sizeof(buf2);
  opus1_print(n);
  strncpy(buf2,buf,n);
}
