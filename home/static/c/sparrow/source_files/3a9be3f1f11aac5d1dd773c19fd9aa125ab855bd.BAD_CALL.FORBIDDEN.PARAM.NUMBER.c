// @checker BAD_CALL.FORBIDDEN.PARAM.NUMBER

void LB_call_WA(double, double, double);

void Func(const char * x) {	
	LB_call_WA(1.5, 2.3, 12.123); // @violation BAD_CALL.FORBIDDEN.PARAM.NUMBER
	
	// Do something ...
}
