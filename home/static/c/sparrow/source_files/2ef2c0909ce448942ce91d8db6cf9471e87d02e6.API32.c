typedef int S32;

int * badFuncProto(S32 * badProtoParam);	/* Violation : Using the Redefined Type   */
S32 * goodFuncProto(int * goodProtoParam);	/* Violation : Using the Redefined Type   */

struct _badStruct {	
	int * badVar;							/* Violation : Using the Redefined Type   */
	S32 * goodVar;
} badStruct;

static long * badContent;  					/* Violation : Using the Redefined Type   */
void badFoo(long * badNum) {				/* Violation : Using the Redefined Type   */
    int * badCount;       					/* Violation : Using the Redefined Type   */
    /* do something */
}   

static S32 * goodContent;
void goodFoo(S32 * goodNum) {
    S32 * goodCount;    
    /* do something */
}

