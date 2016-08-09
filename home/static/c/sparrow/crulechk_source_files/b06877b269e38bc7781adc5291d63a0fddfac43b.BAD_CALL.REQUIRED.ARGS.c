// @checker BAD_CALL.REQUIRED.ARGS

#define LBCALLWA_NUM 0

void LB_call_WA(int);

void Func() {
	LB_call_WA(0); // @violation BAD_CALL.REQUIRED.ARGS
	LB_call_WA(LBCALLWA_NUM);
}
