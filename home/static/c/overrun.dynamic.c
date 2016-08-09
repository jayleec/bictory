// make-4.0/rule.c
void *xmalloc(unsigned int size){
  void *result = malloc(size? size: 1);
  
  if(result == 0) exit(1);
  return result;
}

void create_pattern_rule(unsigned int n, char *str){
  int i;
  unsigned int *lens = xmalloc(n * 4); //문제: n * 4는 top이 되어 버림, n과의 관계가 사라지게 됨
  
  for(i = 0; i < n; ++i){
    lens[i] = strlen(str); //@violation(NOT_EXPECTED) OVERRUN.DYNAMIC
  }

  free(lens);
}


// 문제: 곱하기는 trigger로 표현이 불가함.
unsigned int *xmalloc_summary(unsigned int size){
  void *result = malloc(size * sizeof(unsigned int));
  
  if(result == 0) exit(1);
  return result;
}

void call_summary(){
  unsigned int *p = xmalloc_summary(1);

  p[100] = 10;
  free(p);
}
