/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:58 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.INSUFFICIENT_KEY.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 5 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.INSUFFICIENT_KEY.c"
struct _RSA; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;

typedef struct _RSA RSA;
#line 339 "/usr/include/stdio.h"
extern int printf(const char *__format, ...);
#line 9 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.INSUFFICIENT_KEY.c"
extern RSA *RSA_generate_key(int, int, void *, void *);

extern void badKey1();
#line 19
extern void badKey2();
#line 28
extern void badKey3(int longKey);
#line 42
extern void goodKey();
#line 11
void badKey1() {
auto RSA *__1799_8_rsa;
__1799_8_rsa = (RSA_generate_key(512, 35, ((void *)0), ((void *)0)));
if (__1799_8_rsa == ((RSA *)0)) {
printf(((const char *)"Error\n"));
} 
}

void badKey2() {
auto RSA *__1807_8_rsa;
auto int __1808_6_keyLength = 512;
__1807_8_rsa = (RSA_generate_key(__1808_6_keyLength, 35, ((void *)0), ((void *)0)));
if (__1807_8_rsa == ((RSA *)0)) {
printf(((const char *)"Error\n"));
} 
}

void badKey3( int __1815_18_longKey) {
auto RSA *__1816_8_rsa;
auto int __1817_6_keyLength;
if (__1815_18_longKey) {
__1817_6_keyLength = 1024;
} else  {
__1817_6_keyLength = 512;
}
__1816_8_rsa = (RSA_generate_key(__1817_6_keyLength, 35, ((void *)0), ((void *)0)));
if (__1816_8_rsa == ((RSA *)0)) {
printf(((const char *)"Error\n"));
} 
}

void goodKey() {
auto RSA *__1830_8_rsa;
__1830_8_rsa = (RSA_generate_key(1024, 35, ((void *)0), ((void *)0)));
if (__1830_8_rsa == ((RSA *)0)) {
printf(((const char *)"Error\n"));
} 
}
