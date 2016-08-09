/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/UNCONTROLLED_RECURSION.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 2 "/home/kskyj/sparrow4/util/testcode/c/UNCONTROLLED_RECURSION.c"
extern int fac(int n);
#line 18
extern int fac2(int n);
#line 26
extern int fac3(int n);



extern int fac4(int n);



extern int fac5(int n);
#line 2
int fac( int __6_13_n) {
if ((fac((__6_13_n - 1))) && (__6_13_n > 0)) {

}

if (((__6_13_n > 0) || (fac((__6_13_n - 1)))) && (fac((__6_13_n - 1)))) {

}

if (fac((__6_13_n - 1))) {

}

return __6_13_n * (fac((__6_13_n - 1)));
}

int fac2( int __22_14_n) {
if (__22_14_n <= 0) {
return 1;
}

return __22_14_n * (fac2((__22_14_n - 1)));
}

int fac3( int __30_14_n) {
return (__30_14_n > 0) ? (__30_14_n * (fac3((__30_14_n - 1)))) : 1;
}

int fac4( int __34_14_n) {
return ((fac4(__34_14_n)) > 0) ? (__34_14_n * (fac4((__34_14_n - 1)))) : 1;
}

int fac5( int __38_14_n) {
if (__38_14_n >= 0) {
switch (__38_14_n) {
case 0:
return 1;
default:
return fac5((__38_14_n - 1));
}
} else  {
return (-1);
}
}
