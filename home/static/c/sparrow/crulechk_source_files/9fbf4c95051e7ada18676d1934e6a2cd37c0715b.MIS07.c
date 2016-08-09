extern int count;			/* Violation : remove the extern specifier */

void mis07(int abc);	/* Violation : remove the extern specifier */

void mis07(int abc) {	/* Violation : remove the static specifier */  
    static int state;		/* Violation : remove the static specifier */
    /* do something */
}   
