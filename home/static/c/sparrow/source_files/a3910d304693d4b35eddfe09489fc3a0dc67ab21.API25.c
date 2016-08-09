// Dummy function
char * getSSS() {
	return 0;
}

void badFoo(void) {
  char *TB_Feild;   
  int iVar;
  float fVar;
  char cVar;
  
  TB_Feild = "SSS";  /* Violation : do not use hard-coded value "SSS" */  
  iVar = 0;
  fVar = 12.5 + 29.4;
  cVar = 'a';
}

void goodFoo(void) {
  char *TB_Feild; 
  
  TB_Feild = getSSS();
}
