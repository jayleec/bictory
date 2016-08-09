void nice(int rc){
  int x = 0;
  rc = 0;
  
  if (rc != 0) { //REDUNDANT CONDITION 나오지 않게 조정 
    x = 1;
  } else {
    x = 2;
  }

}


void nice2(){
  long rc;
  
  rc = 0;  // UNUSED_VALUE 나오지 않게 조정
  return;
}
