// @checker FUNCTION_DEFINITION_TYPE_MISMATCH

typedef int SINT32;
int func(int);

int func(SINT32 x) { // @violation FUNCTION_DEFINITION_TYPE_MISMATCH
	// Do something ...
	return x;	
}
