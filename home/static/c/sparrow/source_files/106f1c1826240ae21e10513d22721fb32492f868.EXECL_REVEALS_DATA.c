#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>
#include <unistd.h>
void execl_error(){
(void) execl("login","-p","-d","-h","-s", getenv("USER"),0);

}
