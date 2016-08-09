#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>
void double_lock() {
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
   char error1[10];
   char error2[20];
   FILE *fp; 
   fp = fopen("filename","r");
   if(some_error()) {
	pthread_mutex_lock(&mutex);
	fread(error1,1,10,fp);
	if(some_error2()){
	    pthread_mutex_lock(&mutex);
      	    fread(error2,1,10,fp);
	    pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_unlock(&mutex);
    } 
}



