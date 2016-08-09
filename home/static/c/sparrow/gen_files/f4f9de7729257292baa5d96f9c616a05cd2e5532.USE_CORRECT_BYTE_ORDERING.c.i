/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:58 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/USE_CORRECT_BYTE_ORDERING.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 339 "/usr/include/stdio.h"
extern int printf(const char *__format, ...);
#line 7 "/home/kskyj/sparrow4/util/testcode/c/USE_CORRECT_BYTE_ORDERING.c"
extern int socket(int a, int b, int c);



extern int recv(int a, void *b, int c, int d);


extern void use_correct_byte();
#line 7
int socket( int __1907_16_a,  int __1907_22_b,  int __1907_28_c) {
return 1;
}

int recv( int __1911_14_a,  void *__1911_23_b,  int __1911_29_c,  int __1911_35_d) {
return 1;
}
void use_correct_byte() {

auto unsigned __1916_14_num;
auto int __1917_5_sock; __1917_5_sock = (socket(1, 2, 0));
if ((recv(__1917_5_sock, ((void *)(&__1916_14_num)), 4, 0)) < 0) {


}
printf(((const char *)"We received %u from the network!\n"), ((unsigned)__1916_14_num)); 

}
