//@checker UNREACHABLE_CODE_STRING_COMPARE

#include <string.h>

struct Field
{
	char* x;
	char arr[10];
	typedef struct _Nested
	{
		char* x;
		char arr[10];
	} Nested;
	Nested n;
};

void compare(char* str, Field fStr, bool flag, int k)
{
	int x = 0;



	/* Case 1 : ���� ���� �ڵ� */
	if(str[0] == 'X')
	{
		x++;
	}
	else if(str[0] == 'Y')
	{
		x++;
		/* if-elseif ��ø �˻�� �ڵ�. */
		if(flag == true)
		{
			x++;
			if(k < 20)
			{
				x++;
			}
			else if(k < 30)
			{
				x++;
			}
			else if(k < 40)
			{
				x++;
			}
			else
			{
				x++;
			}
		}
		else if(flag == false)
		{
			x++;
			if(k == 10)
			{
				x++;
			}
			else if(k == 5)
			{
				x++;
			}
		}
		else if(k < 10)
		{
			x++;
		}
	}

	if(strcmp(str, "TES") == 0)
	{
		x++;
	}
	else if(strcmp(str, "TEST") == 0) /* strcmp�̹Ƿ� ���� ���ƾ� �Ѵ�. ���� ���� ����. */
	{
		x++;
	}

	if(fStr.n.arr[2] == 'X')
	{
		x++;
	}
	else if(fStr.n.arr[2] == 'Y')
	{
		x++;
	}
	else if(fStr.n.arr[2] == 'Z')
	{
		x++;
	}

	if(strcmp(fStr.n.arr, "TES") == 0)
	{
		x++;
	}
	else if(strcmp(fStr.n.arr, "TEST") == 0)
	{
		x++;
	}
	else if(strncmp(fStr.n.arr, "TEST2", 5) == 0)
	{
		x++;
	}




	/* Case 2. if-elseif ü�ο� Unreachable Code�� ����. */
	if(str[0] == 'X') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(str, "XTEST") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(str, "XT", 2) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	if(strcmp(fStr.x, "TEST") == 0)
	{
		x++;
	}
	else if(strncmp(fStr.x, "TT", 2) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(fStr.x, "TTT") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	if(str[0] == 'X') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(str, "X", 1) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}




	/* Case 3. Offset�� ����. */
	if(strncmp(str + 2, "TES", 3) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(str + 2, "TEST") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	/* 2��° ���ڰ� X�� ��� ������ ���� ����Ǹ�, else-if������ ù��° �ܾ���� �񱳽� ���� ���ԵǹǷ�
	 * Unreachable code�̴�.
	 */
	if(fStr.n.arr[1] == 'X') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(fStr.n.arr, "TX", 2) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(fStr.n.arr, "KXT") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	/* ������ offset ������ �Ͽ� ��Ȯ�� �м��� �ϴ��� �׽�Ʈ. */
	if(strncmp(fStr.n.arr + 2, "CD", 2) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* �ι�° ���ں��� �����ϴ� CD�� ����, �Ʒ����� BCDT�� Unreachable Code�̴�. */
	else if(strncmp(fStr.n.arr + 1, "BCDT", 3) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* �ι�° ���ں��� �����ϴ� CD�� ����, �Ʒ����� ATCDX�� Unreachable Code�̴�. */
	else if(strncmp(fStr.n.arr, "ATCDX", 5) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	/* Case 4. ��ø if���� ����. */
	if(fStr.n.arr[0] == 'A') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		if(strcmp(fStr.n.arr + 1, "BCD") == 0)
		{
			x++;
		}
		else if(fStr.n.arr[0] == 'B') //@violation UNREACHABLE_CODE_STRING_COMPARE
		{
			x++;
		}
	}

	/* offset + 2���� C�� D�� ���� ��ĥ �� ����. */
	if(strncmp(str, "ABC", 3) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		if(strncmp(str + 1, "BD", 2) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
		{
			x++;
		}
	}
	
	/* Case 5. ���� ������. �̶� �ٸ� ���ǵ鿡 ���� Unreachable Code�� �ƴϴ��� 
	 * ���������� Unreachable Code�� �ɼ� �ִ� ���輺�� �ִٰ� �Ǵ��ϰ� �˶��� ������ ��.
	 */
	if(flag == false && strncmp(str, "ABC", 3) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(flag == false && strcmp(str, "ABCDE") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	/* Case 6. �������� �� */
	if(strcmp(str, "123") != 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* �ݵ�� 123 */
	else if(strcmp(str, "123") != 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	if(strncmp(str, "ABC", 3 ) != 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		/* ���� ����. ����° ���ڰ� �ٸ��Ƿ�. */
		if(strncmp(str, "ABD", 3) == 0)
		{
			x++;
		} /* �����. */
		else if(strncmp(str, "ABC", 3) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
		{
			x++;
		}
	}
	else if(strncmp(str, "ABCD", 4) != 0) /* Unreachable Code? or not? */
	{
		x++;
	}

	/* Case 7. ���� if-elseif ü������ ���� �ٸ� ���ڿ� �� ���ĵ��� ȥ��� ��� �� */
	if(str[1] == 'B') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(fStr.arr + 2, "XX", 2) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* str[1] == 'B' ���� ���� �˶�. */
	else if(strcmp(str, "XBT") == 0) //@violaion UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* strncmp(fStr.arr + 2, "XX") == 0 ���� ���� �˶�. */
	else if(strncmp(fStr.arr, "ABXXTT", 5) == 0) //@vioaltion UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	
	if(str[0] == 'A') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* �� ������ �ΰ� ������, ���� str �� �˻翡 ���� �˶�. */
	else if(strcmp(fStr.arr, "XXX") == 0 || strcmp(str, "ABC") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
}


int main()
{

	return 0;
}
