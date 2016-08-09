void int30(){
  unsigned int ui1, ui2, usum;
  
  /* Initialize ui1 and ui2 */
  ui1 = rand();
  ui2 = rand();
  usum = ui1 + ui2; //@violation INTEGER_OVERFLOW
}

void int30_bad(){
  unsigned int ui1, ui2, udiff;
  
  /* Initialize ui1 and ui2 */
  ui1 = rand();
  ui2 = rand();
  
  udiff = ui1 - ui2; //@violation INTEGER_OVERFLOW
}

void int30_safe1(){

  unsigned int ui1, ui2, usum;
  
  ui1 = unknown();
  ui2 = unknown();
  /* Initialize ui1 and ui2 */
 
  if (UINT_MAX - ui1 < ui2) {
    /* handle error condition */
  }
  else {
    usum = ui1 + ui2;
  }
}


void int30_safe2(){
  unsigned int ui1, ui2, usum;

  ui1 = unknown();
  ui2 = unknown();
  
  /* Initialize ui1 and ui2 */
  
  usum = ui1 + ui2;
  if (usum < ui1) {
    /* handle error condition */
  }
}
