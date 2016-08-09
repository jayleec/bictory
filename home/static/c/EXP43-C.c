#include <string.h>

void exp43_bad(){
  char c_str[] = "test string";
  char *ptr1 = c_str;
  char *ptr2; 

  ptr2 = ptr1 + 3;
  
  memcpy(ptr2,ptr1,6); //@violation MEMCPY_WITH_OVERLAPPING_REGIONS
}
