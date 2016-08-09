/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:53 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/sub.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 33 "/home/kskyj/sparrow4/util/testcode/c/sub.c"
struct _member; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float; struct _member {

int _a;};



extern int sub_test();
#line 75
extern int sum(int a, int b);




extern int substract(int a, int b);




extern double divide(int a, int b);
#line 91
extern long multiply(int a, int b);
#line 39
int sub_test()
{
auto struct _member __23_17_member;

auto int __25_6_a = 0;
auto int __26_6_b = 20;
auto int __27_6_c = 30;

if (__25_6_a == 0)
{
(__23_17_member._a) = 10;
}
else  if (__25_6_a == 1)
{
(__23_17_member._a) = 10;
}

else  {
switch (__26_6_b)
{
case 0:
(__23_17_member._a) = 10;
goto __T38841272;
case 1:
(__23_17_member._a) = 10;
goto __T38841272;
default:
(__23_17_member._a) = 10;
goto __T38841272;
} __T38841272:;
(__23_17_member._a) = 10;
}

return (__25_6_a + __26_6_b) + __27_6_c;
}

int sum( int __57_13_a,  int __57_20_b)
{
return __57_13_a + __57_20_b;
}

int substract( int __62_19_a,  int __62_26_b)
{
return __62_19_a - __62_26_b;
}

double divide( int __67_19_a,  int __67_26_b)
{
if (__67_26_b != 0)
return (double)(__67_19_a / __67_26_b);
return (0.0);
}
long multiply( int __73_19_a,  int __73_26_b)
{
return (long)(__73_19_a * __73_26_b);
}
