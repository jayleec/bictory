/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:57 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/main.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 434 "/home/kskyj/sparrow4/util/testcode/c/main.c"
struct _sub1;
#line 432
struct _struct_FBD18;
#line 686 "/home/kskyj/sparrow4/util/testcode/c/main.c"
struct _struct;
#line 749 "/home/kskyj/sparrow4/util/testcode/c/main.c"
enum _ZZ12TEST_PRE00_BE5_test_125 { _ZZ12TEST_PRE00_BE4tt_0_125, _ZZ12TEST_PRE00_BE4tt_1_125 = 0, _ZZ12TEST_PRE00_BE4tt_2_125}; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 108 "/home/kskyj/sparrow4/util/testcode/c/main.c"
typedef int wchar_t;
#line 434
struct _sub1 {

int a;};
#line 432
struct _struct_FBD18 {




struct _sub1 a;
int b;};
#line 643
typedef int FBFR;
#line 685 "/home/kskyj/sparrow4/util/testcode/c/main.c"
typedef struct _struct STRUCT;
struct _struct {

int dddd;
int value____value;};
#line 4 "/home/kskyj/sparrow4/util/testcode/c/sub.h"
extern int sum(int a, int b);
extern int substract(int a, int b);
extern double divide(int a, int b);
extern long multiply(int a, int b);
#line 110 "/home/kskyj/sparrow4/util/testcode/c/main.c"
extern int memcpy(char *a, char *b, int size);
extern int memset(char *a, int b, int c);
extern void *malloc(int size);
extern void *realloc(char *dest, int size);
extern void printf(char *format, ...);
extern void scanf(char *format, ...);
extern void fprintf(int *file, char *format, ...);
extern void fscanf(int *file, char *format, ...);
extern void umask();
extern void fopen();
extern int strcmp(char *left, char *rignt);
extern int strlen(char *temp);
extern int wcscmp(wchar_t *left, wchar_t *right);
extern int wcslen(wchar_t *temp);



extern int CERT_SCS_STR33_C();
#line 155
extern int CERT_SCS_ARR01_C(int *p_arr, int p_int, int *p_point);
#line 171
extern void CERT_SCS_INT35_C();
#line 198
extern int CERT_SCS_RRE20_C__get_0_negative(int a);
#line 211
extern int CERT_SCS_RRE20_C__get_0_positive(int a);
#line 217
extern int CERT_SCS_RRE20_C__get_0_1_n1(int a);
#line 223
extern int CERT_SCS_RRE20_C__get_all(int a);
#line 231
extern void CERT_SCS_RRE20_C__test();
#line 299
extern void LcfApError();
extern void LcfSetUIMsg();
extern void END_API22();
extern void Fun_API22();
#line 308
extern void Fun_API22_Alarm1();
#line 314
extern void Fun_API22_safe();
#line 321
extern void Fun_API17_API18_NONE(char *temp);


extern void Fun_API17_API18_QUAL(const char *temp);
#line 330
extern void Fun_API13();
#line 340
extern int pfmNumPrint();
extern int PFM_ERR(int a, int b);
extern int PFM_DBG(int a, int b);
extern void Fun_API10();




extern void DU_API10();
#line 358
extern void SET_ERR(char *a, int b);
extern void SET_ERR_EXT(int a, int b);
extern int API07_API08_API19_API21_ALARM();
#line 370
extern int API07_API08_API19_API21_SAFE();
#line 379
extern int pfmDlCall(char *a, char *b);



extern int PFM_TRYNJ(int a);



extern void API06_ALARM();
#line 396
extern char *func();
extern void ApplExmnList(int a, ...);
extern void Fun_API04_API14_API15();
#line 409
extern void Fun_API01_API02_API03_API09_API11_API12_API26();
#line 419
extern void DU_API01_API02_API03_API09_API11_API12_API26();
#line 440
extern void Fun_FBD18();
#line 451
extern void FUN_FBD17_ALARM();
#line 465
extern void xmalloc();
#line 482
extern void Fun_FBD16_1();



extern void Fun_FBD16_2();



extern void Fun_FBD16_3();




extern void Fun_FBD16_Alarm();
#line 502
extern int sleep();
extern int alarm();
extern void create_FB13();




