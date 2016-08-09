// @checker BAD_MACRO.MULTI_STMT_WITHOUT_DO_WHILE

#define CAL(X, Y) X = X + Y; Y = X - Y; // @violation BAD_MACRO.MULTI_STMT_WITHOUT_DO_WHILE 

void muti_stmt_without(int var, int x, int y) {
	if(var == 0)
		CAL(x,y);
}
