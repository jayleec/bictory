#include<stdio.h>
#include<stdlib.h>
 
typedef unsigned int u32;
typedef short u8;
 
u32 array[15];
 
u8 test1(u32 num)
{
  if(0u==(num & 0x8000))
    {
      if(24000u < (num*100000)/32767)
        {
          return 14;
        }
      else
        {
          return 16;
        }
    }
}   //@violation MISSING_RETURN


void test2(u32 num)
{
  u8 index=test1(num);
  array[index]=1; //@violation OVERRUN.STATIC
}

int foo(int x){
  if (x > 10)
    return 1;
} //@violation MISSING_RETURN


int bar(int x){
  if (x > 10)
    return 1;
  else return 2;
}

