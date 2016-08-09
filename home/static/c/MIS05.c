struct badSt_1 {
	int abc;
	signed int   badVar1 : 3;    /* Violation : shall not be permitted */
	unsigned int badVar2 : 2;    /* Violation : shall not be permitted */
}; 

struct badSt_2 {
	int abc;
};

void foo(void) 
{
}
