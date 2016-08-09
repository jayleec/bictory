# 1 "/home/kskyj/sparrow4/util/testcode/c/main.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/main.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/sub.h" 1



int sum(int a, int b);
int substract(int a, int b);
double divide(int a, int b);
long multiply(int a, int b);
# 2 "/home/kskyj/sparrow4/util/testcode/c/main.c" 2
# 1 "/home/kskyj/sparrow4/util/testcode/c/duplicate_header.h" 1






# 1 "/home/kskyj/sparrow4/util/testcode/c/duplicate_sub_1.h" 1
# 8 "/home/kskyj/sparrow4/util/testcode/c/duplicate_header.h" 2
# 1 "/home/kskyj/sparrow4/util/testcode/c/duplicate_sub_1.h" 1
# 9 "/home/kskyj/sparrow4/util/testcode/c/duplicate_header.h" 2
# 1 "/home/kskyj/sparrow4/util/testcode/c/duplicate_sub_2.h" 1
# 10 "/home/kskyj/sparrow4/util/testcode/c/duplicate_header.h" 2

extern int duplicate_int_value;
void duplicate_function();
# 3 "/home/kskyj/sparrow4/util/testcode/c/main.c" 2
# 1 "/home/kskyj/sparrow4/util/testcode/c/main.h" 1
# 78 "/home/kskyj/sparrow4/util/testcode/c/main.h"
extern int CERT_SCS_ARR31_C_int_arr_2[];
extern int CERT_SCS_ARR31_C_int;
extern int * CERT_SCS_ARR31_C_int_pointer;
extern int CERT_SCS_ARR31_C_int_arr[];
# 4 "/home/kskyj/sparrow4/util/testcode/c/main.c" 2
# 108 "/home/kskyj/sparrow4/util/testcode/c/main.c"
typedef int wchar_t;

int memcpy(char * a, char * b, int size) { return 0; }
int memset(char * a, int b, int c) { return 10; }
void * malloc(int size) { return 0; }
void * realloc(char * dest, int size) { return 0; }
void printf(char * format, ...) { }
void scanf(char * format, ...) { }
void fprintf(int * file, char * format, ...) { }
void fscanf(int * file, char * format, ...) { }
void umask() { }
void fopen() { }
int strcmp(char * left, char * rignt) { return 0; }
int strlen(char * temp) { return 0; }
int wcscmp(wchar_t * left, wchar_t * right) { return 0; }
int wcslen(wchar_t * temp) { return 0; }



int CERT_SCS_STR33_C()
{
 wchar_t * wide_str1 = L"abcdefg";
 char * char_str1 = "abcdefg";

 wchar_t * t_wide_str1 = (wchar_t *)malloc(strlen(char_str1) + 1);
 wchar_t * t_wide_str2 = (wchar_t *)malloc(wcslen(wide_str1) + 1);
 wchar_t * t_wide_str3 = (wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t));

 t_wide_str1 = (wchar_t *)malloc(strlen(char_str1) + 1);
 t_wide_str2 = (wchar_t *)malloc(wcslen(wide_str1) + 1);
 t_wide_str3 = (wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t));

 wcscmp((wchar_t *)malloc(strlen(wide_str1) + 1), "");
 wcscmp((wchar_t *)malloc(wcslen(wide_str1) + 1), "");
 wcscmp((wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t)), "");

 return 0;
}



int CERT_SCS_ARR31_C_int;
int * CERT_SCS_ARR31_C_int_pointer;
int CERT_SCS_ARR31_C_int_arr[100];



int CERT_SCS_ARR01_C(int p_arr[], int p_int, int * p_point)
{
 int a = 0;
 int b = 0;

 a = sizeof(p_arr);
 b = sizeof(p_arr[10]);

 a = sizeof(p_int);
 b = sizeof(p_point);

 return a + b;
}



void CERT_SCS_INT35_C()
{
 long long long_long_value = 10;
 unsigned int unsigned_int_value = long_long_value;
 long long long_long_value_temp = long_long_value;

 unsigned_int_value = long_long_value * 10;
 unsigned_int_value = (unsigned int)long_long_value * 10;
 *(&unsigned_int_value) = (unsigned int)long_long_value * 10;

 if (unsigned_int_value == long_long_value)
 {
 }

 while (unsigned_int_value <= (unsigned int)long_long_value)
 {
 }

 for (unsigned_int_value = 0;
  (long long)unsigned_int_value < long_long_value;
  unsigned_int_value++)
 {
 }
}



