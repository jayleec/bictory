/* MEM07-C. Ensure that the arguments to calloc(), when multiplied, do not wrap */
#include <stdio.h>
#include <stdlib.h>

void mem07_bad(){
  unsigned int num_elements = 65530;

  long *buffer = (long *)calloc(num_elements, 4); //@violation INTEGER_OVERFLOW
  free(buffer);
  buffer = 0; 
}

int mem07_main(){
  mem07_bad();
  return 1;
}
