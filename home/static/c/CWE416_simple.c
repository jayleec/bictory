void goodB2Gv(void)
{
  char * data;
  data = ((char *)(_Z6mallocm(100UL)));
  if(data == 0) return;
  data[99] = ((char)0);
  
  _Z4freePv(((void *)data));
  *data = '0';
  return;
}
