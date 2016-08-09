void problem(int x, int y){
  if (x != 1) exit(0);

  if (x < 0){
    assert(x == 0);
    x = x / 0;
  }
  x = y / (x - 1); 
}
    
void problem2(){
  int *p = 0;

  assert(p);

  *p = 10;
}
