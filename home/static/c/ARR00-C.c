/* ARR00-C. Understand how arrays work */
void arr00_bad1(int n){
  int *dis = &n;
  if (n > 5) {
    dis = (int *)malloc(10 * sizeof(int));
  } 
  
  *dis = 10; //@violation NULL_DEREF.MALLOC_FAILED

  if (n > 10){
    free(dis);
    return; //@violation(NOT_EXPECTED) LEAK.MEMORY 
  }
  
  if (n <= 5) { 
    return; //@violation(NOT_EXPECTED) LEAK.MEMORY
  }

  return; //@violation LEAK.MEMORY x
}

