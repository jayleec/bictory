void INT00_1(){
  void *fp;
  int x;
  /* ... */
  if (fscanf(fp, "%ld", &x) < 1) { 
    /* handle error */
  }
}


void INT00_2(){
  unsigned int a, b;
  unsigned long c;
  /* Initialize a and b */
  a = 9999999999; 
  b = 9999999999;
  c = (unsigned long)a * b; /* not guaranteed to fit */ //@violation INTEGER_UNDERFLOW //@violation CAST_ALTERS_VALUE
}
