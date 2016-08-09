#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void bigbuf(){
   char buf[38582934]; // EXCESSIVE_STACK_DEPTH
}


