/* FLP34-C. Ensure that floating-point conversions are within range of the new type */
#include <float.h>
#include <limits.h>

void flp34_bad(float f_a, int m) {
  int i_a;
  int n; 
  if (m > 0){
    i_a =  f_a; //@violation CAST_ALTERS_VALUE
    n = 1;
  } else {
    n = 0;
  }
  
  if (m > 0 && n = 0){
    i_a = f_a; //@violation(NOT_EXPECTED) CAST_ALTERS_VALUE
  }
}

