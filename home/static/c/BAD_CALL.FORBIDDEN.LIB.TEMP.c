// @checker BAD_CALL.FORBIDDEN.LIB.TEMP
#define NULL 0x00

void mktemp_FB12(const char *);

void make_temp(char * fname){
	if(fname != NULL)
		mktemp_FB12(fname); // @violation BAD_CALL.FORBIDDEN.LIB.TEMP
}
