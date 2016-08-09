void foo(void) 
{
  int div = 0;
  int mod = 0;
  unsigned int a = 20;
  unsigned int b = 40;
  
  div = (b+1) / (a+1);      
  mod = b % a; 				/* Violation */
  mod = (b+1) % (a+1);      /* OK. */
}
