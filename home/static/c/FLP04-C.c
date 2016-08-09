#include <stdio.h>

float currentBalance; /* User's cash balance */
void doDeposit() {
  float val;

  scanf("%f", &val);
  
  if(val >= 1000 - currentBalance) {
    /* Handle range error */
  }
 
  currentBalance += val; //@violation INTEGER_OVERFLOW
}
 
void doDeposit_good() {
  float val;
 
  scanf("%f", &val);
  if (isinf(val)) {
    /* Handle infinity error */
  }
  if (isnan(val)) {
    /* Handle NaN error */
  }
  if (val >= 1000 - currentBalance) {
    /* Handle range error */
  }
 
  currentBalance += val; //@violation(NOT_EXPECTED) INTEGER_OVERFLOW
}

int main(int argc, char *argv[]) {
  float val, currentBalance=0;
  scanf("%f", &val);
  currentBalance+=val;
  //  printf("%f\n", currentBalance);
  return 0;
}
