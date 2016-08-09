void free_null(){
  int *p = 0;
  int *x = p;

  free(x);  //@violation FREE_NULL_POINTER
}
  
