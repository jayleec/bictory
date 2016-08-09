/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/IMPROPER_RANDOM_USAGE.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 149 "/usr/include/bits/types.h"
typedef long __time_t;
#line 76 "/usr/include/time.h"
typedef __time_t time_t;
#line 186 "/usr/include/time.h"
extern time_t time(time_t *__timer);
#line 327 "/usr/include/stdlib.h"
extern long random(void);


extern void srandom(unsigned __seed);
#line 380
extern int rand(void);

extern void srand(unsigned __seed);
#line 5 "/home/kskyj/sparrow4/util/testcode/c/IMPROPER_RANDOM_USAGE.c"
extern int badRoleSRand();
#line 12
extern int badRoleRand();
#line 19
extern void seedRandom();



extern int badRoleRandom();
#line 29
extern int goodRoleRandom();
#line 5
int badRoleSRand() {
auto int __1332_6_r;
srand(10U);
__1332_6_r = ((rand()) % 1000);
return (__1332_6_r % 6) + 1;
}

int badRoleRand() {
auto int __1339_6_r;
srand(((unsigned)(time(((time_t *)0)))));
__1339_6_r = ((rand()) % 1000);
return (__1339_6_r % 6) + 1;
}

void seedRandom() {
srandom(((unsigned)(time(((time_t *)0))))); 
}

int badRoleRandom() {
auto int __1350_6_r;
__1350_6_r = ((int)((random()) % 1000L));
return (__1350_6_r % 6) + 1;
}

int goodRoleRandom() {
auto int __1356_6_r;
seedRandom();
__1356_6_r = ((int)((random()) % 1000L));
return (__1356_6_r % 6) + 1;
}