extern void FB13_Alarm();
#line 516
extern int tmpnam();
extern int mktemp();
extern void create_FB12();




extern void FB12_Alarm();
#line 530
extern int tpcancel();
extern int tprecv();
extern void create_FB11();




extern void FB11_Alarm();
#line 544
extern int signal();
extern int sigaction();
extern void create_FB10();




extern void FB10_Alarm();
#line 558
extern int getrlimit();
extern int setrlimit();
extern void create_FB09();




extern void FB09_Alarm();
#line 572
extern int fork();
extern int vfork();
extern void create_FB08();




extern void FB08_Alarm();
#line 597
extern void FBN_call_param(int FBN_int_param, float a);
#line 606
extern void Fun_FBD07_SAFE();
#line 614
extern void Fun_FBD06_SAFE();




extern void FBD06_Alarm();
#line 628
extern void getenv(char *a);
extern void waitFor();
extern void FB0D04_FBOD05();
#line 636
extern void FB0D04_FBOD05_ALARM();
#line 644
extern void LOG_PC();
extern void LOG_WRITE();
extern void FBD03(FBFR *temp);




extern void FBD03_ALARAM_1(FBFR *temp);



extern void FBD03_ALARAM_2(FBFR *temp);
#line 661
extern void FBD02_ALARM();
#line 694 "/home/kskyj/sparrow4/util/testcode/c/main.c"
extern int routine_in_macro(int p1, int p2);

extern int test_macro_param_sub(int a, int b);



extern int test_macro_param();
#line 707
extern int get_100();
#line 717 "/home/kskyj/sparrow4/util/testcode/c/main.c"
extern int test_double_param(int a, int b);




extern void TEST_PRE00_C(int param1);
#line 747
extern int TEST_PRE00_B(int p1);
#line 764
extern int add(int a, int b);
#line 799 "/home/kskyj/sparrow4/util/testcode/c/main.c"
extern int *get_pointer();
#line 817 "/home/kskyj/sparrow4/util/testcode/c/main.c"
extern int vodmain(int argc, char **argv);
#line 149 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int CERT_SCS_ARR31_C_int;
int *CERT_SCS_ARR31_C_int_pointer;
int CERT_SCS_ARR31_C_int_arr[100];
#line 586
int FBN_int;
#line 613
extern char *var_FBD06;
#line 692 "/home/kskyj/sparrow4/util/testcode/c/main.c"
STRUCT g_struct;

extern char **g_p_p_value; char **g_p_p_value2; extern int g_var_in_macro;
#line 798 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int global_pointer[100];
#line 808
int g_int_value;
#line 613 "/home/kskyj/sparrow4/util/testcode/c/main.c"
char *var_FBD06 = ((char *)0);
#line 694 "/home/kskyj/sparrow4/util/testcode/c/main.c"
char **g_p_p_value = ((char **)0); int g_var_in_macro = 0;
#line 110 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int memcpy( char *__41_19_a,  char *__41_29_b,  int __41_36_size) { return 0; }
int memset( char *__42_19_a,  int __42_26_b,  int __42_33_c) { return 10; }
void *malloc( int __43_19_size) { return ((void *)0); }
void *realloc( char *__44_23_dest,  int __44_33_size) { return ((void *)0); }
void printf( char *__45_20_format, ...) {   }
void scanf( char *__46_19_format, ...) {   }
void fprintf( int *__47_20_file,  char *__47_33_format, ...) {   }
void fscanf( int *__48_19_file,  char *__48_32_format, ...) {   }
void umask() {   }
void fopen() {   }
int strcmp( char *__51_19_left,  char *__51_32_rignt) { return 0; }
int strlen( char *__52_19_temp) { return 0; }
int wcscmp( wchar_t *__53_22_left,  wchar_t *__53_38_right) { return 0; }
int wcslen( wchar_t *__54_22_temp) { return 0; }



