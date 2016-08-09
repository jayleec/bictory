/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/ENV32.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 517 "/usr/include/stdlib.h"
extern int atexit(void (*__func)(void));
#line 543 "/usr/include/stdlib.h"
extern void exit(int __status);
#line 4 "/home/kskyj/sparrow4/util/testcode/c/ENV32.c"
extern void exit1(void);




extern void exit2(void);
#line 17
extern void func2(void);




extern void func1(void);



extern int env(void);
#line 4
void exit1(void) {

return;
}

void exit2(void) {
if (1) {

exit(0);
}
return;
}

void func2(void) {
exit1();
exit2(); 
}

void func1(void) {
func2(); 
}

int env(void) {
if ((atexit(func1)) != 0) {

}
if ((atexit(func2)) != 0) {

}

exit(0); 
}
