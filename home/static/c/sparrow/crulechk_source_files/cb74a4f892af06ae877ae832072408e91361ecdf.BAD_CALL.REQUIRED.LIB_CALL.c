// @checker BAD_CALL.REQUIRED.LIB_CALL

// Dummy functions
void LB_call_WLC_exit();
void LB_call_WLC_need();

void Func() { // @violation BAD_CALL.REQUIRED.LIB_CALL
	LB_call_WLC_exit();
	
	// Do something ...
	// LB_call_WLC_need() missing
}
