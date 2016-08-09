/* FIO01-C. Be careful using functions that use file names for identification */
/* RACE_CONDITION */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fio01_bad1(){
  char *file_name = "test.txt"; 
  void *f_ptr;
  
  /* initialize file_name */
 
  f_ptr = fopen(file_name, "w"); // open a file???
  if (f_ptr == 0) {
    /* Handle error */
    return;
  }
  
  /*... Process file ...*/
  
  if (fclose(f_ptr) != 0) {
    /* Handle error */
    exit(1);
  }
  
  if (remove(file_name) != 0) { //@violation RACE_CONDITION
  /* Handle error */
    return;
  }
}

void fio01_bad2(){
  char *file_name = "test2.txt"; 
  void *f_ptr;
 
  /* initialize file_name */
  
  f_ptr = fopen(file_name, "w"); //open a file???
  if (f_ptr == 0)  {
    /* Handle error */
    return;
  }
  
  /* ... */
  
  if (chmod(file_name, 1) == -1) { //@violation RACE_CONDITION
    /* Handle error */
    exit(1);
  }
  fclose(f_ptr);
}

void fio01_safe(){
  char *file_name = "test3.txt";
  int fd;
  
  /* initialize file_name */
  
  fd = open(
            file_name,
            0 | 0 | 0,
            1
            );
  if (fd == -1) {
    /* Handle error */
  }
  
  /* ... */
  
  if (fchmod(fd, 1) == -1) {
    /* Handle error */
  }
  close(fd);
}
