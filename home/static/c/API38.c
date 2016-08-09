void badFoo(void) {
  signed char *badSc;                 /* Violation : shall use the allowed pointer types. */
  signed short *badSsh;               /* Violation : shall use the allowed pointer types. */
  unsigned short int *badUshi;        /* Violation : shall use the allowed pointer types. */
}

void goodFoo(void) {
  char  *c;  
  short *sh; 
  int   *i;
}
