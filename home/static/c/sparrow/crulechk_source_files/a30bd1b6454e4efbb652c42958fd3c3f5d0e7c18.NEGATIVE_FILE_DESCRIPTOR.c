#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int negative_file_des(){
   char* rPort = getenv("rPort");
   int sockfd = -1;
   char buf[25];
   strncpy(buf, rPort, 25); 
   if(connect(sockfd,&buf, 10) < 0){
      // NEGATIVE_FILE_DESCRIPTOR
      exit(1);
   }
   return 0;
}