int CERT_SCS_RRE20_C__get_0_negative(int a)
{
 int ret = 0;
 if (1)
 {
  return -1;
 }
 else
 {
  return -4;
 }
 return ret;
}
int CERT_SCS_RRE20_C__get_0_positive(int a)
{
 return 0;
 return 1;
 return 2;
}
int CERT_SCS_RRE20_C__get_0_1_n1(int a)
{
 return -1;
 return 0;
 return 1;
}
int CERT_SCS_RRE20_C__get_all(int a)
{
 int ret = 0;

 ret = CERT_SCS_RRE20_C__get_0_negative(20);
 return ret;
}

void CERT_SCS_RRE20_C__test()
{
 int a = 0;

 if (CERT_SCS_RRE20_C__get_0_negative(10))
 if (CERT_SCS_RRE20_C__get_0_negative(10) < 0)
 if (CERT_SCS_RRE20_C__get_0_negative(10) <= 0)
 if (CERT_SCS_RRE20_C__get_0_negative(10) == 0)
 if (CERT_SCS_RRE20_C__get_0_negative(10) != 0)
 if (CERT_SCS_RRE20_C__get_0_negative(10) >= 0)
 if (CERT_SCS_RRE20_C__get_0_negative(10) > 0)
 if (CERT_SCS_RRE20_C__get_0_negative(10) == 1)
  a = 10;

 if (CERT_SCS_RRE20_C__get_0_positive(10))
 if (CERT_SCS_RRE20_C__get_0_positive(10) < 0)
 if (CERT_SCS_RRE20_C__get_0_positive(10) <= 0)
 if (CERT_SCS_RRE20_C__get_0_positive(10) == 0)
 if (CERT_SCS_RRE20_C__get_0_positive(10) != 0)
 if (CERT_SCS_RRE20_C__get_0_positive(10) >= 0)
 if (CERT_SCS_RRE20_C__get_0_positive(10) > 0)
 if (CERT_SCS_RRE20_C__get_0_positive(10) == 1)
  a = 10;

 if (CERT_SCS_RRE20_C__get_0_1_n1(10))
 if (CERT_SCS_RRE20_C__get_0_1_n1(10) < 0)
 if (CERT_SCS_RRE20_C__get_0_1_n1(10) <= 0)
 if (CERT_SCS_RRE20_C__get_0_1_n1(10) == 0)
 if (CERT_SCS_RRE20_C__get_0_1_n1(10) != 0)
 if (CERT_SCS_RRE20_C__get_0_1_n1(10) >= 0)
 if (CERT_SCS_RRE20_C__get_0_1_n1(10) > 0)
 if (CERT_SCS_RRE20_C__get_0_1_n1(10) == 1)
  a = 10;

 if (CERT_SCS_RRE20_C__get_all(10))
 if (CERT_SCS_RRE20_C__get_all(10) < 0)
 if (CERT_SCS_RRE20_C__get_all(10) <= 0)
 if (CERT_SCS_RRE20_C__get_all(10) == 0)
 if (CERT_SCS_RRE20_C__get_all(10) != 0)
 if (CERT_SCS_RRE20_C__get_all(10) >= 0)
 if (CERT_SCS_RRE20_C__get_all(10) > 0)
 if (CERT_SCS_RRE20_C__get_all(10) == 1)
  a = 10;

 if (strcmp("", " "))
 if (strcmp("", " ") < 0)
 if (strcmp("", " ") <= 0)
 if (strcmp("", " ") == 0)
 if (strcmp("", " ") != 0)
 if (strcmp("", " ") >= 0)
 if (strcmp("", " ") > 0)
 if (strcmp("", " ") == 1)
  a = 10;

 if (strlen(""))
 if (strlen("") < 0)
 if (strlen("") <= 0)
 if (strlen("") == 0)
 if (strlen("") != 0)
 if (strlen("") >= 0)
 if (strlen("") > 0)
 if (strlen("") == 1)
  a = 10;
}




void LcfApError() { }
void LcfSetUIMsg() { }
void END_API22() { }
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



void Fun_API17_API18_NONE(char * temp)
{
}
void Fun_API17_API18_QUAL(const char * temp)
{
}



void Fun_API13()
{
 char left[10];
 int a = 10;
 memset(left, 0x00, strlen(left));
 memset(left, 0x00, a);
 memset(left, 0x01, 10);
}


int pfmNumPrint() { return 10; }
int PFM_ERR(int a, int b) { return 0; }
int PFM_DBG(int a, int b) { return 0; }
void Fun_API10()
{
 PFM_ERR(10, pfmNumPrint());
 PFM_DBG(10, 20);
}
void DU_API10()
{
 PFM_ERR(10, pfmNumPrint());
 PFM_DBG(10, 20);
}





