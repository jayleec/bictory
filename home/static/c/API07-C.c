void api07_bad1(){
  char *source = "12345";
  char a[5];
  /* ... */
  if (source) {
    char* b = strncpy(a, source, 5); //@violation IMPROPER_NULL_TERMINATION
  }
  else {
    /* Handle null string condition */
  }

  free(source);
}
