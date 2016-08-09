/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/MIS04.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/MIS04.c"
extern char *malloc(int size);
#line 10
extern char *mis04_1(void);
#line 22
extern char *mis04_2(void);
#line 35
extern char *goodFoo(void);
#line 20
static int badCount2;
#line 33
static int goodCount;
#line 20
static int badCount2 = 100;
#line 33
static int goodCount = 100;
#line 4
char *malloc( int __840_19_size) {
return ((char *)0);
}



char *mis04_1(void)
{
auto char *__848_11_ptr_tmp = ((char *)0);
__848_11_ptr_tmp = (malloc(100));



return __848_11_ptr_tmp;
}



char *mis04_2(void)
{
auto char *__860_11_ptr_tmp = ((char *)0);
badCount2 = (badCount2 + 20);
__860_11_ptr_tmp = (malloc(100));



return __860_11_ptr_tmp;
}



char *goodFoo(void)
{
auto char *__873_11_ptr_tmp = ((char *)0);
__873_11_ptr_tmp = (malloc(goodCount));



return __873_11_ptr_tmp;
}
