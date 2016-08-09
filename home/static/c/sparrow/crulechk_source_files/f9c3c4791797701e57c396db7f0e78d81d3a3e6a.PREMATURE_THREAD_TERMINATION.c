// @checker PREMATURE_THREAD_TERMINATION

// Dummy typedef
typedef unsigned int pthread_t;

// Dummy function
int pthread_create(pthread_t *, void *, void * (*)(void *), void *);

void * foo(void * data){ 
	return data;
} 

int foo2() { // @violation PREMATURE_THREAD_TERMINATION 
	pthread_t pth; 
	int a = 1; 
	
	if(pthread_create(&pth, 0, (void*(*)(void*))foo, (void*)&a) < 0){
		// Do something
	} 
	
	return 0; 
}
