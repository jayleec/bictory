/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:51 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/MULTIPLE_BINDS_TO_SAME_PORT.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 12 "/home/kskyj/sparrow4/util/testcode/c/MULTIPLE_BINDS_TO_SAME_PORT.c"
struct dummy_st;



struct sockaddr_in;
#line 39
struct _ZZ11bind_socketE8sockaddr_3; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 12
struct dummy_st {
int s_addr;};


struct sockaddr_in {
int sin_family;
int sin_port;
struct dummy_st sin_addr;};


extern void bind_socket();
#line 28
extern int unlink();
extern int socket();


extern int setsockopt();



extern int htonl();


extern int bind();
#line 22
void bind_socket() {
auto int __17_6_server_sockfd;
auto int __18_6_server_len;
auto struct sockaddr_in __19_21_server_address;
auto int __20_6_optval;

unlink(("server_socket"));
__17_6_server_sockfd = (socket(0, 0, 0));
__20_6_optval = 1;

setsockopt(__17_6_server_sockfd, 0, 1, (&__20_6_optval), 4U);

(__19_21_server_address.sin_family) = 0;
(__19_21_server_address.sin_port) = 21;
((__19_21_server_address.sin_addr).s_addr) = (htonl(0));
__18_6_server_len = 12;

bind(__17_6_server_sockfd, ((struct _ZZ11bind_socketE8sockaddr_3 *)(&__19_21_server_address)), __18_6_server_len); 
}
