#include "sub.h"
#include "duplicate_header.h"
#include "main.h"
//typedef int a_boolean;
//#define CAST_TEST (a_boolean *)a + 10 
//
//a(int k);
//int b()
//{
//	int * a = 0;	//byte a;
//	a = CAST_TEST;
//	return 10;
//}
//
//#define NULL	0
//#define FALSE	0
//typedef unsigned int sizeof_t;
//typedef void * a_void_ptr;
//typedef char a_byte_boolean;
//#define incr_token_set_array_element(array, tok) (array)[(int)(tok)]++
//typedef struct a_pch_saved_variable {
//  a_void_ptr	var_address;
//  sizeof_t	var_size;
//  a_byte_boolean	indirect;
//  char *var_name;
//} a_pch_saved_variable;
//#define pch_saved_var_name(var) , #var
//#define pch_saved_var_array_terminating_elem()	{ (a_void_ptr)NULL, (sizeof_t)0, FALSE pch_saved_var_name(NULL) }
//struct _known_attr_table {	int a;	} known_attr_table[10];
//#define KNOWN_ATTR_TABLE_LENGTH		((sizeof_t)(sizeof(known_attr_table)/sizeof(known_attr_table[0])-1))
//
//typedef int a_token_sequence_number;
//struct a_symbol_header	{	int a;	};
//void next_token_full(int * i, struct a_symbol_header ** j)	{	}
//#define NEXT_TOKEN()	(next_token_full((a_token_sequence_number*)NULL, (struct a_symbol_header **)NULL))
//void NEXT_TOKE_FUNCTION()
//{
//	int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//	static a_pch_saved_variable saved_vars[] = {
//		pch_saved_var_array_terminating_elem()
//	};
//	incr_token_set_array_element(a, 2);
//	KNOWN_ATTR_TABLE_LENGTH;
//	NEXT_TOKEN();
//}
//
//static int g_extern_static_int_val;
//#define STDCALL_FUNCTION	\
//	int _stdcall std_call_function(int a)	\
//	{	\
//		return 100;	\
//	}
//
//STDCALL_FUNCTION
//
//#define STATIC_DEF_VAR	static int int_value
//#define EXPORT_FUNCTION __declspec (dllexport)
//EXPORT_FUNCTION int _export_function()
//{
//	STATIC_DEF_VAR;
//	return 10;
//}
//
//#define SDL_COMPILE_TIME_ASSERT(name, x)	typedef int SDL_dummy_ ## name[(x) * 2 - 1]
//typedef int Bitu;
//typedef Bitu (*CallBack_Handler)(void);
//typedef signed long Bit32s;
//#define BIT32S Bit32s
//#define MACRO_UNKNOW_SYMBOL_1(x) (BIT32S)x + 10;
//#define reg_8(reg) ((reg) & 4 ? reg_8h((reg) & 3) : reg_8l((reg) & 3))
//#define MACRO_BRACKET(reg) (regs[(reg)])
//
//int reg_8h(int a)	{	return a + 1;	}
//int reg_8l(int b)	{	return b + 1;	}
//void test_macro_bracket()
//{
//	typedef int typedef_int[10];
//	typedef_int dddd;
//	char regs[100];
//	int a = 0;
//	signed long b = 0;
//	SDL_COMPILE_TIME_ASSERT(name, 10);
//
//	SDL_dummy_name aaaa;
//
//	a = sizeof(unsigned int);
//	aaaa[10] = 2;
//	dddd[0] = 10;
//	
//	b = MACRO_UNKNOW_SYMBOL_1(a);
//
//	a = reg_8(20);
//	MACRO_BRACKET(10);
//
//	++ (unsigned int)a; 
//}
//
//
//extern int duplicate_int_value;
//void duplicate_function()
//{
//}



