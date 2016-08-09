/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API50.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API50.c"
extern int order(char x);
#line 14
extern void another(int a);
#line 1
int order( char __5_16_x)
{
switch ((int)__5_16_x)
{
case 43:
case 45: return 2;
case 37:
case 42:
case 47: return 3;
default: return 0;
}
}

void another( int __18_18_a) {
if (__18_18_a > 0) {
(-1); return;
} else  if (__18_18_a == 0) {
0; return;
} else  {
if ((__18_18_a % 2) == 0) {
(-1); return;
} else  {
(-2); return;
}
}
}
