void bar(){
}

void foo(int *x){
  if (x != 0){
    bar();
  } else {
    x = malloc(100);
  }

  if(x == 0){
    return;
  } 

  free(x);
  return;
}