/*	stdio.h 등의 system function 더미	-------------------------------	*/
#ifndef __cplusplus
typedef int wchar_t;
#endif
int memcpy(char * a, char * b, int size)	{	return 0;	}
int memset(char * a, int b, int c)	{	return 10;	}
void * malloc(int size)	{	return 0;	}
void * realloc(char * dest, int size)	{	return 0;	}
void printf(char * format, ...)	{	}
void scanf(char * format, ...)	{	}
void fprintf(int * file, char * format, ...)	{	}
void fscanf(int * file, char * format, ...)	{	}
void umask()	{	}
void fopen()	{	}
int strcmp(char * left, char * rignt)		{	return 0;	} 
int strlen(char * temp)						{	return 0;	}
int wcscmp(wchar_t * left, wchar_t * right)	{	return 0;	}
int wcslen(wchar_t * temp)					{	return 0;	}


/*	CERT_SCS_STR33_C	-------------------------------	*/
int CERT_SCS_STR33_C()
{
	wchar_t * wide_str1 = L"abcdefg";
	char * char_str1 = "abcdefg";

	wchar_t * t_wide_str1 = (wchar_t *)malloc(strlen(char_str1) + 1);
	wchar_t * t_wide_str2 = (wchar_t *)malloc(wcslen(wide_str1) + 1);						
	wchar_t * t_wide_str3 = (wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t)); // 실제 크기를 만들어줌.

	t_wide_str1 = (wchar_t *)malloc(strlen(char_str1) + 1);
	t_wide_str2 = (wchar_t *)malloc(wcslen(wide_str1) + 1);						
	t_wide_str3 = (wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t)); // 실제 크기를 만들어줌.

	wcscmp((wchar_t *)malloc(strlen(wide_str1) + 1), "");
	wcscmp((wchar_t *)malloc(wcslen(wide_str1) + 1), "");
	wcscmp((wchar_t *)malloc((wcslen(wide_str1) + 1) * sizeof(wchar_t)), "");

	return 0;
}

/*	CERT_SCS_ARR31_C	-------------------------------	*/
//extern int * CERT_SCS_ARR31_C_int_arr;	//	Alarm
int CERT_SCS_ARR31_C_int;
int * CERT_SCS_ARR31_C_int_pointer;
int CERT_SCS_ARR31_C_int_arr[100];


/*	CERT_SCS_ARR01_C	-------------------------------	*/
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


/*	CERT_SCS_INT35_C	-------------------------------	*/
void CERT_SCS_INT35_C()
{
	long long long_long_value = 10;
	unsigned int unsigned_int_value = long_long_value;				//	alarm
	long long long_long_value_temp = long_long_value;				//	safe

	unsigned_int_value = long_long_value * 10;						//	alarm
	unsigned_int_value = (unsigned int)long_long_value * 10;		//	safe
	*(&unsigned_int_value) = (unsigned int)long_long_value * 10;	//	safe

	if (unsigned_int_value == long_long_value)						//	alarm
	{
	}

	while (unsigned_int_value <= (unsigned int)long_long_value)		//	safe
	{
	}

	for (unsigned_int_value = 0;									
		(long long)unsigned_int_value < long_long_value;			//	safe
		unsigned_int_value++)
	{
	}
}


/*	CERT_SCS_RRE20_C	-------------------------------	*/
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
	/*	모든 function은 자연수로 봄.	*/
	ret = CERT_SCS_RRE20_C__get_0_negative(20);
	return ret;
}

