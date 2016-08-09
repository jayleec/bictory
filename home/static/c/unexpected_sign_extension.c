void use_bad1(int x){
  unsigned int y;
  x = -100;
  y = x; //@violation CAST_ALTERS_VALUE //@violation UNEXPECTED_SIGN_EXTENSION
}
