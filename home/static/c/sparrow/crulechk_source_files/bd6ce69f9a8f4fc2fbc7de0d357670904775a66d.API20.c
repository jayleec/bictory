#define RC_NRM 0
#define RC_ERR -1

// Dummy function for the test
void pfmInitError() {
	return;
}

void badError() {
	int rc = 0;
	
    if(rc != RC_NRM) {
        return RC_ERR;		/* Violation */
    }
}

void goodError() {
    int rc = 0;
	
    if(rc != RC_NRM) {
        pfmInitError();
        return RC_ERR;
    }
}

void badError2() {
	int rc = 0;
	
    if(rc != RC_NRM) {
		if(rc > 1) {
			pfmInitError();
			return RC_ERR;
		} else {
			return RC_ERR;	/* Violation */
		}
    }
}

void goodError2() {
	int rc = 0;
	if(rc != RC_NRM) {
        pfmInitError();
        return RC_ERR;
    }
	
	return RC_ERR;
}