int CERT_SCS_STR33_C()
{ static long __T42318320[8] = {97,98,99,100,101,102,103,0};
auto wchar_t *__60_12_wide_str1 = ((wchar_t *)__T42318320);
auto char *__61_9_char_str1 = "abcdefg";

auto wchar_t *__63_12_t_wide_str1;
auto wchar_t *__64_12_t_wide_str2;
auto wchar_t *__65_12_t_wide_str3;
#line 132
__63_12_t_wide_str1 = ((wchar_t *)(malloc(((strlen(__61_9_char_str1)) + 1))));
__64_12_t_wide_str2 = ((wchar_t *)(malloc(((wcslen(__60_12_wide_str1)) + 1))));
__65_12_t_wide_str3 = ((wchar_t *)(malloc(((int)(((unsigned)((wcslen(__60_12_wide_str1)) + 1)) * 4U)))));

__63_12_t_wide_str1 = ((wchar_t *)(malloc(((strlen(__61_9_char_str1)) + 1))));
__64_12_t_wide_str2 = ((wchar_t *)(malloc(((wcslen(__60_12_wide_str1)) + 1))));
__65_12_t_wide_str3 = ((wchar_t *)(malloc(((int)(((unsigned)((wcslen(__60_12_wide_str1)) + 1)) * 4U)))));

wcscmp(((wchar_t *)(malloc(((strlen(((char *)__60_12_wide_str1))) + 1)))), ((wchar_t *)("")));
wcscmp(((wchar_t *)(malloc(((wcslen(__60_12_wide_str1)) + 1)))), ((wchar_t *)("")));
wcscmp(((wchar_t *)(malloc(((int)(((unsigned)((wcslen(__60_12_wide_str1)) + 1)) * 4U))))), ((wchar_t *)("")));

return 0;
}
#line 155
int CERT_SCS_ARR01_C( int *__86_26_p_arr,  int __86_39_p_int,  int *__86_52_p_point)
{
auto int __88_6_a = 0;
auto int __89_6_b = 0;

__88_6_a = 4;
__89_6_b = 4;

__88_6_a = 4;
__89_6_b = 4;

return __88_6_a + __89_6_b;
}



void CERT_SCS_INT35_C()
{
auto long long __104_12_long_long_value = 10LL;
auto unsigned __105_15_unsigned_int_value;
auto long long __106_12_long_long_value_temp;
#line 174
__105_15_unsigned_int_value = ((unsigned)__104_12_long_long_value);
__106_12_long_long_value_temp = __104_12_long_long_value;

__105_15_unsigned_int_value = ((unsigned)(__104_12_long_long_value * 10LL));
__105_15_unsigned_int_value = (((unsigned)__104_12_long_long_value) * 10U);
__105_15_unsigned_int_value = (((unsigned)__104_12_long_long_value) * 10U);

if (((long long)__105_15_unsigned_int_value) == __104_12_long_long_value)
{
}

while (__105_15_unsigned_int_value <= ((unsigned)__104_12_long_long_value))
{
}

for (__105_15_unsigned_int_value = 0U; (((long long)__105_15_unsigned_int_value) < __104_12_long_long_value); __105_15_unsigned_int_value++)


{
} 
}



int CERT_SCS_RRE20_C__get_0_negative( int __129_42_a)
{
auto int __131_6_ret = 0;
if (1)
{
return (-1);
}

else  {
return (-4);
}
return __131_6_ret;
}
int CERT_SCS_RRE20_C__get_0_positive( int __142_42_a)
{
return 0;
return 1;
return 2;
}
int CERT_SCS_RRE20_C__get_0_1_n1( int __148_38_a)
{
return (-1);
return 0;
return 1;
}
int CERT_SCS_RRE20_C__get_all( int __154_35_a)
{
auto int __156_6_ret = 0;

__156_6_ret = (CERT_SCS_RRE20_C__get_0_negative(20));
return __156_6_ret;
}

