void uncontrolled_format_string_bad(){
  char *data;
  char dataBuffer[100] = "";
  unsigned int dataLen = strlen(data);
  char *environment = getenv("HOME");
  data = dataBuffer;
  
  if (environment != 0) {
    strncat(data+dataLen, environment, 100 - dataLen - 1);
  }

  printf(data); //@violation INFORMATION_LEAK
}
 
