void int08(){
  short i = 32766 + 1;
  short x = 1;
  /* ... */
  if (i + x <= i) {   //@violation INTEGER_OVERFLOW
    /* handle overflow */
  }
}
