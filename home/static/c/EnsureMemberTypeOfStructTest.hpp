#ifndef _5_HPP_
#define _5_HPP_

/* int 형을 사용함, 헤더파일에서도 알람이 나게 함. */
typedef struct _struct0 //@violation ENSURE_MEMBER_TYPE_OF_STRUCT
{ 
	int x; //@b-violation ENSURE_MEMBER_TYPE_OF_STRUCT
} Struct0;

#endif // _5_HPP_