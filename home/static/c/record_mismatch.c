void record1(int a, int b){
  make_CWM1021U01Req_I_RECORD(&a, b);
  
  destroy_CWM1021U01Req(getaddr_CWM1021U01Req());
}

void record2(int a, int b){
  make_CWM1021U01Req_I_RECORD(&a, b);

  return; //@violation LEAK.RECORD
}

