/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/MEM08.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/MEM08.c"
struct gadget;
#line 11
struct widget; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 3 "/home/kskyj/sparrow4/util/testcode/c/MEM08.c"
typedef struct gadget gadget;
#line 10
typedef struct widget widget;
#line 485 "/usr/include/stdlib.h"
extern void *realloc(void *__ptr, size_t __size);
#line 17 "/home/kskyj/sparrow4/util/testcode/c/MEM08.c"
extern void *returnRealloc(gadget *gp);



extern void test();
#line 29
extern int MEM08_main();
#line 17
void *returnRealloc( gadget *__1101_30_gp) {
return realloc(((void *)__1101_30_gp), 16U);
}

void test() {
auto gadget *__1106_10_gp;
auto widget *__1107_10_wp;


__1107_10_wp = ((widget *)(returnRealloc(__1106_10_gp))); 
}

int MEM08_main() {
auto gadget *__1114_10_gp;
auto widget *__1115_10_wp;

test();
__1115_10_wp = ((widget *)(returnRealloc(__1114_10_gp)));



__1114_10_gp = ((gadget *)(realloc(((void *)__1114_10_gp), 320U)));

return 0;
}
