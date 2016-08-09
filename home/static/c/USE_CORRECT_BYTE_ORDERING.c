#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define PF_INET 1
#define SOCK_STREAM 2
int socket(int a,int b,int c){
return 1;
}

int recv(int a,void * b,int c,int d){
return 1;
}
void use_correct_byte(){
/* sock is a connected TCP socket */
unsigned int num;
int sock = socket(PF_INET, SOCK_STREAM,0);
if (recv(sock, (void *)&num, sizeof(unsigned int), 0) < 0) {
 // USE_CORRECT_BYTE_ORDERING
   /* Handle error */
}
printf("We received %u from the network!\n", (unsigned int)num);

}



