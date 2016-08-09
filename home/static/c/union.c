union Exam{
  int a;
  int *b;
};

void foo(){
  union Exam data;
  data.a = 0;
  
  *(data.b) = 1; //@violation(NOT_EXPECTED) NULL_DEREF
}
  
int main(){
  foo();
  return 1;
}
