/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/NEGATIVE_FILE_DESCRIPTOR.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 174 "/usr/include/bits/socket.h"
struct sockaddr; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 192 "/usr/include/bits/types.h"
typedef unsigned __socklen_t;
#line 35 "/usr/include/bits/socket.h"
typedef __socklen_t socklen_t;
#line 543 "/usr/include/stdlib.h"
extern void exit(int __status);
#line 566 "/usr/include/stdlib.h"
extern char *getenv(const char *__name);
#line 129 "/usr/include/sys/socket.h"
extern int connect(int __fd, const struct sockaddr *__addr, socklen_t __len);
#line 6 "/home/kskyj/sparrow4/util/testcode/c/NEGATIVE_FILE_DESCRIPTOR.c"
extern int negative_file_des();



extern int strncpy();
#line 6
int negative_file_des() {
auto char *__2139_10_rPort;
auto int __2140_8_sockfd = (-1);
auto char __2141_9_buf[25];
#line 7
__2139_10_rPort = (getenv(((const char *)"rPort")));


strncpy((__2141_9_buf), __2139_10_rPort, 25);
if ((connect(__2140_8_sockfd, ((const struct sockaddr *)(&__2141_9_buf)), 10U)) < 0) {

exit(1);
}
return 0;
}
