#ifndef _MAIN_H_
#define _MAIN_H_


#define ROUTINE_PARAMETER 10,20
#define ROUTINE_PARAMETER_2 10,

//#define repeatable 100
//#define REPEATABLE [repeatable]

#define TEST_ROUTINE	\
	char ** g_p_p_value = 0;	\
	char ** g_p_p_value2;	\
	int g_var_in_macro	= 0;	\
	int routine_in_macro(int p1, int p2) \
	{	\
		int a = 0;	\
		int b = 10;	\
		int c = 0;	\
		for (a = 10, b = 20; a < 100; a ++, b++)	\
		{	\
			c ++;	\
		}	\
		while (a != 20)	\
			a ++;	\
		return c + b;	\
	}

#define RPE00_C_E1(X, Y) ((X)*(X)*(X) + (Y) + (unsigned long)(int)(&g_struct)->value____value + g_struct.value____value)
#define RPE00_C_E1_1(X, Y)	X * X * X + (unsigned long)(int)Y
#define RPE00_C_E2(X) (++val_1, ++val_2, 2*X)
#define PROCESS_TEST(X)	\
	enum _test {	\
		tt_0,	/*	test	*/	\
		tt_1 = tt_0,	\
		tt_2	} test;	\
	unsigned int	aaa = 100;	\
	int bbb = 200;	\
	int ccc = 300;	\
	char * temp = "abcedf\\g ABCEDFG \n";	\
	char ** ppoint = 0;	\
	test = tt_0;	\
	**ppoint = 0;	\
	if (0 < X && X < 10)	\
	{	\
		ccc = (int)RPE00_C_E1 ((aaa + 100) * bbb, 30 + get_100() + X);	\
		ccc = 10;	\
	}	\
	else if (X > 20)	\
	{	\
		switch (bbb)	\
		{	\
		case 10:	\
			ccc = 10;	\
			{	\
				int b = 3;	\
				ccc += b;	\
			}	\
			break;	\
		case 20:	\
			ccc = 20;	
	//		return 30;	\
	//		break;	\
	//	case 30:	\
	//		goto TEST;\
	//		break;	\
	//	}	\
	//	TEST:	\
	//	ccc ++;	\
	//}	\
	//return ccc;
#define DEFINE_STRING(type, name, init) type var_##name = #init;
#define DEFINE_STRING_2(type, ni) type var_##ni;



/*	CERT_SCS_ARR31_C	-------------------------------	*/
extern int CERT_SCS_ARR31_C_int_arr_2[];
extern int CERT_SCS_ARR31_C_int;
extern int * CERT_SCS_ARR31_C_int_pointer;
extern int CERT_SCS_ARR31_C_int_arr[];
//extern int * CERT_SCS_ARR31_C_int_dupl;

#endif	//	_MAIN_H_
