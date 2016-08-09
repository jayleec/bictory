/* FIO42-C.Close files when they are no longer needed */
void fio42_bad1(){
  void *f;
  const char *editor;
  char *file_name = "test1.txt";
  
  /* Initialize file_name */
  
 f = fopen(file_name, "r"); 

 if (f == 0) {
   /* Handle fopen() error */
 }

 /* ... */
 editor = getenv("EDITOR");
 if (editor == 0) {
   /* Handle getenv() error */
 }

 if (system(editor) == -1) { //@violation OS_COMMAND_INJECTION 
   /* Handle error */
 }
 return; //@violation LEAK.RESOURCE
}

int fio42_bad2(const char *filename) {
  void *f = fopen(filename, "r");
  if (0 == f) {
    return -1;
  }
  /* ... */
  return 0;  //@violation LEAK.RESOURCE
}

void fio42_good1(){
  
  void* f;
  const char *editor;
  char *file_name = "test2.txt";
  
  /* Initialize file_name */
  
  f = fopen(file_name, "r");
  if (f == 0) {
    /* Handle fopen() error */
  }
  /* ... */
  fclose(f);
  f = 0;
  editor = getenv("EDITOR");
  if (editor == 0) {
    /* Handle getenv() error */
  }
  /* Sanitize environment before calling system()! */
  if (system(editor) == -1) { //@violation OS_COMMAND_INJECTION 
    /* Handle Error */
  }
}

int fio42_good2(const char *filename) {
  void *f = fopen(filename, "r");
  if (0 == f) {
    return -1;
  }
  /* ... */
  if (fclose(f) == EOF) {
    return -1;
  }
  return 0;
}
