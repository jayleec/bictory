void nh_memset(){
  char a[81];
  char b[12];

  opus1_print(strlen(b));
  opus1_print(sizeof(a));

  if(strlen(b) > sizeof(a)){
    memcpy(a,b,sizeof(a));
  } else {
    memcpy(a,b,strlen(b));
  }

}
