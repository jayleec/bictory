void foo(void) {    
  int b = 20000;
  int c = 3000000;
  int start = 2147483647;
  int end = -2147483647;
    
  if (end - start > 0) {         /* Violation : shall not be underflowed. */
    /* do something */
  }
}