void CERT_SCS_RRE20_C__test()
{
	int a = 0;

	if (CERT_SCS_RRE20_C__get_0_negative(10))
	if (CERT_SCS_RRE20_C__get_0_negative(10) <  0)
	if (CERT_SCS_RRE20_C__get_0_negative(10) <= 0)
	if (CERT_SCS_RRE20_C__get_0_negative(10) == 0)
	if (CERT_SCS_RRE20_C__get_0_negative(10) != 0)
	if (CERT_SCS_RRE20_C__get_0_negative(10) >= 0)
	if (CERT_SCS_RRE20_C__get_0_negative(10) >  0)
	if (CERT_SCS_RRE20_C__get_0_negative(10) == 1)
		a = 10;

	if (CERT_SCS_RRE20_C__get_0_positive(10))
	if (CERT_SCS_RRE20_C__get_0_positive(10) <  0)
	if (CERT_SCS_RRE20_C__get_0_positive(10) <= 0)
	if (CERT_SCS_RRE20_C__get_0_positive(10) == 0)
	if (CERT_SCS_RRE20_C__get_0_positive(10) != 0)
	if (CERT_SCS_RRE20_C__get_0_positive(10) >= 0)
	if (CERT_SCS_RRE20_C__get_0_positive(10) >  0)
	if (CERT_SCS_RRE20_C__get_0_positive(10) == 1)
		a = 10;

	if (CERT_SCS_RRE20_C__get_0_1_n1(10))
	if (CERT_SCS_RRE20_C__get_0_1_n1(10) <  0)
	if (CERT_SCS_RRE20_C__get_0_1_n1(10) <= 0)
	if (CERT_SCS_RRE20_C__get_0_1_n1(10) == 0)
	if (CERT_SCS_RRE20_C__get_0_1_n1(10) != 0)
	if (CERT_SCS_RRE20_C__get_0_1_n1(10) >= 0)
	if (CERT_SCS_RRE20_C__get_0_1_n1(10) >  0)
	if (CERT_SCS_RRE20_C__get_0_1_n1(10) == 1)
		a = 10;

	if (CERT_SCS_RRE20_C__get_all(10))
	if (CERT_SCS_RRE20_C__get_all(10) <  0)
	if (CERT_SCS_RRE20_C__get_all(10) <= 0)
	if (CERT_SCS_RRE20_C__get_all(10) == 0)
	if (CERT_SCS_RRE20_C__get_all(10) != 0)
	if (CERT_SCS_RRE20_C__get_all(10) >= 0)
	if (CERT_SCS_RRE20_C__get_all(10) >  0)
	if (CERT_SCS_RRE20_C__get_all(10) == 1)
		a = 10;

	if (strcmp("", " "))
	if (strcmp("", " ") <  0)
	if (strcmp("", " ") <= 0)
	if (strcmp("", " ") == 0)
	if (strcmp("", " ") != 0)
	if (strcmp("", " ") >= 0)
	if (strcmp("", " ") >  0)
	if (strcmp("", " ") == 1)
		a = 10;

	if (strlen(""))
	if (strlen("") <  0)
	if (strlen("") <= 0)
	if (strlen("") == 0)
	if (strlen("") != 0)
	if (strlen("") >= 0)
	if (strlen("") >  0)
	if (strlen("") == 1)
		a = 10;
}



/*	API22	-------------------------------	*/
void LcfApError()	{	}
void LcfSetUIMsg()	{	}
void END_API22()	{	}
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


/*	API17	API18	-------------------------------	*/
void Fun_API17_API18_NONE(char * temp)			
{	
}
void Fun_API17_API18_QUAL(const char * temp)	
{	
}


/*	API10	-------------------------------	*/
void Fun_API13()
{
	char left[10];
	int a = 10;
	memset(left, 0x00, strlen(left));
	memset(left, 0x00, a);
	memset(left, 0x01, 10);
}

/*	API10	-------------------------------	*/
int pfmNumPrint()				{	return 10;	}
int PFM_ERR(int a, int b)	{	return 0;	}
int PFM_DBG(int a, int b)	{	return 0;	}
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



/*	API07	API08	API19	API21	-------------------------------	*/
#define PDB_ERRORNUM 100
void SET_ERR(char * a, int b)	{}
void SET_ERR_EXT(int a, int b)	{}
int API07_API08_API19_API21_ALARM()
{
	if (1)
	{
		SET_ERR(0, 20);
		SET_ERR(" ", 20);
		SET_ERR_EXT(0, PDB_ERRORNUM);
	}
	return -100;
}
int API07_API08_API19_API21_SAFE()
{
	SET_ERR_EXT(0, PDB_ERRORNUM);
	SET_ERR("ERR001", PDB_ERRORNUM);
	return 0;
}


