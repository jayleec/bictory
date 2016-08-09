void integer_overflow_bad1(){
  int x[100] ;
  void *f = fopen("a.txt","r");
  int n = 0;
  fgets(x,10,f); // src
  n = *x + 100;  //@violation INTEGER_OVERFLOW
  fclose(f);
}

int nclsocket(int _socket,void *_buffer,unsigned int _recvLen, char _isStream)
{
  char *p = (char *)_buffer ; // Pointer to the buffer
  int nNumReq = (int)_recvLen; // Number of bytes requested
  int nReadBytes = 0;          // Reset the byte counter
  int nNumRead = 0;            // Actual number of bytes read
  while(nReadBytes < (int)_recvLen ) // Loop until the buffer is full
    {
      nNumRead = recv(_socket,p,nNumReq-nReadBytes,0);
      if ( nNumRead == 0 )
        {
          break ;
        }
      if(nNumRead > 0)
        {
          nReadBytes += nNumRead; // Increment the byte counter
          p += nNumRead;          // Move the pointer for the next read
          
          if ( nReadBytes == _recvLen )
            {
              break ;
            }
          if ( _isStream == NL_TRUE &&  *(_buffer+nReadBytes-1) == '\n' )
            {
              break ;
            }
        }
      if(nNumRead < 0){
        return nReadBytes ;
      }
    }
  return 0;
}

void casting_problem() {
auto short __45_9_y = ((short)32760);
auto long __46_8_z = 32760L;
auto int *__47_8_x; __47_8_x = ((int *)(malloc(100)));
 __46_8_z = (((long)__45_9_y) + 999999999L); 
__46_8_z = (((long)__46_8_z) + 999999999L); 
free(__47_8_x);
return;
}

int input_overflow(int n){
  char *c = getenv("HOME");
  int divisor = atoi(c);
  return n/divisor; //@violation DIV_BY_ZERO.MISSING_CHECK
}

void divide_long(int n){
  signed long long_min = -2147483648;
  signed long result;

  result = long_min / -1; //@violation INTEGER_OVERFLOW
  
}

void mod_long(int n){
  signed long long_min = -2147483648;
  signed long result;

  result = long_min % -1; //@violation NEGATIVE_MOD_OPERATION
  
}

void unary_long(int n){
  long long_min = -2147483648;
  long result;

  result = -1 * long_min; //@violation INTEGER_OVERFLOW
}

