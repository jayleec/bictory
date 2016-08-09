/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API45.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API45.c"
extern void badFoo(void);
#line 11
extern void goodFoo(void);
#line 1
void badFoo(void)
{
auto unsigned char __7_19_index = ((unsigned char)0U);
auto int __8_9_sum = 0;
do {
__8_9_sum += ((int)__7_19_index);
__7_19_index++;
} while (((int)__7_19_index) < 1000); 
}

void goodFoo(void)
{
auto int __17_9_index = 0;
auto int __18_9_sum = 0;
while (__17_9_index < 1000) {
__18_9_sum += __17_9_index;
__17_9_index++;
} 
}
