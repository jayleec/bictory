// @checker BAD_CALL.INCORRECT_SIZEOF.MEMCPY

// Dummy function
void memcpy(const char *, const char *, int);

void foo(){
	char a[100];
	char b[100];
	int * ref = a;
	
	memcpy(a,b,sizeof(ref)); // @violation BAD_CALL.INCORRECT_SIZEOF.MEMCPY 
	memcpy(a,b,sizeof(10 * 10)); // @violation BAD_CALL.INCORRECT_SIZEOF.MEMCPY
}
