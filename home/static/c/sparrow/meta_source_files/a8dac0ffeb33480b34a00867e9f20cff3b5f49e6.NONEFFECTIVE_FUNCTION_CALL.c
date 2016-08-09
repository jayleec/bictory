#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
void noneffect(){
   char buf[10];
   memset(buf, 10, '\0');  // NONEFFECTIVE_FUNCTION_CALL
 }
