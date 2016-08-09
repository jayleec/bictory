/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.PRE_CALL.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.REQUIRED.PRE_CALL.c"
extern void LcfApError_API22();
extern void LcfSetUIMsg_API22();

extern void FuncBad(const char *x);




extern void FuncGood(const char *x);
#line 7
void FuncBad( const char *__11_27_x) {
LcfSetUIMsg_API22();
LcfApError_API22(); 
}

void FuncGood( const char *__16_28_x) {
LcfApError_API22();
LcfSetUIMsg_API22(); 
}
