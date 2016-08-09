/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:54 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE;
#line 8 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
struct List;
#line 19
struct Under;
#line 389
struct big_number;
#line 98
struct _ZZ19memory_leak_01_mainE5SRL01_312;
#line 126
struct _ZZ27memory_leak_complex_01_mainE5SRL01_319; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 8 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
struct List {
char buf1[5];
char buf2[10];
int *ptr;};
#line 19
struct Under {
int buf[20];};
typedef struct Under Under;
typedef struct List List;
#line 389
struct big_number {
char low[1024];
char high[1024];};
#line 98
struct _ZZ19memory_leak_01_mainE5SRL01_312 {
char *p;};
#line 126
struct _ZZ27memory_leak_complex_01_mainE5SRL01_319 {
char *p;};
#line 214 "/usr/include/stdio.h"
extern int fclose(FILE *__stream);
#line 249 "/usr/include/stdio.h"
extern FILE *fopen(const char *__filename, const char *__modes);
#line 333 "/usr/include/stdio.h"
extern int fprintf(FILE *__stream, const char *__format, ...);
#line 339
extern int printf(const char *__format, ...);
#line 407 "/usr/include/stdio.h"
extern int fscanf(FILE *__stream, const char *__format, ...);
#line 688 "/usr/include/stdio.h"
extern size_t fwrite(const void *__ptr, size_t __size, size_t __n, FILE *__s);
#line 327 "/usr/include/stdlib.h"
extern long random(void);
#line 380
extern int rand(void);
#line 471
extern void *malloc(size_t __size);
#line 488
extern void free(void *__ptr);
#line 543 "/usr/include/stdlib.h"
extern void exit(int __status);
#line 566 "/usr/include/stdlib.h"
extern char *getenv(const char *__name);
#line 43 "/usr/include/string.h"
extern void *memcpy(void *__dest, const void *__src, size_t __n);
#line 64
extern void *memset(void *__s, int __c, size_t __n);
#line 127 "/usr/include/string.h"
extern char *strcpy(char *__dest, const char *__src);


extern char *strncpy(char *__dest, const char *__src, size_t __n);
#line 25 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
extern void buffer_overrun_01_sub(char *ptr, int size);


extern void buffer_overrun_01_main();
#line 35
extern int buffer_overrun_complex_01_sub();


extern void buffer_overrun_complex_01_main(char c);
#line 44
extern void buffer_overrun_02_main();
#line 53
extern int buffer_overrun_complex_02_sub();


extern void buffer_overrun_complex_02_main();
#line 64
extern void buffer_overrun_03(int index, char c);
#line 74
extern void buffer_overrun_complex_03_sub(int index);




extern void buffer_overrun_complex_03(int index, char c);
#line 87
extern int memory_leak_01_sub(char **p, size_t n);
#line 97
extern int memory_leak_01_main(size_t size);
#line 111
extern int memory_leak_complex_01_sub(char **p, size_t n);
#line 121
extern void memory_leak_complex_01_sub_free(char *p);
extern int unknown();


extern int memory_leak_complex_01_main(size_t size);
#line 137
extern int resource_leak_01_sub(const char *name, FILE **pf);
#line 145
extern int resource_leak_01_main(const char *name);
#line 155
extern int resource_leak_complex_01_sub(const char *name, FILE **pf);
#line 163
extern void resource_leak_complex_01_sub_close(FILE *f);

extern int close();

extern int resource_leak_complex_01_main(const char *name);
#line 182
extern void null_deref_01_sub(char *p, char c);


extern void null_deref_01_main();
#line 191
extern void null_deref_complex_01_sub(char *p, char c);


extern void *null_deref_complex_01_sub2();


extern void null_deref_complex_01_main();
#line 203
extern void null_deref_02_main(char *pstr);
#line 210
extern void null_deref_complex_02_sub(char *pstr);


extern void null_deref_complex_02_main(char *pstr);
#line 219
extern void null_deref_03_main();
#line 227
extern void divide_by_zero_03(int i);
#line 236
extern int divide_by_zero_complex_03_sub();


extern void divide_by_zero_complex_03(int i);
#line 247
extern void divide_by_zero_04(int x);
#line 254
extern void divide_by_zero_complex_04_sub(int x);


