// @checker BAD_CALL.LIBRARY.MEMORY

// Dummy define
typedef unsigned int size_t;

// Dummy function
void * malloc_FB06(void *, size_t);
void realloc_FB06();

void memory(char * buf){	
	buf = (char *)malloc_FB06(buf, sizeof(char *) * 10); // @violation BAD_CALL.LIBRARY.MEMORY	
	realloc_FB06();
	// Do something...
}