void SET_ERR(char * a, int b) {}
void SET_ERR_EXT(int a, int b) {}
int API07_API08_API19_API21_ALARM()
{
 if (1)
 {
  SET_ERR(0, 20);
  SET_ERR(" ", 20);
  SET_ERR_EXT(0, 100);
 }
 return -100;
}
int API07_API08_API19_API21_SAFE()
{
 SET_ERR_EXT(0, 100);
 SET_ERR("ERR001", 100);
 return 0;
}



int pfmDlCall(char * a, char * b)
{
 return 20;
}
int PFM_TRYNJ(int a)
{
 return 30;
}
void API06_ALARM()
{
 char * args = "..";
 int c = PFM_TRYNJ(pfmDlCall("struct88", args));
 pfmDlCall("struct88", args);
}



char * func() { return ""; }
void ApplExmnList(int a, ...) {}
void Fun_API04_API14_API15()
{
 char * pString = func();
 ApplExmnList(3, 1, 2, 3);
 ApplExmnList(3, 1, 2);
 ApplExmnList(3, 1);
 ApplExmnList(3, pString);
}



void Fun_API01_API02_API03_API09_API11_API12_API26()
{
 char left[100];
 char * temp = "ABCEDFG";
 memcpy(left, "10", strlen(left));
 memcpy(left, "20", strlen(left));
 memcpy(left, "ABCEDFG", strlen("ABCEDFG"));
 memcpy(left, "Z123456", 8);
 memcpy(left, temp, strlen(left));
}
void DU_API01_API02_API03_API09_API11_API12_API26()
{
 char left[100];
 char * temp = "ABCEDFG";
 memcpy(left, "10", strlen(left));
 memcpy(left,"20", strlen(left));
 memcpy(left, "ABCEDFG", strlen("ABCEDFG"));
 memcpy(left, "Z123456", 8);
 memcpy(left, temp, strlen(left));
}



struct _struct_FBD18
{
 struct _sub1
 {
  int a;
 } a;
 int b;
};
void Fun_FBD18()
{
 struct _struct_FBD18 a;
 a.a.a = 10;
 a.b = a.a.a + 10;
 a.a.a = 20;
 a.b += a.a.a;
 a.a.a = 30;
}


