#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>
void unlock() {
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
FILE *fp;
char buf[10] ="error";
fp = fopen("filename","w");
  pthread_mutex_lock(&mutex);
   if(some_error()) {
	fwrite(buf,1,10,fp);
	pthread_mutex_unlock(&mutex);
    }
    pthread_mutex_unlock(&mutex);
}

