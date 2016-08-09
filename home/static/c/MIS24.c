void foo(void) 
{
  int sum = 0;
  int dividor = 20;
  int dim     = 40;
  unsigned int dim2 = 60;
  
  sum = dim / dividor;     /* Violation : shall be unsigned integer type */
  sum = dim2 / dividor;    /* Violation : shall be unsigned integer type */
}