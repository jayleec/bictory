/* FIO08-C. Take care when calling remove() on an open file */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fio08_bad1(){
  char *file_name = "text1.txt";
  void *file;
  
  /* Initialize file_name */
 
  file = fopen(file_name, "w+");
  if (file == 0) {
    /* Handle error condition */
  }
  
  /* ... */
  
  if (remove(file_name) != 0) {  //@violation RACE_CONDITION
    /* Handle error condition */
  }
  
  /* Continue performing I/O operations on file */
  
  fclose(file);

}

void fio08_good1(){

  void *file;
  char *file_name = "text2.txt";
  
  /* Initialize file_name */
  
  file = fopen(file_name, "w+");
  if (file == 0) {
    /* Handle error condition */
  }
  
  if (unlink(file_name) != 0) {
    /* Handle error condition */
  }
  
  /* Continue performing I/O operations on file */
  
  fclose(file);
  
}
