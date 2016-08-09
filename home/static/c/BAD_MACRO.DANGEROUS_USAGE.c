// @checker BAD_MACRO.DANGEROUS_USAGE

#define pow(a) ((a)*(a)) // @violation BAD_MACRO_DANGEROUS_USAGE

void dangerous_macro_usage(){
	int b = 3;
	int c = 24 * pow(b);
}
