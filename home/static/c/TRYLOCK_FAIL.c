#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void try_lock_fail() {
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
   char error1[10];
   char error2[20];
   FILE *fp;
   fp = fopen("filename","r");
   if(some_error()) {
        pthread_mutex_lock(&mutex);
        fread(error1,1,10,fp);
    
            pthread_mutex_trylock(&mutex);  // TRYLOCK_FAIL
            fread(error2,1,10,fp);
            pthread_mutex_unlock(&mutex);
        
        pthread_mutex_unlock(&mutex);
    }
}




