/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:51 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.MISUSE.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 6 "/home/kskyj/sparrow4/util/testcode/c/BAD_MACRO.MISUSE.c"
extern void push(int);


extern void macro_misuse(int x); void macro_misuse( int __13_23_x) {
push(__13_23_x); 
}
