char * getSSS() {
	return 0;
}

// Dummy strcpy function
void strcpy(char * dest, char * src) {
	return;
}

int badFoo(void) {
	char * TB_Feild;
	int var = 1;					/* Violation: hard-coded value is used */
	const int con = 1;				/* Violation: hard-coded value is used */
    
	TB_Feild = "SSS";				/* Violation: hard-coded value is used */
	
	if(var < 1) {					/* Violation: hard-coded value is used */
		var = var + 1;				/* Violation: hard-coded value is used */
	}
	
	strcpy(TB_Feild, "SSS"); 		/* Violation: hard-coded value is used */
	
	return 1;						/* Violation: hard-coded value is used */
}

void goodFoo(void) {
	char *TB_Feild; 
  
	strcpy(TB_Feild, getSSS());
}
