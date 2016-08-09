//@checker ENSURE_MEMBER_TYPE_OF_STRUCT
#include "EnsureMemberTypeOfStructTest.hpp"
/* �ý��� ������� �˶��� ������, �̸� ���� ó���ϴ°� NEST�� �ɼ����� ����ó����. */
#include <iostream> 

/* ���� ����. */
struct Struct1
{
	long x;
	long y;
	long arr[100]; /* ������������ �� �� ������, ���� �迭�� �����ϵ��� �� */
};

/* int ���� ����� */
typedef struct _struct2 //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
{ 
	int x; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
	unsigned int y; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
} Struct2;

/* ������ ���� ����� */
struct Struct3 //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
{ 
	char* ch; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
};

/* Nested struct �˻� */
struct Struct4
{
	struct Nested //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
	{ 
		int field; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
		char field2;
	};
	Nested n;
};

/* typedef �� int�� ��� */
typedef int INTEGER;

struct Struct5 //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
{ 
	char ch;
	INTEGER data; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
};


int main()
{
	return 0;
}
