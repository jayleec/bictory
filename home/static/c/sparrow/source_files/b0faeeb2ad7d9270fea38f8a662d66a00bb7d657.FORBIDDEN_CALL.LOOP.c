// @checker  FORBIDDEN_CALL.LOOP

// Dummy functions
void FCINLOOP_SUB(int);

void Func(int x) {
	int a;
	for(a=0; a<x; a++) { // In a loop
		FCINLOOP_SUB(a); // @violation FORBIDDEN_CALL.LOOP
	}
}
