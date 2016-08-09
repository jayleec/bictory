/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API44.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API44.c"
extern void badLoop(void);
#line 11
extern void goodLoop(void);
#line 1
void badLoop(void)
{
auto int __7_9_i = 0;
for (__7_9_i = 0; (__7_9_i < 10); ++__7_9_i) {
auto int __9_13_k; __9_13_k = __7_9_i;

} 

}

void goodLoop(void)
{
auto int __17_9_i = 0;
auto int __18_9_k;
for (__17_9_i = 0; (__17_9_i < 10); ++__17_9_i) {
__18_9_k = __17_9_i;
} 

}
