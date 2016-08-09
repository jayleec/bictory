# 1 "/home/kskyj/sparrow4/util/testcode/c/PREMATURE_THREAD_TERMINATION.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/PREMATURE_THREAD_TERMINATION.c"



typedef unsigned int pthread_t;


int pthread_create(pthread_t *, void *, void * (*)(void *), void *);

void * foo(void * data){
 return data;
}

int foo2() {
 pthread_t pth;
 int a = 1;

 if(pthread_create(&pth, 0, (void*(*)(void*))foo, (void*)&a) < 0){

 }

 return 0;
}