extern void divide_by_zero_complex_04(int x);
#line 264
extern void double_free_sub(List *p);



extern void double_free_main();
#line 284
extern void double_free_complex_sub(List *p);
#line 290
extern void double_free_complex_main();
#line 306
extern void use_after_free(List *p);
#line 312
extern void use_after_free_complex_sub(List *p);



extern void use_after_free_complex(List *p);
#line 322
extern char *return_pointer_to_freed();
#line 329
extern void return_pointer_to_freed_complex_sub(List *p);



extern char *return_pointer_to_freed_complex();
#line 340
extern int uninit(int mode);
#line 354
extern void uninit_sub(int *p);
#line 364
extern int uninit_main();
#line 371
extern char *return_pointer_to_local();
#line 377
extern void free_non_heap(int size);
#line 393
extern char pass_by_value(struct big_number b);




extern int missing_return(unsigned cnt, int sum);
#line 407
extern int cast_alters_value();
#line 416
extern void free_null_pointer_call(int *x);



extern void free_null_pointer_main();
#line 426
extern void memcpy_with_overlapping_regions();
#line 434
extern void null_check_after_dereference();
#line 443
extern void shift_exceeds_bit_width();
#line 451
extern void shift_negative();
#line 459
extern void underrun_static();
#line 466
extern void underrun_static_bad_condition(int index);
#line 475
extern void type_underrun_static();
#line 481
extern void type_underrun_bad(int index);
#line 489
extern void unresonable_parameter();
#line 496
extern void format_string();
#line 502
extern void unreachable_code();
#line 514
extern void ignored_return_value();
#line 523
extern int ignored_return_2_sub(int x);


extern void ignored_return_2_main();
#line 532
extern void checked_return();
#line 551
extern char dangerous_func_cast_sub();


extern void dangerous_func_cast_main();
#line 561
extern void varargs_func_cast_sub(int n);


extern void varargs_func_cast_main();
#line 570
extern int overrun_pf();
#line 581
extern void information_leak();




extern void argument_number_mismatch1(int a);


extern void argument_number_mismatch2();




extern void double_close();
#line 603
extern int redundant_condition1();


extern int redundant_condition2();


extern void redundant_condition3();
#line 617
extern void minimal_scope();
#line 645 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
extern int missing_function_return(float a);
#line 147 "/usr/include/stdio.h"
extern struct _IO_FILE *stderr;
#line 616 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
extern int a;
#line 642 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
int testField;
#line 616 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
int a = 2;
#line 25
void buffer_overrun_01_sub( char *__2069_34_ptr,  int __2069_43_size) {
(__2069_34_ptr[__2069_43_size]) = ((char)0); 
}
void buffer_overrun_01_main() {

auto char __2074_10_buf[5];
buffer_overrun_01_sub((__2074_10_buf), 5); 
}


int buffer_overrun_complex_01_sub() {
return 5;
}
void buffer_overrun_complex_01_main( char __2082_42_c) {
auto char __2083_10_buf[5];
((__2083_10_buf)[(buffer_overrun_complex_01_sub())]) = __2082_42_c; 
}


void buffer_overrun_02_main() {
auto struct List __2089_17_str;
auto char __2090_10_buff1[5];
auto char __2091_10_buff2[10];
strcpy(((__2089_17_str.buf1)), ((const char *)((__2089_17_str.buf2))));
memcpy(((void *)(__2090_10_buff1)), ((const void *)(__2091_10_buff2)), 10U); 
}


int buffer_overrun_complex_02_sub() {
return 10;
}
void buffer_overrun_complex_02_main() {

auto char __2102_10_buff1[5];
auto char __2103_10_buff2[10];
strncpy((__2102_10_buff1), ((const char *)(__2103_10_buff2)), ((size_t)(buffer_overrun_complex_02_sub()))); 
}


void buffer_overrun_03( int __2108_28_index,  char __2108_40_c) {
auto char __2109_10_buf[10];
if (__2108_28_index > 10) {
return;
}
((__2109_10_buf)[__2108_28_index]) = __2108_40_c;
memset(((void *)(__2109_10_buf)), 0, ((size_t)(__2108_28_index + 1))); 
}


