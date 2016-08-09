// Dummy strcpy function
void strcpy(char * dest, char * src) {
	return;
}

char * getSSS() {
	return 0;
}

void badFoo(void) {
	char * TB_Feild;   
    
	strcpy(TB_Feild, "SSS");		/* Violation : do not use hard-coded value "SSS" */  
	strcpy(TB_Feild, "NOT_TARGET");
}

void goodFoo(void) {
	char *TB_Feild; 
  
	strcpy(TB_Feild, getSSS());
}
