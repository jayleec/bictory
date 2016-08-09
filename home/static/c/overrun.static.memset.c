struct node {
  char a[100];
  int b[100];
};

void over_memset(int *x, int n){
  char y[100];
  if (n < sizeof(y) + 1) return;
  memcpy(y,x,n); //@violation OVERRUN.STATIC.MEMSET.BAD_COND
}

void caller1(){
  char x[1000];
  over_memset(x, 200);
}

void type_over_memset2(struct node *x){
  x->a[200] = 'c'; //@violation TYPE_OVERRUN.STATIC
}

void type_over_memset(struct node *x){
  struct node *y = (struct node *)malloc(sizeof(struct node) * 1);
  
  char *z = y;
  if(y == 0) return;
  z[2] = 100;
  z[200] = 127;
  z[600] = 'p'; //@violation OVERRUN.DYNAMIC
  free(y);
}

void type_over_memset3(struct node *x, int n){
  if (n >= 200) return;
  x->a[n] = 'c'; //@violation TYPE_OVERRUN.BAD_COND
}

void type_over_memset4(struct node *x, int n){
  if (n >= 99) return;
  x->a[n] = 'c'; //@violation(NOT_EXPECTED) TYPE_OVERRUN.BAD_COND
}

void type_under_memset5(struct node *x, int n){
  if (n >= 0) return;
  x->a[n] = 'c'; //@violation TYPE_UNDERRUN.BAD_COND
}

void type_over6(int n){
  struct node x; 
  char z[1000];
  memset(x.a, 0, 10000); //@violation TYPE_OVERRUN.MEMSET
}

void type_over7(int n){
  struct node x; 
  if(n > 200) return; 
  memset(x.a, 0, n); //@violation TYPE_OVERRUN.MEMSET.BAD_COND
}

void type_under8(int n){
  struct node x; 
  opus1_print(1);
  memset(x.a, 0, -10); //@violation TYPE_UNDERRUN.MEMSET
  opus1_print(2);
}

void type_under9(int n){
  struct node x; 
  if(n >= 0) return; 
  memset(x.a, 0, n); //@violation TYPE_UNDERRUN.MEMSET.BAD_COND
}


  