void CERT_SCS_RRE20_C__test()
{
auto int __164_6_a = 0;

if (CERT_SCS_RRE20_C__get_0_negative(10))
if ((CERT_SCS_RRE20_C__get_0_negative(10)) < 0)
if ((CERT_SCS_RRE20_C__get_0_negative(10)) <= 0)
if ((CERT_SCS_RRE20_C__get_0_negative(10)) == 0)
if ((CERT_SCS_RRE20_C__get_0_negative(10)) != 0)
if ((CERT_SCS_RRE20_C__get_0_negative(10)) >= 0)
if ((CERT_SCS_RRE20_C__get_0_negative(10)) > 0)
if ((CERT_SCS_RRE20_C__get_0_negative(10)) == 1)
__164_6_a = 10;

if (CERT_SCS_RRE20_C__get_0_positive(10))
if ((CERT_SCS_RRE20_C__get_0_positive(10)) < 0)
if ((CERT_SCS_RRE20_C__get_0_positive(10)) <= 0)
if ((CERT_SCS_RRE20_C__get_0_positive(10)) == 0)
if ((CERT_SCS_RRE20_C__get_0_positive(10)) != 0)
if ((CERT_SCS_RRE20_C__get_0_positive(10)) >= 0)
if ((CERT_SCS_RRE20_C__get_0_positive(10)) > 0)
if ((CERT_SCS_RRE20_C__get_0_positive(10)) == 1)
__164_6_a = 10;

if (CERT_SCS_RRE20_C__get_0_1_n1(10))
if ((CERT_SCS_RRE20_C__get_0_1_n1(10)) < 0)
if ((CERT_SCS_RRE20_C__get_0_1_n1(10)) <= 0)
if ((CERT_SCS_RRE20_C__get_0_1_n1(10)) == 0)
if ((CERT_SCS_RRE20_C__get_0_1_n1(10)) != 0)
if ((CERT_SCS_RRE20_C__get_0_1_n1(10)) >= 0)
if ((CERT_SCS_RRE20_C__get_0_1_n1(10)) > 0)
if ((CERT_SCS_RRE20_C__get_0_1_n1(10)) == 1)
__164_6_a = 10;

if (CERT_SCS_RRE20_C__get_all(10))
if ((CERT_SCS_RRE20_C__get_all(10)) < 0)
if ((CERT_SCS_RRE20_C__get_all(10)) <= 0)
if ((CERT_SCS_RRE20_C__get_all(10)) == 0)
if ((CERT_SCS_RRE20_C__get_all(10)) != 0)
if ((CERT_SCS_RRE20_C__get_all(10)) >= 0)
if ((CERT_SCS_RRE20_C__get_all(10)) > 0)
if ((CERT_SCS_RRE20_C__get_all(10)) == 1)
__164_6_a = 10;

if (strcmp("", " "))
if ((strcmp("", " ")) < 0)
if ((strcmp("", " ")) <= 0)
if ((strcmp("", " ")) == 0)
if ((strcmp("", " ")) != 0)
if ((strcmp("", " ")) >= 0)
if ((strcmp("", " ")) > 0)
if ((strcmp("", " ")) == 1)
__164_6_a = 10;

if (strlen(""))
if ((strlen("")) < 0)
if ((strlen("")) <= 0)
if ((strlen("")) == 0)
if ((strlen("")) != 0)
if ((strlen("")) >= 0)
if ((strlen("")) > 0)
if ((strlen("")) == 1)
__164_6_a = 10; 
}




void LcfApError() {   }
void LcfSetUIMsg() {   }
void END_API22() {   }
void Fun_API22()
{
LcfApError();
LcfSetUIMsg();
END_API22(); 
}
void Fun_API22_Alarm1()
{
END_API22();
LcfSetUIMsg();
LcfApError(); 
}
void Fun_API22_safe()
{
LcfApError(); 
}



void Fun_API17_API18_NONE( char *__252_34_temp)
{  
}
void Fun_API17_API18_QUAL( const char *__255_40_temp)
{  
}



void Fun_API13()
{
auto char __263_7_left[10];
auto int __264_6_a = 10;
memset((__263_7_left), 0, (strlen((__263_7_left))));
memset((__263_7_left), 0, __264_6_a);
memset((__263_7_left), 0x1, 10); 
}


int pfmNumPrint() { return 10; }
int PFM_ERR( int __272_17_a,  int __272_24_b) { return 0; }
int PFM_DBG( int __273_17_a,  int __273_24_b) { return 0; }
void Fun_API10()
{
PFM_ERR(10, (pfmNumPrint()));
PFM_DBG(10, 20); 
}
void DU_API10()
{
PFM_ERR(10, (pfmNumPrint()));
PFM_DBG(10, 20); 
}
#line 358
void SET_ERR( char *__289_21_a,  int __289_28_b) {   }
void SET_ERR_EXT( int __290_22_a,  int __290_29_b) {   }
int API07_API08_API19_API21_ALARM()
{
if (1)
{
SET_ERR(((char *)0), 20);
SET_ERR(" ", 20);
SET_ERR_EXT(0, 100);
}
return (-100);
}
int API07_API08_API19_API21_SAFE()
{
SET_ERR_EXT(0, 100);
SET_ERR("ERR001", 100);
return 0;
}