/*	API06	-------------------------------	*/
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


/*	API04	API14	API15	-------------------------------	*/
char * func()	{	return "";	}
void ApplExmnList(int a, ...) {}
void Fun_API04_API14_API15()
{
	char * pString = func();
	ApplExmnList(3, 1, 2, 3);
	ApplExmnList(3, 1, 2);
	ApplExmnList(3, 1);
	ApplExmnList(3, pString);
}

/*	API01	API02	API03	API09	API11	API12	API26	-------------------------------	*/
#define N_COUNTER "10"
void Fun_API01_API02_API03_API09_API11_API12_API26()
{
	char left[100];
	char * temp = "ABCEDFG";
	memcpy(left, N_COUNTER, strlen(left));
	memcpy(left, "20", strlen(left)); 
	memcpy(left, "ABCEDFG", strlen("ABCEDFG"));
	memcpy(left, "Z123456", 8);
	memcpy(left, temp, strlen(left));
}
void DU_API01_API02_API03_API09_API11_API12_API26()
{
	char left[100];
	char * temp = "ABCEDFG";
	memcpy(left, N_COUNTER, strlen(left));
	memcpy(left,"20", strlen(left));
	memcpy(left, "ABCEDFG", strlen("ABCEDFG"));
	memcpy(left, "Z123456", 8);
	memcpy(left, temp, strlen(left));
}


/*	FBD18	-------------------------------	*/
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

/*	FBD17	-------------------------------	*/
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


/*	FBD16	-------------------------------	*/
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

/*	FBD13	-------------------------------	*/
int sleep()	{	return 0;	}
int alarm()	{	return 0;	}
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

/*	FBD12	-------------------------------	*/
int tmpnam()	{	return 0;	}
int mktemp()	{	return 0;	}
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

/*	FBD11	-------------------------------	*/
int tpcancel()	{	return 0;	}
int tprecv()	{	return 0;	}
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

/*	FBD10	-------------------------------	*/
int signal()		{	return 0;	}
int sigaction()	{	return 0;	}
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

/*	FBD09	-------------------------------	*/
int getrlimit()	{	return 0;	}
int setrlimit()	{	return 0;	}
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

/*	FBD08	-------------------------------	*/
int fork()		{	return 0;	}
int vfork()	{	return 0;	}
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

/*	FBD07	-------------------------------	*/
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

/*	FBD06	-------------------------------	*/
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

/*	FBD04	FBD05	-------------------------------	*/
#define LOG_PATH	".."
#define DB_PATH		"..."
void getenv(char * a)	{	}
void waitFor()	{	}
void FB0D04_FBOD05()
{
	getenv("LOG_PATH");
	getenv("DB_PATH");
	waitFor();
}
void FB0D04_FBOD05_ALARM()
{
	getenv(LOG_PATH);
	getenv(DB_PATH);
}

/*	FBD03	-------------------------------	*/
typedef int FBFR;
void LOG_PC()	{	}
void LOG_WRITE()	{	}
void FBD03(FBFR * temp)
{
	//LOG_PC();
	//LOG_WRITE();
}
void FBD03_ALARAM_1(FBFR * temp)
{
	LOG_PC();
}
void FBD03_ALARAM_2(FBFR * temp)
{
	LOG_WRITE();
}

/*	FBD02	-------------------------------	*/
void FBD02_ALARM()
{
	/*
		printf, scanf, fprintf, fscanf를 사용해야된다.
		사용하지 않아서 alarm 발생.
	*/
	//printf();
	//scanf();
	//fprintf();
	//fscanf();
}













typedef struct _struct STRUCT;
struct _struct
{
	int dddd;
	int value____value;
//	int test REPEATABLE;
};
STRUCT g_struct;

TEST_ROUTINE