void buffer_overrun_complex_03_sub( int __2118_40_index) {
if (__2118_40_index > 10) {
exit(1);
} 
}
void buffer_overrun_complex_03( int __2123_36_index,  char __2123_48_c) {
auto char __2124_10_buf[10];
buffer_overrun_complex_03_sub(__2123_36_index);
((__2124_10_buf)[__2123_36_index]) = __2123_48_c;
memset(((void *)(__2124_10_buf)), 0, ((size_t)(__2123_36_index + 1))); 
}


int memory_leak_01_sub( char **__2131_31_p,  size_t __2131_41_n) {
auto char *__2132_11_tmp;
__2132_11_tmp = ((char *)(malloc(__2131_41_n)));
if (__2132_11_tmp != ((char *)0)) {
(*__2131_31_p) = __2132_11_tmp;
return 0;
} else  {
return 1;
}
}
int memory_leak_01_main( size_t __2141_32_size) {


auto struct _ZZ19memory_leak_01_mainE5SRL01_312 __2144_7_srl = {((char *)0)};
auto char *__2145_11_ptr;
if (memory_leak_01_sub((&(__2144_7_srl.p)), __2141_32_size)) {
__2145_11_ptr = (__2144_7_srl.p);
free(((void *)__2145_11_ptr));
return 2;
}
return 0;
}


int memory_leak_complex_01_sub( char **__2155_39_p,  size_t __2155_49_n) {
auto char *__2156_11_tmp;
__2156_11_tmp = ((char *)(malloc(__2155_49_n)));
if (__2156_11_tmp != ((char *)0)) {
(*__2155_39_p) = __2156_11_tmp;
return 0;
} else  {
return 1;
}
}
void memory_leak_complex_01_sub_free( char *__2165_44_p) {
if (unknown())
free(((void *)__2165_44_p)); 
}
int memory_leak_complex_01_main( size_t __2169_40_size) {


auto struct _ZZ27memory_leak_complex_01_mainE5SRL01_319 __2172_7_srl = {((char *)0)};
auto char *__2173_11_ptr;
memory_leak_complex_01_sub((&(__2172_7_srl.p)), __2169_40_size);
__2173_11_ptr = (__2172_7_srl.p);
memory_leak_complex_01_sub_free(__2173_11_ptr);
return 0;
}


int resource_leak_01_sub( const char *__2181_38_name,  FILE **__2181_51_pf) {
auto FILE *__2182_11_f; __2182_11_f = (fopen(__2181_38_name, ((const char *)"r")));
if (!(__2182_11_f)) {
return (-1);
}
(*__2181_51_pf) = __2182_11_f;
return 0;
}
int resource_leak_01_main( const char *__2189_39_name) {
auto FILE *__2190_11_dummy;
if ((resource_leak_01_sub(__2189_39_name, (&__2190_11_dummy))) == (-1)) {
fprintf(stderr, ((const char *)"Problem with: %s\n"), __2189_39_name);
return 0;
}
return 1;
}


int resource_leak_complex_01_sub( const char *__2199_46_name,  FILE **__2199_59_pf) {
auto FILE *__2200_11_f; __2200_11_f = (fopen(__2199_46_name, ((const char *)"r")));
if (!(__2200_11_f)) {
return (-1);
}
(*__2199_59_pf) = __2200_11_f;
return 0;
}
void resource_leak_complex_01_sub_close( FILE *__2207_47_f) {
if (unknown())
close(__2207_47_f); 
}
int resource_leak_complex_01_main( const char *__2211_47_name) {
auto FILE *__2212_11_dummy;
auto int __2213_6_a;
if ((resource_leak_complex_01_sub(__2211_47_name, (&__2212_11_dummy))) == (-1)) {
fprintf(stderr, ((const char *)"Problem with: %s\n"), __2211_47_name);
return 0;
}
resource_leak_complex_01_sub_close(__2212_11_dummy);
return 1;
if (__2213_6_a == 1) {
return 2;
}
}


void null_deref_01_sub( char *__2226_30_p,  char __2226_38_c) {
(__2226_30_p[0]) = __2226_38_c; 
}
void null_deref_01_main() {
auto char *__2230_11_p = ((char *)0);
null_deref_01_sub(__2230_11_p, ((char)97)); 
}


