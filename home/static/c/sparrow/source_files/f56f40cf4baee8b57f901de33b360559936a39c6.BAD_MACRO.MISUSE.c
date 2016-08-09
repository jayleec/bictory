// @checker BAD_MACRO.MISUSE
#define pthread_cleanup_push(a) push(a)
#define pthread_cleanup_pop pop

// Dummy functions
void push(int);
void pop();

void macro_misuse(int x){ // @violation BAD_MACRO.MISUSE
	pthread_cleanup_push(x);  
} 
