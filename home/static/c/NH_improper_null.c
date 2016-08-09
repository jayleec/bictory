/* Translated by the Edison Design Group C++/C front end (version 4.2) */
/* Thu Apr 24 10:12:01 2014 */
int __EDGCPFE__4_2;
void *memcpy(); void *memset();
#line 1 "test.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
struct SSS;



struct SS;




struct S; struct _Complex_long_double { long double _Vals[2];}; typedef struct _Complex_long_double _Complex_long_double; struct _Complex_double { double _Vals[2];}; typedef struct _Complex_double _Complex_double; struct _Complex_float { float _Vals[2];}; typedef struct _Complex_float _Complex_float
#line 11
;
#line 2
struct SSS {
char dest3[11];};


struct SS {
struct SSS inner2[30];
char dest2[2];
};


struct S {
struct SS inner1;
struct SS inner1_1;
struct SS inner1_2;
struct SS inner1_3;
};


extern int strncpy(char *, char *, int);
extern void *malloc(int);


extern int test(int n); int test( int __20_14_n) {


auto char *__23_9_test;


auto struct S __26_11_s;
#line 24
__23_9_test = ((char *)(malloc(1)));
#line 35

memset(&__26_11_s, 0, 11);

do {
 strncpy(((((((__26_11_s.inner1).inner2))[0]).dest3)), ((const char *)"0123456789"), 10UL); 
  (((((((__26_11_s.inner1).inner2))[0]).dest3))[10UL]) = ((char)0);
} while(0);

#line 42
 free(__23_9_test);
return 0;
}
