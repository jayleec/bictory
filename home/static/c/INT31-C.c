void int31_bad1(){
  unsigned long int u_a = 9999999999999999;
  signed char sc;
  sc = (signed char)u_a; //@violation CAST_ALTERS_VALUE  //@violation CAST_ALTERS_VALUE
}

void int31_bad2(void) {
  signed int si = -2147483648;
  unsigned int ui = (unsigned int)si;  //@violation CAST_ALTERS_VALUE  //@violation CAST_ALTERS_VALUE
}