int pfmDlCall( char *__310_22_a,  char *__310_32_b)
{
return 20;
}
int PFM_TRYNJ( int __314_19_a)
{
return 30;
}
void API06_ALARM()
{
auto char *__320_9_args = "..";
auto int __321_6_c; __321_6_c = (PFM_TRYNJ((pfmDlCall("struct88", __320_9_args))));
pfmDlCall("struct88", __320_9_args); 
}



char *func() { return ""; }
void ApplExmnList( int __328_23_a, ...) {   }
void Fun_API04_API14_API15()
{
auto char *__331_9_pString; __331_9_pString = (func());
ApplExmnList(3, 1, 2, 3);
ApplExmnList(3, 1, 2);
ApplExmnList(3, 1);
ApplExmnList(3, __331_9_pString); 
}



void Fun_API01_API02_API03_API09_API11_API12_API26()
{
auto char __342_7_left[100];
auto char *__343_9_temp = "ABCEDFG";
memcpy((__342_7_left), "10", (strlen((__342_7_left))));
memcpy((__342_7_left), "20", (strlen((__342_7_left))));
memcpy((__342_7_left), "ABCEDFG", (strlen("ABCEDFG")));
memcpy((__342_7_left), "Z123456", 8);
memcpy((__342_7_left), __343_9_temp, (strlen((__342_7_left)))); 
}
void DU_API01_API02_API03_API09_API11_API12_API26()
{
auto char __352_7_left[100];
auto char *__353_9_temp = "ABCEDFG";
memcpy((__352_7_left), "10", (strlen((__352_7_left))));
memcpy((__352_7_left), "20", (strlen((__352_7_left))));
memcpy((__352_7_left), "ABCEDFG", (strlen("ABCEDFG")));
memcpy((__352_7_left), "Z123456", 8);
memcpy((__352_7_left), __353_9_temp, (strlen((__352_7_left)))); 
}
#line 440
void Fun_FBD18()
{
auto struct _struct_FBD18 __373_23_a;
((__373_23_a.a).a) = 10;
(__373_23_a.b) = (((__373_23_a.a).a) + 10);
((__373_23_a.a).a) = 20;
(__373_23_a.b) += ((__373_23_a.a).a);
((__373_23_a.a).a) = 30; 
}


void FUN_FBD17_ALARM()
{
auto int __384_6_i;
for (__384_6_i = 0; (__384_6_i < 10); __384_6_i++)
{
malloc(10);
}
while (__384_6_i > 0)
{
malloc(20);
__384_6_i--;
}
malloc(30); 
}
void xmalloc()
{
auto int __398_6_i;
for (__398_6_i = 0; (__398_6_i < 10); __398_6_i++)
{
malloc(10);
}
while (__398_6_i > 0)
{
malloc(20);
__398_6_i--;
}
malloc(30); 
}



void Fun_FBD16_1()
{
umask(); 
}
void Fun_FBD16_2()
{
fopen(); 
}
void Fun_FBD16_3()
{
fopen();
umask(); 
}
void Fun_FBD16_Alarm()
{
umask();
fopen(); 
}


int sleep() { return 0; }
int alarm() { return 0; }
void create_FB13()
{
auto int __437_9_a;
auto int __438_9_b;
#line 506
__437_9_a = (sleep());
__438_9_b = (alarm()); 
}
void FB13_Alarm()
{
auto int __442_9_a;
auto int __443_9_b;
#line 511
__442_9_a = (sleep());
__443_9_b = (alarm()); 
}


int tmpnam() { return 0; }
int mktemp() { return 0; }
void create_FB12()
{
auto int __451_9_a;
auto int __452_9_b;
#line 520
__451_9_a = (tmpnam());
__452_9_b = (mktemp()); 
}
void FB12_Alarm()
{
auto int __456_9_a;
auto int __457_9_b;
#line 525
__456_9_a = (tmpnam());
__457_9_b = (mktemp()); 
}


