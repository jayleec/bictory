const char *p;
void dont_do_this(void) {
  const char c_str[] = "This will change";
  p = c_str; /* Dangerous */ //@violation 
  /* ... */
}
 
void innocuous(void) {
  const char c_str[] = "Surprise, surprise";
}
 
void this_is_OK(void) {
  const char c_str[] = "Everything OK";
  const char *p = c_str;
  /* ... */
}

char *init_array(void) {
  char array[10];
  /* Initialize array */
  return array; //@violation RETURN_LOCAL
}

void squirrel_away(char **ptr_param) {
  char local[10];
  /* Initialize array */
  *ptr_param = local; //@violation PARAMETER_POINTER_TO_LOCAL
}
 
void rodent() {
  char *ptr;
  squirrel_away(&ptr);
  /* ptr is live but invalid here. */
}

int main(void) {
  dont_do_this();
  innocuous();  /* p might be pointing to "Surprise, surprise". */
  
  this_is_OK();
  init_array(); 
  rodent();
  return 0;
}
