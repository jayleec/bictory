typedef double newDouble;

void badFoo(void) {
  signed char sc;                 /* Violation : shall use the allowed basic types. */
  signed short ssh;               /* Violation : shall use the allowed basic types. */
  unsigned short int ushi;        /* Violation : shall use the allowed basic types. */
  newDouble td;					  /* Violation : shall use the allowed basic types. */
}

void goodFoo(void) {
  char  c;  
  short sh; 
  int   i;
}
