// @checker BAD_CALL.REQUIRED.PRE_CALL

// Dummy functions
void LcfApError_API22();
void LcfSetUIMsg_API22();

void FuncBad(const char * x) {	
	LcfSetUIMsg_API22(); // @violation BAD_CALL.REQUIRED.PRE_CALL
	LcfApError_API22();
}

void FuncGood(const char * x) {
	LcfApError_API22();
	LcfSetUIMsg_API22();
}
