#define TRUE  1
#define FALSE 0

void badFoo(void)
{
    int abc = 0;
	int edf = 1;
    
    if(abc == TRUE) {    /* Violation : should be compared with FALSE */
        abc = 20;
    } else if(abc == (edf - 1)) {
		abc = 30;
	}
}

void goodFoo(void)
{
    int abc = 0;
    
    if(abc != FALSE) {
        abc = 20;
    }
}
