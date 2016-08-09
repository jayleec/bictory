/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/MSC32.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 149 "/usr/include/bits/types.h"
typedef long __time_t;
#line 76 "/usr/include/time.h"
typedef __time_t time_t;
#line 339 "/usr/include/stdio.h"
extern int printf(const char *__format, ...);
#line 380 "/usr/include/stdlib.h"
extern int rand(void);

extern void srand(unsigned __seed);
#line 186 "/usr/include/time.h"
extern time_t time(time_t *__timer);
#line 5 "/home/kskyj/sparrow4/util/testcode/c/MSC32.c"
extern void msc32(); void msc32() {

auto int __2034_6_i;
#line 6
srand(((unsigned)(time(((time_t *)0)))));
__2034_6_i = 0;
for (__2034_6_i = 0; (__2034_6_i < 10); __2034_6_i++) {
printf(((const char *)"%d, "), (rand()));
} 
}
