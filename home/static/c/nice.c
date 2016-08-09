int x;

void normal(void *context){
  pfmDbioOpenCursorArray("aabbcc_vf001", context, 0, 10);
  
  /* 자원사용 */
  pfmDbioFetchCursorArray("aabbcc_vf001", 100, context);

  /* 해제 -> 해제 후 자원사용시도하면 에러!! */
  pfmDbioCloseCursorArray("aabbcc_vf001");
}


void problem1(void *context){
  // 1) 커서 오픈 
  pfmDbioOpenCursor("queryname", context, 0, 10);
  
  // 2) 커서로부터 데이터 FETCH
  pfmDbioFetchCursor("queryname", context);
  
  // 3) 커서 Close
  pfmDbioCloseCursor("queryname");

  //4) 다시 커서로부터 데이터 FETCH   --> !!!!!!!!!프로그램 비정상 종료 발생!!!!!!!!!
  pfmDbioFetchCursor("queryname", context); //@violation USE_AFTER_CLOSE
}
  
void problem2(void *context){
  int i;
  x = 100;
  pfmDbioOpenCursor("queryname", context, 0, 10);
  for(i=0; i < 100; i++) {
    pfmDbioFetchCursor("queryname", context);
    if(x>10)
      {
        pfmDbioCloseCursor("queryname");  
        continue;
        
      } else
      {
        break;
      }
    
  }
  pfmDbioCloseCursor("queryname"); //@violation DOUBLE_CLOSE.CURSOR
}

void problem3(void *context){
  pfmDbioOpenCursor("queryname", context, 0, 10);
  while(1) {
    pfmDbioFetchCursor("queryname", context);
    if(x > 10)
      {
        pfmDbioCloseCursor("queryname");  
        continue;
        
      } else
      {
        break;
      }
    
  }
  pfmDbioCloseCursor("queryname"); 
}

