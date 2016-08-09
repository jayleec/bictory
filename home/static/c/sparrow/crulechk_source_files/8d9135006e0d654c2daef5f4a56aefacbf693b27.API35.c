typedef double newDouble;

void badFoo(void) {
  signed char sc[10];                 /* Violation : shall use the allowed array types. */
  signed short ssh[10];               /* Violation : shall use the allowed array types. */
  unsigned short int ushi[10];        /* Violation : shall use the allowed array types. */
  newDouble td[10];					  /* Violation : shall use the allowed array types. */
}

void goodFoo(void) {
  char  c[10];  
  short sh[10]; 
  int   i[10];
}
