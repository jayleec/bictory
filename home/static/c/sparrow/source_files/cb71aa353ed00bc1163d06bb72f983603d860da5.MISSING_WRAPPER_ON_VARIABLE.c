// @checker MISSING_WRAPPER_ON_VARIABLE

void PFM_ERR_API10(int, int);
int PfmNumber_API10(int);

void Func(const char * x) {	
	PFM_ERR_API10(0, 0); // @violation MISSING_WRAPPER_ON_VARIABLE
	PFM_ERR_API10(0, PfmNumber_API10(0));
	
	// Do something ...
}
