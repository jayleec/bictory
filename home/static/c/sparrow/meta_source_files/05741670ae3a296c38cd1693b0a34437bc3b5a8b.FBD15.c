void badFoo(void) 
{
  int badA[5];
  int i = 3;
  badA[2] = 10;               /* Violation : shall not use the subscript operator [] */
  badA[i] = 10;               /* Violation : shall not use the subscript operator [] */
}

void goodFoo(void) 
{
  int goodA[5]={0,1,2,3,4}; 
  *goodA = 10;            /* OK. */
}  
