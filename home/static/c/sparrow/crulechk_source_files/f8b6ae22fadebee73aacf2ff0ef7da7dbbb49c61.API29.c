typedef int S32;

int badFuncProto(S32 badProtoParam[]);		
S32 goodFuncProto(int goodProtoParam[]);	/* Violation : Using the Redefined Type */

struct _badStruct {
	int badVar[10];							/* Violation : Using the Redefined Type */
	S32 goodVar[10];
} badStruct;

static long badContent[10];  				/* Violation : Using the Redefined Type */
void badFoo(long badNum) {
    int badCount[10];       				/* Violation : Using the Redefined Type */
    /* do something */
}   

static S32 goodContent[10];
void goodFoo(S32 goodNum) {
    S32 goodCount[10];    
    /* do something */
}

