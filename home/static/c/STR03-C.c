/* STR03-C. Do not inadvertently truncate a null-terminated byte
   string */

void str03_bad1(){
  char *string_data = "abcdefg";
  char a[6];
  /* ... */
  strncpy(a, string_data, sizeof(a)); //@violation IMPROPER_NULL_TERMINATION
}

