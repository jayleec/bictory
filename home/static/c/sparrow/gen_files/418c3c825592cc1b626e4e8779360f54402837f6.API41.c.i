/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:53 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API41.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/API41.c"
extern void badFoo(void);
#line 16
extern void goodFoo(void);
#line 4
void badFoo(void)
{
auto int __10_9_abc = 0;
auto int __11_6_edf = 1;

if (__10_9_abc == 1) {
__10_9_abc = 20;
} else  if (__10_9_abc == (__11_6_edf - 1)) {
__10_9_abc = 30;
} 
}

void goodFoo(void)
{
auto int __22_9_abc = 0;

if (__22_9_abc != 0) {
__22_9_abc = 20;
} 
}
