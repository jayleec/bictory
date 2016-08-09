void foo(){
  char *buff = (char *) malloc(256);
  
  if(!buff){
    return;
  }

  free(buff);
  
  *buff='c'; //@violation USE_AFTER_FREE
}

/* void printLine(void *buff){ */
/*   int x = (int) *buff; */
/* } */

void foo2(){
  char *buff = (char *) malloc(256);
  
  if(!buff){
    return;
  }

  free(buff);
  
  printLine(buff); //@violation USE_AFTER_FREE
}

