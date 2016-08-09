void shift_negative_bad1(){
  int p = 10;
  p = p << (-2); //@violation SHIFT_NEGATIVE
}
