void int32(){
  int si1, si2, sum;

  si1 = rand();
  si2 = rand();
  /* Initialize si1 and si2 */
  
  sum = si1 + si2; //@violation INTEGER_OVERFLOW
}

void int32_bad1(){
  signed int si1, si2, result;
  
  si1 = rand();
  si2 = rand();
  /* Initialize si1 and si2 */
  
  result = si1 - si2; //@violation INTEGER_OVERFLOW
}

void int32_safe2(){
  signed int si1, si2, result;
  
  si1 = rand();
  si2 = rand();
  
  /* Initialize si1 and si2 */
  
  if (((si1^si2) //@violation INTEGER_OVERFLOW
       & (((si1 ^ ((si1^si2)
                   & (1 << (sizeof(int)*2-1))))-si2)^si2)) < 0) {
    /* Handle error condition */
  }
  
}

void int32_safe1(){
  
  signed int si1, si2, sum;

  si1 = rand();
  si2 = rand();
  /* Initialize si1 and si2 */
  
  if ( ((si1^si2) | (((si1^(~(si1^si2) & INT_MIN)) + si2)^si2)) >= 0) {    //@violation INTEGER_OVERFLOW
    /* Handle error condition */
  } 
}
