/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/CHECK_ALIGNMENT_OF_MEMORY.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 485 "/usr/include/stdlib.h"
extern void *realloc(void *__ptr, size_t __size);
#line 5 "/home/kskyj/sparrow4/util/testcode/c/CHECK_ALIGNMENT_OF_MEMORY.c"
extern void check_assign();




extern int aligned_alloc();
#line 5
void check_assign() {
auto size_t __1906_8_resize = 1024U;
auto size_t __1907_8_alignment = 4096U;
auto int *__1908_6_ptr;
auto int *__1909_6_ptr1;
if ((__1908_6_ptr = ((int *)(aligned_alloc(__1907_8_alignment, 4U)))) == ((int *)0)) {

}
if ((__1909_6_ptr1 = ((int *)(realloc(((void *)__1908_6_ptr), __1906_8_resize)))) == ((int *)0)) {

} 
}
