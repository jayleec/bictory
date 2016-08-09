/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.TP.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 8 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.FORBIDDEN.LIB.TP.c"
extern void tprecv_FB11(int);

extern void terminate_tp(char *buf); void terminate_tp( char *__14_26_buf) {
if (__14_26_buf != ((char *)0)) {
tprecv_FB11(0);
} 


}
