void double_close1(int n, void *x){
  int *p = malloc(100);
  if(n > 10){
    tpfree(p);
    ji_tpsyserr(x, "aaaaa", 1);
  }

  tpfree(p);
}
  
void double_free1(int n){
  void *fp = fopen("a.txt","r");
  if(n > 10){
    fclose(fp);

    ji_tpusrerr();
  }

  if(n > 20){
    fclose(fp);
    
    ji_tpusrerr();
  }

  fclose(fp);
}
  
