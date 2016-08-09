int *gp;

void foo(){
  int *p = 0;
  bar(p);
}

void bar(int *p){
  if (p != 0) {
    *p = 100;
  }
}

void problem(){
  gp = 0;
  *gp = 10; //@violation NULL_DEREF
}

void bar2(int *p){
  if (p == 0){
    *p = 1; //@violation NULL_DEREF.MISSING_CHECK
  }
}
    
void bar3(int *p){
  int *x;
  int *p1 = 0;
  x = p1 + 5;
  *x = 10;
}
