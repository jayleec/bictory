int order(char x)
{
    switch(x)
    {
        case '+' : 
        case '-' : return 2;
        case '%' : 
        case '*' : 
        case '/' : return 3; 	/* second return statement */
        default : return 0;  	/* third return statement */
    }
}

void another(int a) {
	if(a > 0) {
		return -1;
	} else if(a == 0) {
		return 0;				/* second return statement */
	} else {
		if(a % 2 == 0) {
			return -1;			/* third return statement */
		} else {
			return -2;			/* fourth return statement */
		}
	}
}