int test_macro_param_sub(int a, int b)
{
	return a + b;
}
int test_macro_param()
{
	return test_macro_param_sub(ROUTINE_PARAMETER_2 10);
	return test_macro_param_sub(ROUTINE_PARAMETER);
	return 10;
}

int get_100()
{
	DEFINE_STRING(char *, 
		temp, 
		abcedfg
		)
	DEFINE_STRING_2(char *, temp_2 = "ddd")
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

			val_1 = (int)RPE00_C_E1(val_3 + 1, 10);
			val_1 = (int)(RPE00_C_E1_1(val_3 ++ + 1, 10));
			val_1 = (int)(RPE00_C_E1_1(val_3 + 1, 10));
			val_2 = (10, 20 + 30, 30 - 10);
			val_2 = (int)RPE00_C_E2((val_1 + get_100()) * val_3);
		}
	}

	//* ++ p_val;
}

int TEST_PRE00_B(int p1)
{
	PROCESS_TEST(p1)
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
	//ret = (int)(RPE00_C_E1(a, 10) + RPE00_C_E1(b, 10.07));
	return ret;
}

/*
int test2(char data[100])
{
	int * temp = (int *)malloc(sizeof(int) * 10);
	memset(temp, 0x00, sizeof(int) * 10);
	temp[0] = temp[9] = 0xffff;
	int * temp_2 = (int *)malloc(sizeof(int) * 5);
	memset(temp_2, 0x00, sizeof(int) * 5);
	temp = (int *)realloc(temp, sizeof(int) * 20);
	temp[19] = 0x20;


	wchar_t wide_str1[] = L"0123456789";
	int length = wcslen(wide_str1);
	int length2 = wcslen(wide_str1) * sizeof(wchar_t);
	wchar_t *wide_str2 = (wchar_t *)malloc(wcslen(wide_str1) + 1);
	if (wide_str2 == NULL) {
		/* Handle Error * /
	}
	/* ... * /
	free(wide_str2);
	wide_str2 = NULL;

	return sizeof(data);
}
*/

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








int vodmain(int argc, char * argv[])
{
	int c = sum(10, 20);
	int d = substract(c, 10);

	double e = divide(100, 3);
	long f = multiply(10, 20);

	return c;
}




/*




extern int a;												->	etk_var_start

int a = 0;													->	etk_var_start

struct _a		
{
	int a;													->	etk_var_start
};

typedef int (*fn_type)(void);

int multi(int a, int b);	-> etk_secondary_start

int sub(int b, int c)
{
	return b - c;
}

int add			->	etk_scope_function_start >  etk_routine_start
											 >  etk_type_return_start                       
	(	
		int dd								>	etk_var_func_param_start > etk_var_start 								
	)		
{				> stmk_block
	statements[0]
	int a;													->	etk_var_start
	
	int a1				 -> etk_stmt_decl_start	> etk_var_start
		= 20,			->	etk_expr_init_start	> etk_expr_call_routine_start
		a2 
		= 10;			->	etk_expr_init_start	> etk_expr_call_routine_start

	a1 = 20;
	a1 = add(10, 20);


	int a1, a2;
	hkk
		jlk
	a1 = 20;
	a2 = 20;

	statements[1]
	fn_type test_call	 -> etk_stmt_decl_start	> etk_var_start
					= 
	statements[2]
				add;	 ->	etk_expr_init_start	> etk_expr_call_routine_start

	statements[3]
	a = add(a);		->	etk_op_func_call_start > etk_expr_routine_start
	for (int b = 0;											->	etk_var_start
		b < 10;												->	etk_expr_var_start	> 
		b ++)												->	etk_expr_var_start	> 
		;

	multi(			->  etk_expr_call_routine_start	> etk_expr_routine_start > 
		sub(),		->	etk_expr_call_routine_start	> etk_expr_routine_start > 
		30
	);	
}

etk_expr_routine_start				pExpression->kind == enk_routine 
etk_expr_call_routine_start

etk_const_routine_addr_start		함수 포인터 

etk_routine_start
etk_expr_routine_scope_start

*/
