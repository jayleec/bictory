//@checker ENSURE_MEMBER_TYPE_OF_STRUCT
#include "EnsureMemberTypeOfStructTest.hpp"
/* 시스템 헤더에서 알람이 나지만, 이를 예외 처리하는건 NEST의 옵션으로 예외처리함. */
#include <iostream> 

/* 문제 없음. */
struct Struct1
{
	long x;
	long y;
	long arr[100]; /* 포인터형으로 볼 수 있으나, 정적 배열은 무시하도록 함 */
};

/* int 형을 사용함 */
typedef struct _struct2 //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
{ 
	int x; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
	unsigned int y; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
} Struct2;

/* 포인터 형을 사용함 */
struct Struct3 //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
{ 
	char* ch; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
};

/* Nested struct 검사 */
struct Struct4
{
	struct Nested //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
	{ 
		int field; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
		char field2;
	};
	Nested n;
};

/* typedef 된 int형 사용 */
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
