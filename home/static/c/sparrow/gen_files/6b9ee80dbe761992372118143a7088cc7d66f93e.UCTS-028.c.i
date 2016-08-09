/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/UCTS-028.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 127 "/usr/include/string.h"
extern char *strcpy(char *__dest, const char *__src);
#line 5 "/home/kskyj/sparrow4/util/testcode/c/UCTS-028.c"
extern void *aux_test_extreme(int *buf, char n);



extern void test_extreme();


extern int malloc();

extern int free();


extern int test_strcpy_dyn();
#line 5
void *aux_test_extreme( int *__1101_29_buf,  char __1101_39_n) {
(__1101_29_buf[(((int)__1101_39_n) + 2)]) = 0; 
}

void test_extreme() {
auto char *__1106_11_a;

__1106_11_a = ((char *)(malloc(12)));
aux_test_extreme(((int *)(__1106_11_a + 8)), ((char)4));
free(__1106_11_a); 
}

int test_strcpy_dyn()
{
auto char *__1115_11_dest;
auto char __1116_10_buf[20];
auto char __1117_10_buf2[9];
__1115_11_dest = ((char *)(malloc(10)));
strcpy(__1115_11_dest, ((const char *)(__1116_10_buf)));
strcpy(__1115_11_dest, ((const char *)(__1117_10_buf2)));
free(__1115_11_dest);
return 0;
}