void null_deref_complex_01_sub( char *__2235_38_p,  char __2235_46_c) {
(__2235_38_p[0]) = __2235_46_c; 
}
void *null_deref_complex_01_sub2() {
return ((void *)0);
}
void null_deref_complex_01_main() {
auto char *__2242_11_p; __2242_11_p = ((char *)(null_deref_complex_01_sub2()));
null_deref_complex_01_sub(__2242_11_p, ((char)97)); 
}


void null_deref_02_main( char *__2247_31_pstr) {
if (__2247_31_pstr != ((char *)0))
(__2247_31_pstr[0]) = ((char)97);
(__2247_31_pstr[1]) = ((char)98); 
}


void null_deref_complex_02_sub( char *__2254_38_pstr) {
if (__2254_38_pstr != ((char *)0)) ; 
}
void null_deref_complex_02_main( char *__2257_39_pstr) {
null_deref_complex_02_sub(__2257_39_pstr);
(__2257_39_pstr[1]) = ((char)98); 
}


void null_deref_03_main() {
auto struct List *__2264_18_p;
__2264_18_p = ((struct List *)(malloc(19U)));
(__2264_18_p->ptr) = ((int *)0);
free(((void *)__2264_18_p)); 
}


void divide_by_zero_03( int __2271_28_i) {
auto int __2272_9_a = 0; auto int __2272_16_b;
auto int __2273_9_cnt = 100;
if (__2271_28_i > 10)
__2272_9_a = ((int)(random()));
__2272_16_b = (__2273_9_cnt / __2272_9_a); 
}


int divide_by_zero_complex_03_sub() {
return 0;
}
void divide_by_zero_complex_03( int __2283_36_i) {
auto int __2284_9_a; auto int __2284_12_b;
auto int __2285_9_cnt = 100;
__2284_9_a = (divide_by_zero_complex_03_sub());
__2284_12_b = (__2285_9_cnt / __2284_9_a); 
}


void divide_by_zero_04( int __2291_28_x) {
auto int __2292_9_r; auto int __2292_12_cnt = 100;
if (!(__2291_28_x))
__2292_9_r = (__2292_12_cnt / __2291_28_x); 
}


void divide_by_zero_complex_04_sub( int __2298_40_x) {
if (!(__2298_40_x)) ; 
}
void divide_by_zero_complex_04( int __2301_36_x) {
auto int __2302_9_r; auto int __2302_12_cnt = 100;
divide_by_zero_complex_04_sub(__2301_36_x);
__2302_9_r = (__2302_12_cnt / __2301_36_x); 
}


void double_free_sub( List *__2308_28_p) {
free(((void *)(__2308_28_p->ptr)));
free(((void *)__2308_28_p)); 
}
void double_free_main() {
auto List *__2313_11_head;
__2313_11_head = ((List *)(malloc(19U)));
if (!(__2313_11_head)) {
exit(1);
}
(__2313_11_head->ptr) = ((int *)(malloc(40U)));
if (!(__2313_11_head->ptr)) {
free(((void *)__2313_11_head));
exit(1);
}
double_free_sub(__2313_11_head);
free(((void *)__2313_11_head)); 
}


void double_free_complex_sub( List *__2328_36_p) {
free(((void *)(__2328_36_p->ptr)));
if (unknown()) {
free(((void *)__2328_36_p));
} 
}
void double_free_complex_main() {
auto List *__2335_11_head;
__2335_11_head = ((List *)(malloc(19U)));
if (!(__2335_11_head)) {
exit(1);
}
(__2335_11_head->ptr) = ((int *)(malloc(40U)));
if (!(__2335_11_head->ptr)) {
free(((void *)__2335_11_head));
exit(1);
}
double_free_complex_sub(__2335_11_head);
free(((void *)__2335_11_head)); 
}


void use_after_free( List *__2350_27_p) {
free(((void *)__2350_27_p));
free(((void *)(__2350_27_p->ptr))); 
}


void use_after_free_complex_sub( List *__2356_39_p) {
if (unknown())
free(((void *)__2356_39_p)); 
}
void use_after_free_complex( List *__2360_35_p) {
use_after_free_complex_sub(__2360_35_p);
free(((void *)(__2360_35_p->ptr))); 
}


