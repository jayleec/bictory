typedef int S32;

struct _badStruct {
	int badVar;				/* Violation : Using the Redefined Type   */
	S32 goodVar;
} badStruct;

static long badContent;  	/* Violation : Using the Redefined Type   */
void badFoo(long badNum) {
    int badCount;       	/* Violation : Using the Redefined Type   */
    /* do something */
}   

static S32 goodContent;
void goodFoo(S32 goodNum) {
    S32 goodCount;    
    /* do something */
}
