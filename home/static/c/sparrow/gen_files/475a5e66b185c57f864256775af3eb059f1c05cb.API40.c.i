/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API40.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/API40.c"
extern int getBadSum(int badIndex);
#line 16
extern int getGoodSumG(int goodIndex);
#line 1
int sums[10];

int getBadSum( int __7_19_badIndex) {
auto int __8_6_sum = 0;

if (__8_6_sum == 0) {
if ((__7_19_badIndex + 1) > 0) {
return (sums)[__7_19_badIndex];
}
return (sums)[__7_19_badIndex];
}

return (sums)[__7_19_badIndex];
}

int getGoodSumG( int __20_21_goodIndex) {
auto int __21_6_sum = 0;

if ((__20_21_goodIndex >= 0) && (__20_21_goodIndex < 10)) {
return (sums)[__20_21_goodIndex];
}

return (-1);
}