void FUN_FBD17_ALARM()
{
 int i;
 for (i = 0; i < 10; i ++)
 {
  malloc(10);
 }
 while (i > 0)
 {
  malloc(20);
  i --;
 }
 malloc(30);
}
void xmalloc()
{
 int i;
 for (i = 0; i < 10; i ++)
 {
  malloc(10);
 }
 while (i > 0)
 {
  malloc(20);
  i --;
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
    int a = sleep();
    int b = alarm();
}
void FB13_Alarm()
{
    int a = sleep();
    int b = alarm();
}


int tmpnam() { return 0; }
int mktemp() { return 0; }
void create_FB12()
{
    int a = tmpnam();
    int b = mktemp();
}
void FB12_Alarm()
{
    int a = tmpnam();
    int b = mktemp();
}


int tpcancel() { return 0; }
int tprecv() { return 0; }
void create_FB11()
{
    int a = tpcancel();
    int b = tprecv();
}
void FB11_Alarm()
{
    int a = tpcancel();
    int b = tprecv();
}


int signal() { return 0; }
int sigaction() { return 0; }
void create_FB10()
{
    int a = signal();
    int b = sigaction();
}
void FB10_Alarm()
{
    int a = signal();
    int b = sigaction();
}


int getrlimit() { return 0; }
int setrlimit() { return 0; }
void create_FB09()
{
    int a = getrlimit();
    int b = setrlimit();
}
void FB09_Alarm()
{
    int a = getrlimit();
    int b = setrlimit();
}


int fork() { return 0; }
int vfork() { return 0; }
void create_FB08()
{
    int a = fork();
    int b = vfork();
}
void FB08_Alarm()
{
    int a = fork();
    int b = vfork();
}


int FBN_int;
struct _FBN_struct
{
 int FBN_int_member;
};
struct _FBN_struct_safe
{
 int int_value_member;
};
typedef int (*FBN_FUNC_TYPE)(int a, char FBN_char_param);
void FBN_call_param(int FBN_int_param, float a);
void FBN_call_param(int FBN_int_param, float a)
{
 int FBN_int_local;
 FBN_int_local = 10;
 for (FBN_int_local = 0; FBN_int_local < 10; FBN_int_local ++)
 {
  int FBN_int_loop = 10;
 }
}
void Fun_FBD07_SAFE()
{
 int FBN_int_local;
 FBN_int_local = 10;
}


char * var_FBD06 = 0;
void Fun_FBD06_SAFE()
{
 var_FBD06 = (char *)malloc(10);
 var_FBD06 = (char *)realloc(var_FBD06, 20);
}
void FBD06_Alarm()
{
 var_FBD06 = (char *)malloc(10);
 var_FBD06 = (char *)realloc(var_FBD06, 20);
}




void getenv(char * a) { }
void waitFor() { }
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


typedef int FBFR;
void LOG_PC() { }
void LOG_WRITE() { }
void FBD03(FBFR * temp)
{


}
void FBD03_ALARAM_1(FBFR * temp)
{
 LOG_PC();
}
void FBD03_ALARAM_2(FBFR * temp)
{
 LOG_WRITE();
}


void FBD02_ALARM()
{
# 671 "/home/kskyj/sparrow4/util/testcode/c/main.c"
}
# 685 "/home/kskyj/sparrow4/util/testcode/c/main.c"
typedef struct _struct STRUCT;
struct _struct
{
 int dddd;
 int value____value;

};
STRUCT g_struct;

char ** g_p_p_value = 0; char ** g_p_p_value2; int g_var_in_macro = 0; int routine_in_macro(int p1, int p2) { int a = 0; int b = 10; int c = 0; for (a = 10, b = 20; a < 100; a ++, b++) { c ++; } while (a != 20) a ++; return c + b; }

int test_macro_param_sub(int a, int b)
{
 return a + b;
}
int test_macro_param()
{
 return test_macro_param_sub(10, 10);
 return test_macro_param_sub(10,20);
 return 10;
}

int get_100()
{
 char *


 var_temp
# 709 "/home/kskyj/sparrow4/util/testcode/c/main.c"
 = "abcedfg";



 char * var_temp_2 = "ddd";
 return 100;
}

int test_double_param(int a, int b)
{
 return 10;
}

void TEST_PRE00_C(int param1)
{
 int val_1 = 10;
 int val_2 = 0;
 int val_3 = 0;
 int * p_val = &val_1;

 if (param1 > 0 )
 {
  if (param1 > 1)
  {
   int sub_val_1 = 0;
   int sub_val_2 = 0;

   val_1 = (int)((val_3 + 1)*(val_3 + 1)*(val_3 + 1) + (10) + (unsigned long)(int)(&g_struct)->value____value + g_struct.value____value);
   val_1 = (int)(val_3 ++ + 1 * val_3 ++ + 1 * val_3 ++ + 1 + (unsigned long)(int)10);
   val_1 = (int)(val_3 + 1 * val_3 + 1 * val_3 + 1 + (unsigned long)(int)10);
   val_2 = (10, 20 + 30, 30 - 10);
   val_2 = (int)(++val_1, ++val_2, 2*(val_1 + get_100()) * val_3);
  }
 }


}

int TEST_PRE00_B(int p1)
{
 enum _test { tt_0, tt_1 = tt_0, tt_2 } test; unsigned int aaa = 100; int bbb = 200; int ccc = 300; char * temp = "abcedf\\g ABCEDFG \n"; char ** ppoint = 0; test = tt_0; **ppoint = 0; if (0 < p1 && p1 < 10) { ccc = (int)(((aaa + 100) * bbb)*((aaa + 100) * bbb)*((aaa + 100) * bbb) + (30 + get_100() + p1) + (unsigned long)(int)(&g_struct)->value____value + g_struct.value____value); ccc = 10; } else if (p1 > 20) { switch (bbb) { case 10: ccc = 10; { int b = 3; ccc += b; } break; case 20: ccc = 20;
   return 30;
   break;
  case 30:
   goto TEST;
   break;
  }
TEST:
  ccc ++;
 }
 return ccc;
 return 10;
}


int add(int a, int b)
{
 int ret = 0;

 return ret;
}
# 798 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int global_pointer[100];
int * get_pointer()
{
 int i;
 int j;
 for (i = 0, j = 20; i < 10; i ++)
  ;
 return global_pointer;
}

int g_int_value;
# 817 "/home/kskyj/sparrow4/util/testcode/c/main.c"
int vodmain(int argc, char * argv[])
{
 int c = sum(10, 20);
 int d = substract(c, 10);

 double e = divide(100, 3);
 long f = multiply(10, 20);

 return c;
}