char *return_pointer_to_freed() {
auto char *__2367_11_p; __2367_11_p = ((char *)(malloc(1U)));
free(((void *)__2367_11_p));
return __2367_11_p;
}


void return_pointer_to_freed_complex_sub( List *__2373_48_p) {
if (unknown())
free(((void *)__2373_48_p)); 
}
char *return_pointer_to_freed_complex() {
auto char *__2378_11_p; __2378_11_p = ((char *)(malloc(1U)));
return_pointer_to_freed_complex_sub(((List *)__2378_11_p));
return __2378_11_p;
}


int uninit( int __2384_16_mode) {
auto int __2385_9_n;
switch (__2384_16_mode) {
case 1:
__2385_9_n = 1;
goto __T42990424;
case 2:
__2385_9_n = 2;
goto __T42990424;
} __T42990424:;
return __2385_9_n;
}


void uninit_sub( int *__2398_22_p) {
switch (rand()) {
case 1:
(*__2398_22_p) = 1;
goto __T42992192;
case 2:
(*__2398_22_p) = 2;
goto __T42992192;
} __T42992192:; 
}
int uninit_main() {
auto int __2409_9_n;
uninit_sub((&__2409_9_n));
return __2409_9_n;
}


char *return_pointer_to_local() {
auto char __2416_10_buf[4] = "abc";
return __2416_10_buf;
}


void free_non_heap( int __2421_24_size) {
auto char __2422_10_buf[10];
auto char *__2423_11_p; __2423_11_p = (__2422_10_buf);
if (__2421_24_size > 10) {
__2423_11_p = ((char *)(malloc(((size_t)__2421_24_size))));
}
if (!(__2421_24_size < 10)) {
free(((void *)__2423_11_p));
} 
}
#line 393
char pass_by_value( struct big_number __2437_38_b) {
return ((__2437_38_b.low))[0];
}


int missing_return( unsigned __2442_33_cnt,  int __2442_42_sum) {
if (__2442_33_cnt == 0U) {
return __2442_42_sum;
}
missing_return((__2442_33_cnt - 1U), ((int)(((unsigned)__2442_42_sum) + __2442_33_cnt))); 
}



int cast_alters_value() {
auto int __2452_9_a = (-2);
auto unsigned __2453_18_ua;

__2453_18_ua = ((unsigned)__2452_9_a);
return 0;
}


void free_null_pointer_call( int *__2460_34_x) {

free(((void *)__2460_34_x)); 
}
void free_null_pointer_main() {
auto int *__2465_8_x = ((int *)0);
free_null_pointer_call(__2465_8_x); 
}


void memcpy_with_overlapping_regions() {
auto int *__2471_8_a;
auto int *__2472_8_b;
#line 427
__2471_8_a = ((int *)(malloc(100U)));
__2472_8_b = __2471_8_a;
memcpy(((void *)__2471_8_a), ((const void *)__2472_8_b), 10U);
free(((void *)__2471_8_a)); 
}


void null_check_after_dereference() {
auto int *__2479_8_x;
(*__2479_8_x) = 100;
if (__2479_8_x == ((int *)0)) {
return;
} 
}


void shift_exceeds_bit_width() {

auto int __2489_6_a = 20; auto int __2489_11_b = 0;

__2489_11_b = (__2489_6_a << 9999999); 
}


void shift_negative() {

auto int __2497_6_a = 20; auto int __2497_11_b = 0;

__2497_11_b = (__2497_6_a << (-2)); 
}


void underrun_static() {
auto int __2504_7_b[100];
((__2504_7_b)[(-1)]) = 0; 
}



void underrun_static_bad_condition( int __2510_40_index) {
auto int __2511_7_b[100];

if (__2510_40_index < (-5))
((__2511_7_b)[__2510_40_index]) = 0; 
}



void type_underrun_static() {
auto Under __2520_9_under;
(((__2520_9_under.buf))[(-20)]) = 5; 
}


void type_underrun_bad( int __2525_28_index) {
auto Under __2526_9_under;

if (__2525_28_index < (-5))
(((__2526_9_under.buf))[__2525_28_index]) = 5; 
}


