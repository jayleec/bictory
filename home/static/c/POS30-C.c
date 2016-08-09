extern int pathconf(char*, int);
int errno = 0;

void pos30_bad(){
  char array[100];
  int bufsize;
  int len;
  int symlink_max;
  char *buf;

  symlink_max = pathconf("/usr/bin/", 99);
  if (symlink_max == -1) {
    if (errno != 0) {
      /* handle error condition */
      return;
    }
    bufsize = 100000;
    return;
  }
  else {
    bufsize = 99+1;
  }
  
  buf = (char *)array;
  if (buf == 0) {
    /* handle error condition */
    return;
  }
  
  len = readlink("/usr/bin/perl", buf, bufsize); //@violation OVERRUN.STATIC.MEMSET 
  buf[len] = '\0';
}

void pos30_good(){
  char array[100];
  int bufsize;
  int len;
  int symlink_max;
  char *buf;

  symlink_max = pathconf("/usr/bin/", 99);
  if (symlink_max == -1) {
    if (errno != 0) {
      /* handle error condition */
      return;
    }
    bufsize = 10000;
  }
  else {
    bufsize = 99+1;
  }
  
  buf = (char *)array;
  if (buf == 0) {
    /* handle error condition */
    return;
  }
  
  len = readlink("/usr/bin/perl", buf, sizeof(buf) - 1);
  
  if(len != -1) {
    buf[len] = '\0';
  } else {
    return;
  }
}