int tpcancel() { return 0; }
int tprecv() { return 0; }
void create_FB11()
{
auto int __465_9_a;
auto int __466_9_b;
#line 534
__465_9_a = (tpcancel());
__466_9_b = (tprecv()); 
}
void FB11_Alarm()
{
auto int __470_9_a;
auto int __471_9_b;
#line 539
__470_9_a = (tpcancel());
__471_9_b = (tprecv()); 
}


int signal() { return 0; }
int sigaction() { return 0; }
void create_FB10()
{
auto int __479_9_a;
auto int __480_9_b;
#line 548
__479_9_a = (signal());
__480_9_b = (sigaction()); 
}
void FB10_Alarm()
{
auto int __484_9_a;
auto int __485_9_b;
#line 553
__484_9_a = (signal());
__485_9_b = (sigaction()); 
}


int getrlimit() { return 0; }
int setrlimit() { return 0; }
void create_FB09()
{
auto int __493_9_a;
auto int __494_9_b;
#line 562
__493_9_a = (getrlimit());
__494_9_b = (setrlimit()); 
}
void FB09_Alarm()
{
auto int __498_9_a;
auto int __499_9_b;
#line 567
__498_9_a = (getrlimit());
__499_9_b = (setrlimit()); 
}


int fork() { return 0; }
int vfork() { return 0; }
void create_FB08()
{
auto int __507_9_a;
auto int __508_9_b;
#line 576
__507_9_a = (fork());
__508_9_b = (vfork()); 
}
void FB08_Alarm()
{
auto int __512_9_a;
auto int __513_9_b;
#line 581
__512_9_a = (fork());
__513_9_b = (vfork()); 
}
#line 597
void FBN_call_param( int __528_25_FBN_int_param,  float __528_46_a)
{
auto int __530_6_FBN_int_local;
__530_6_FBN_int_local = 10;
for (__530_6_FBN_int_local = 0; (__530_6_FBN_int_local < 10); __530_6_FBN_int_local++)
{
auto int __534_7_FBN_int_loop = 10;
} 
}
void Fun_FBD07_SAFE()
{
auto int __539_6_FBN_int_local;
__539_6_FBN_int_local = 10; 
}



void Fun_FBD06_SAFE()
{
var_FBD06 = ((char *)(malloc(10)));
var_FBD06 = ((char *)(realloc(var_FBD06, 20))); 
}
void FBD06_Alarm()
{
var_FBD06 = ((char *)(malloc(10)));
var_FBD06 = ((char *)(realloc(var_FBD06, 20))); 
}




void getenv( char *__559_20_a) {   }
void waitFor() {   }
void FB0D04_FBOD05()
{
getenv("LOG_PATH");
getenv("DB_PATH");
waitFor(); 
}
void FB0D04_FBOD05_ALARM()
{
getenv("..");
getenv("..."); 
}



void LOG_PC() {   }
void LOG_WRITE() {   }
void FBD03( FBFR *__577_19_temp)
{  


}
void FBD03_ALARAM_1( FBFR *__582_28_temp)
{
LOG_PC(); 
}
void FBD03_ALARAM_2( FBFR *__586_28_temp)
{
LOG_WRITE(); 
}


void FBD02_ALARM()
{  
#line 671 "/home/kskyj/sparrow4/util/testcode/c/main.c"
}
#line 694 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int routine_in_macro( int __606_97_p1,  int __606_105_p2) { auto int __606_115_a = 0; auto int __606_126_b = 10; auto int __606_138_c = 0; for ((__606_115_a = 10) , (__606_126_b = 20); (__606_115_a < 100); (__606_115_a++) , (__606_126_b++)) { __606_138_c++; } while (__606_115_a != 20) 
#line 694
__606_115_a++; return __606_138_c + __606_126_b; }

int test_macro_param_sub( int __608_30_a,  int __608_37_b)
{
return __608_30_a + __608_37_b;
}
int test_macro_param()
{
return test_macro_param_sub(10, 10);
return test_macro_param_sub(10, 20);
return 10;
}

