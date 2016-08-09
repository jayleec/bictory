struct node {
  int a;
  struct node *x;
};

int module1(struct node *context){
  int rc;
  rc = unknown();
  if(rc != 0) {
    switch (rc){
    case 1:
      pfmDbioCloseCursor("AAA");
      return 0;
      
    default:
      pfmDbioCloseCursor("AAA");
      return 0;
    }

  } else {


  }


  module18(context);
  
  return 1;
}

void module18(struct node context){
  int rc;
  rc = unknown();
  if(rc != 0) {
      pfmDbioCloseCursor("AAA");
      return 0;
  }
}  

void double_close(int n){
  if (n > 10){
    pfmDbioCloseCursor("abc"); //@violation(NOT_EXPECTED) DOUBLE_CLOSE.CURSOR
  } else {
    pfmDbioCloseCursor("abc");
  }
}

void run_error(){
  int x = top();
  double_close(x); 
}




