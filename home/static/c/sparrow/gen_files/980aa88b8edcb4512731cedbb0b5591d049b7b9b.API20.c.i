/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API20.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 5 "/home/kskyj/sparrow4/util/testcode/c/API20.c"
extern void pfmInitError();



extern void badError();
#line 17
extern void goodError();
#line 26
extern void badError2();
#line 39
extern void goodError2();
#line 5
void pfmInitError() {
return;
}

void badError() {
auto int __14_6_rc = 0;

if (__14_6_rc != 0) {
(-1); return;
} 
}

void goodError() {
auto int __22_9_rc = 0;

if (__22_9_rc != 0) {
pfmInitError();
(-1); return;
} 
}

void badError2() {
auto int __31_6_rc = 0;

if (__31_6_rc != 0) {
if (__31_6_rc > 1) {
pfmInitError();
(-1); return;
} else  {
(-1); return;
}
} 
}

void goodError2() {
auto int __44_6_rc = 0;
if (__44_6_rc != 0) {
pfmInitError();
(-1); return;
}

(-1); return;
}
