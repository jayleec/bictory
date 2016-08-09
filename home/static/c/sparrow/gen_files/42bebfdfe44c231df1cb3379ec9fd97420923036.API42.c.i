/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API42.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/API42.c"
extern void getResource();
extern int isUserAuthentic();

extern void fooBad(void);
#line 14
extern void fooNestedBad(void);
#line 7
void fooBad(void) {
auto char *__844_9_some = ((char *)0);

getResource(); 

}

void fooNestedBad(void) {
auto char *__851_9_some = ((char *)0);

if (isUserAuthentic()) {
if (isUserAuthentic()) {
getResource();
}

getResource();
} 

}
