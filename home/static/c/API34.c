typedef int S32;

struct badTag {
    int weight;      		/*  Violation : Using the Redefined Type  */
	int * weightPointer;	/*  Violation : Using the Redefined Type  */
};  

struct goodTag {
    S32 weight;
	S32 weightPointer[10]; 
};  
