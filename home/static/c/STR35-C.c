/* STR35-C. Do not copy data from an unbounded source to a
   fixed-length array */

enum { CHARS_TO_READ = 9 };

void str35_bad1(){ 
  int x; char c; float f; 
  char *safe; 
  char *problem = malloc(100);
  char buf[CHARS_TO_READ + 1];
  char *s = "%7d%20s %c %lf";
  scanf(s, &x, buf, &c, &f); //@violation OVERRUN.STATIC.MEMSET
  scanf("%9d%s", &x, buf); //@violation UNBOUNDED_SOURCE_TO_ARRAY
  scanf("%11d%s", &x, safe);
  scanf("%13d%s", &x, problem); //@violation UNBOUNDED_SOURCE_TO_ARRAY
  free(problem);
}


int str35_main(int argc, char *argv[]) {
  char cmdline [4096];
  cmdline[0] = '\0';
  fgets(argv, "file.c");
  
  for (int i = 1; i < argc; ++i) {
    opus1_print(argv[i]);
    strcat(cmdline, argv[i]); //@violation DO_NOT_ASSUME_ENV
    strcat(cmdline, " ");
  }
  
  /* ... */
  
  return 0;
}
