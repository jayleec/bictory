/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API39.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API39.c"
struct bad;
#line 9
struct good; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1
struct bad {
char a;};
typedef struct bad bad_t;
#line 9
struct good {
char a;};
typedef struct good good_t;
#line 5
extern void badFoo(bad_t badParam);
#line 13
extern void goodFoo(good_t goodParam);
#line 5
void badFoo( bad_t __9_19_badParam) { 

}
#line 13
void goodFoo( good_t __17_21_goodParam) { 

}
