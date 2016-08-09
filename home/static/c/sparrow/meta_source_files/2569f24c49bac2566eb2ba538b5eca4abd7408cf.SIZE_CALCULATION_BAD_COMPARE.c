#include </usr/include/stdio.h>
#include <stdlib.h>
#include <string.h>
int getuid() {
return 0;
 }
int geteuid() {
 return 0;
 }
void func(){
if(getuid == 0 || geteuid == 0){ // BAD_COMPARE
		     // Do something
 }
}

void function (int length){
		   double *p;
		   p = (double*)malloc(length * sizeof(int)); // SIZE_CALCULATION
}
