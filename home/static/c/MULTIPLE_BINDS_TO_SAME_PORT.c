// @checker MULTIPLE_BINDS_TO_SAME_PORT
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

#define SO_REUSEADDR 1
#define SOCK_STREAM  0
#define SOL_SOCKET   0
#define INADDR_ANY   0
#define AF_INET      0

struct dummy_st {
  int s_addr;
};

struct sockaddr_in {
  int sin_family;
  int sin_port;
  struct dummy_st sin_addr
};

void bind_socket(){ 
	int server_sockfd; 
	int server_len; 
	struct sockaddr_in server_address; 
	int optval; 
	
	unlink("server_socket"); 
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	optval = 1; 
	
	setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)); 
	
	server_address.sin_family = AF_INET; 
	server_address.sin_port = 21; 
	server_address.sin_addr.s_addr = htonl(INADDR_ANY); // @violation MULTIPLE_BINDS_TO_SAME_PORT
	server_len = sizeof(struct sockaddr_in); 
	
	bind(server_sockfd, (struct sockaddr *) &server_address, server_len); 
}
