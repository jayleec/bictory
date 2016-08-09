void condition_value(int x){
  int y = x < 10;
  int z = x > 5;
  int g = 10;
  if (x == 7 && y && !z) {
    g = g / (g - 10); //@violation(NOT_EXPECTED) DIV_BY_ZERO
  }
}

void condition_value2(int x){
  int y = x < 10;
  int z = y < 1;
  int g = 10;
  if (x < 10 && z) {
    g = g / (g - 10); //@violation(NOT_EXPECTED) DIV_BY_ZERO
  }
}

