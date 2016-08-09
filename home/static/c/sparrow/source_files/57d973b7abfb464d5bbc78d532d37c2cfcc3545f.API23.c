#define SET_ERR set_err
#define RC_ERR -1

void set_err(char * type, char * disc);

int badError() {
    /* do something */
    return RC_ERR; /* Violation : Not found a log function call */
}

int goodError() {
    /* do something */
    SET_ERR("ERRORCode", "error number");
    return RC_ERR; 
}

int goodError2() {
	/* do something */
    SET_ERR("ERRORCode", "error number");
}

int badError2() {
    /* do something */
    return RC_ERR; /* Violation : Not found a log function call */
}