int get_100()
{



auto char *__624_2_var_temp = "abcedfg";
#line 713 "/home/kskyj/sparrow4/util/testcode/c/main.c"
auto char *__630_9_var_temp_2 = "ddd";
return 100;
}

int test_double_param( int __634_27_a,  int __634_34_b)
{
return 10;
}

void TEST_PRE00_C( int __639_23_param1)
{
auto int __641_6_val_1 = 10;
auto int __642_6_val_2 = 0;
auto int __643_6_val_3 = 0;
auto int *__644_8_p_val; __644_8_p_val = (&__641_6_val_1);

if (__639_23_param1 > 0)
{
if (__639_23_param1 > 1)
{
auto int __650_8_sub_val_1 = 0;
auto int __651_8_sub_val_2 = 0;

__641_6_val_1 = ((int)((((unsigned long)((((__643_6_val_3 + 1) * (__643_6_val_3 + 1)) * (__643_6_val_3 + 1)) + 10)) + ((unsigned long)((int)(g_struct.value____value)))) + ((unsigned long)(g_struct.value____value))));
__641_6_val_1 = ((int)(((unsigned long)((((__643_6_val_3++) + (1 * (__643_6_val_3++))) + (1 * (__643_6_val_3++))) + 1)) + 10UL));
__641_6_val_1 = ((int)(((unsigned long)(((__643_6_val_3 + (1 * __643_6_val_3)) + (1 * __643_6_val_3)) + 1)) + 10UL));
__642_6_val_2 = 20;
__642_6_val_2 = ((int)(((++__641_6_val_1) , (++__642_6_val_2)) , ((2 * (__641_6_val_1 + (get_100()))) * __643_6_val_3)));
}
} 


}

int TEST_PRE00_B( int __664_22_p1)
{
auto enum _ZZ12TEST_PRE00_BE5_test_125 __666_41_test; auto unsigned __666_60_aaa = 100U; auto int __666_75_bbb = 200; auto int __666_90_ccc = 300; auto char *__666_108_temp = "abcedf\\g ABCEDFG \n"; auto char **__666_147_ppoint = ((char **)0); __666_41_test = ((enum _ZZ12TEST_PRE00_BE5_test_125)0U); 
#line 749
(*(*__666_147_ppoint)) = ((char)0); if ((0 < __664_22_p1) && (__664_22_p1 < 10)) { __666_90_ccc = ((int)((((unsigned long)(((((__666_60_aaa + 100U) * ((unsigned)__666_75_bbb)) * ((__666_60_aaa + 100U) * ((unsigned)__666_75_bbb))) * ((__666_60_aaa + 100U) * ((unsigned)__666_75_bbb))) + ((unsigned)((30 
#line 749
+ (get_100())) + __664_22_p1)))) + ((unsigned long)((int)(g_struct.value____value)))) + ((unsigned long)(g_struct.value____value)))); __666_90_ccc = 10; } else  if (__664_22_p1 > 20) { switch (__666_75_bbb) { case 10: __666_90_ccc = 10; { auto int __666_457_b = 3; __666_90_ccc += __666_457_b; } 
#line 749
goto __T42545408; case 20: __666_90_ccc = 20;
return 30;
goto __T42545408;
case 30:
goto __673_1_TEST;
goto __T42545408;
} __T42545408:;
__673_1_TEST:;
__666_90_ccc++;
}
return __666_90_ccc;
return 10;
}


int add( int __681_13_a,  int __681_20_b)
{
auto int __683_6_ret = 0;

return __683_6_ret;
}
#line 799 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int *get_pointer()
{
auto int __691_6_i;
auto int __692_6_j;
for ((__691_6_i = 0) , (__692_6_j = 20); (__691_6_i < 10); __691_6_i++)
;
return global_pointer;
}
#line 817 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int vodmain( int __700_17_argc,  char **__700_30_argv)
{
auto int __702_6_c;
auto int __703_6_d;

auto double __705_9_e;
auto long __706_7_f;
#line 819
__702_6_c = (sum(10, 20));
__703_6_d = (substract(__702_6_c, 10));

__705_9_e = (divide(100, 3));
__706_7_f = (multiply(10, 20));

return __702_6_c;
}
