void unreasonable_parameter_bad1(){
  int x = 1;
  
  int *y = malloc(x);
  
  int *z = malloc(x - 10); //@violation UNREASONABLE_PARAMETER 

  free(y);
  free(z);
}
