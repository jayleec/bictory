# 1 "/home/kskyj/sparrow4/util/testcode/c/MULTIPLE_BINDS_TO_SAME_PORT.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/MULTIPLE_BINDS_TO_SAME_PORT.c"
# 12 "/home/kskyj/sparrow4/util/testcode/c/MULTIPLE_BINDS_TO_SAME_PORT.c"
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
 server_sockfd = socket(0, 0, 0);
 optval = 1;

 setsockopt(server_sockfd, 0, 1, &optval, sizeof(optval));

 server_address.sin_family = 0;
 server_address.sin_port = 21;
 server_address.sin_addr.s_addr = htonl(0);
 server_len = sizeof(struct sockaddr_in);

 bind(server_sockfd, (struct sockaddr *) &server_address, server_len);
}
