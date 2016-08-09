/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:56 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/API48.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/API48.c"
extern int IsBadReturn(const char path);




extern int IsAnotherBadReturn(const char path);
#line 15
extern int IsGoodReturn(const char path);
#line 4
int IsBadReturn( const char __8_28_path) {

return 0;
}

int IsAnotherBadReturn( const char __13_35_path) {

auto int __15_6_a = 3;
return __15_6_a + 1;
}

int IsGoodReturn( const char __19_29_path) {

return 0;
}
