//@checker AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH

/* 유사 PFM_TRY문을 작성 */
#define PFM_TRY(X) if((X)==false) goto PFM_CATCH

bool errorCall(int value)
{
	if(value<=0)
	{
		return false;
	}

	return true;
}

/* 문제 없음. */
void function1()
{
	int x = 10;
	
	PFM_TRY(errorCall(10));
	if(x==10)
	{
PFM_CATCH:
		return;
	}
}

/* catch 라벨이 위에 있음 */
void function2()
{
	int x = 10;
	if(x==10)
	{		
PFM_CATCH: //@b-violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
		x = -5;
		PFM_TRY(errorCall(x)); //@violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
	}
}

/* catch 라벨이 위에 있으며, 한 함수내에 PFM_TRY가 여러개임 */
void function3()
{	
	int x = 10;
	
	PFM_TRY(errorCall(10));
	
	if(x==10)
	{		
PFM_CATCH: //@b-violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
		x = -5;
		PFM_TRY(errorCall(x)); //@violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
	}
}

/* 반복분 내에 PFM_TRY와 catch 라벨이 같이 있음*/
void function4()
{
	int x = 0;
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		/* 반복문 내에 */
		PFM_TRY(errorCall(5-i)); //@violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
		if(i<5)
		{
PFM_CATCH:
			x++;
		}
	}
}

/* 반복문을 포함하여 다수의 PFM_TRY가 함수내에 있음. */
void function5()
{
	int x = 0, y = 0;
	while(x != 10)
	{
		if(y==0)
		{
			PFM_TRY(errorCall(5-x)); //@violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
		}
		else
		{
			PFM_TRY(errorCall(3-x)); //@violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
		}
		x++;
PFM_CATCH: //@b-violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
		y++;
	}

	PFM_TRY(errorCall(0)); //@violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
}

/* 서로 다른 반복문에 있음. 문제 없음. */
void function6()
{
	int x = 0, y = 0;
	int i = 0;
	while(x != 10)
	{
		x++;
		PFM_TRY(errorCall(5-x));
	}
	
	for(i = 0; i < 10; i++)
	{
PFM_CATCH:
		y++;
	}
}

/* 한쪽이 중첩된 반복문 내에 있음. */
void function7()
{
	int x = 0; 
	int y = 0;
	int j = 0;
	for(int i = 0; i < 10; i++)
	{
		for(j = 0; j < i; j++)
		{
PFM_CATCH: //@b-violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
			y++;
		}
		PFM_TRY(errorCall(5-x)); //@violation AVOID_INFINITE_LOOP_WHEN_USE_PFM_TRY_CATCH
	}
}

int main()
{
	function1();
	function2();
	function3();
	function4();
	function5();
	function6();
	function7();
	return 0;
}

