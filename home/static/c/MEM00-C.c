/* MEM00-C. Allocate and free memory in the same module, at the same
   level of abstraction */

int verify_size(char *list, unsigned int size) {
  if (size < 32) {
    /* Handle error condition */
    free(list);
    return -1;
  }
  return 0;
}
 
void mem00_bad1() {
  int number = 33;
  char *list = (char *)malloc(number);
  if (list == 0) {
    /* Handle allocation error */
    return;
  }

  if (verify_size(list, number) == -1) {
      free(list); //@violation(NOT_EXPECTED) DOUBLE_FREE
      return;
  }
 
  /* Continue processing list */
  free(list); 
}

void mem00_bad2(int x){
  char *p = malloc(x);
  
  if(p != 0) free(p);

  if(x > 0) free(p); //@violation DOUBLE_FREE
}

void myfree(char *p, int n){
    free(p);
}

void simple_prob(){
  int n=0;
  char *p = malloc(100);
  myfree(p,n);
  free(p);  //@violation DOUBLE_FREE
}
