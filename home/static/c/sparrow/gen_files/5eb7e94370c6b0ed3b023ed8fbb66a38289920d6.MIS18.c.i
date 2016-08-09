/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/MIS18.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/MIS18.c"
extern void badTest();
extern int printf();
#line 11
extern void goodTest();
#line 4
void badTest() {
printf(("%s"), ("excluded"));
printf(("%s"), ("test")); 
}



void goodTest() {
printf(("%s"), ("test")); 
}
