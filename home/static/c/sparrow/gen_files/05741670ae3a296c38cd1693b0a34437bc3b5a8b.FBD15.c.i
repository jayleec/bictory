/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:51 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/FBD15.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/FBD15.c"
extern void badFoo(void);
#line 9
extern void goodFoo(void);
#line 1
void badFoo(void)
{
auto int __7_7_badA[5];
auto int __8_7_i = 3;
((__7_7_badA)[2]) = 10;
((__7_7_badA)[__8_7_i]) = 10; 
}

void goodFoo(void)
{
auto int __15_7_goodA[5] = {0,1,2,3,4};
(*(__15_7_goodA)) = 10; 
}
