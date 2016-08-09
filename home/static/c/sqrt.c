/******************************************************************************
Calculates the square root of a number (rounded down to the nearest int)
******************************************************************************/

int sqrtApprox(int x) {
  int i;
  if (x == 1){
    return 1;
  }
  for (i = 0; i < x; i++) {
    if (x / i < i) { // In the first iteration i == 0, potential divide-by-zero here //@violation DIV_BY_ZERO
      break;
    }
  }
  return i;
}