void unresonable_parameter() {
auto int __2534_6_a = (-20);
auto void *__2535_9_z; __2535_9_z = (malloc(((size_t)__2534_6_a)));
free(__2535_9_z); 
}


void format_string() {
auto int __2541_7_x = 2;

printf(((const char *)"%s"), __2541_7_x); 
}

void unreachable_code() {
auto int __2547_9_x = 1;
switch (__2547_9_x) {
case 1:
goto __T43014960;
printf(((const char *)"aa\n"));
} __T43014960:; 

}



void ignored_return_value() {
auto FILE *__2559_7_fd;
auto char __2560_6_buf[20];
fwrite(((const void *)(__2560_6_buf)), 1U, 1U, __2559_7_fd); 
}




int ignored_return_2_sub( int __2567_30_x) {
return __2567_30_x - 20;
}
void ignored_return_2_main() {
auto int __2571_8_y; __2571_8_y = (ignored_return_2_sub(10));
return;
}


void checked_return() {
auto FILE *__2577_10_fp;
auto int __2578_8_a = 20;

if ((fscanf(__2577_10_fp, ((const char *)"%d"), (&__2578_8_a))) == (-1))
printf(((const char *)"End of file\n"));
if ((fscanf(__2577_10_fp, ((const char *)"%d"), (&__2578_8_a))) == (-1))
printf(((const char *)"End of file\n"));
if ((fscanf(__2577_10_fp, ((const char *)"%d"), (&__2578_8_a))) == (-1))
printf(((const char *)"End of file\n"));
if ((fscanf(__2577_10_fp, ((const char *)"%d"), (&__2578_8_a))) == (-1))
printf(((const char *)"End of file\n"));
if ((fscanf(__2577_10_fp, ((const char *)"%d"), (&__2578_8_a))) == (-1))
printf(((const char *)"End of file\n"));

fscanf(__2577_10_fp, ((const char *)"%d"), (&__2578_8_a)); 
}


char dangerous_func_cast_sub() {
return ((char)98);
}
void dangerous_func_cast_main() {
auto int (*__2599_6_fp_dangerous_func_cast_main)();
__2599_6_fp_dangerous_func_cast_main = ((int (*)())dangerous_func_cast_sub); 
}



void varargs_func_cast_sub( int __2605_32_n) {  

}
void varargs_func_cast_main() {
auto void (*__2609_11_pt_varargs)(int, ...);
__2609_11_pt_varargs = ((void (*)(int, ...))varargs_func_cast_sub); 
}


int overrun_pf() {
auto int __2615_6_i = 0;
auto int __2616_6_buf[10];
while (1) {
__2615_6_i++;
((__2616_6_buf)[__2615_6_i]) = 0;
if (__2615_6_i >= 10) goto __T43027344;
} __T43027344:;
return 0;
}

void information_leak() {
auto char *__2626_8_path; __2626_8_path = (getenv(((const char *)"PATH")));
fprintf(stderr, ((const char *)__2626_8_path)); 
}

void argument_number_mismatch1( int __2630_36_a) {
printf(((const char *)"a = %d\n"), __2630_36_a); 
}
void argument_number_mismatch2() {  

}


void double_close() {
auto FILE *__2639_8_fp; __2639_8_fp = (fopen(((const char *)"test.txt"), ((const char *)"r")));

fclose(__2639_8_fp);

fclose(__2639_8_fp); 

}

int redundant_condition1() {
return 1;
}
int redundant_condition2() {
return 0;
}
void redundant_condition3() {
auto int __2654_6_x;
auto int __2655_6_y;
#line 610
__2654_6_x = (redundant_condition1());
__2655_6_y = (redundant_condition2());
if ((__2654_6_x == 0) || (__2655_6_y == 0))
printf(((const char *)"hello")); 
}


void minimal_scope() {
if ((a++) == 20)
printf(((const char *)"a = %d\n"), a); 
}
#line 645 "/home/kskyj/sparrow4/util/testcode/c/all_sample.c"
int missing_function_return( float __2669_31_a) {
auto float __2670_8_b = (2.099999905F);
__2670_8_b += __2669_31_a;
return (int)__2670_8_b;
}
