int main (){
  int *x = 0;

  for (;;){
    opus1_print(1);
    *x = 1; //@violation NULL_DEREF
  } 
  return 1;
}
    
