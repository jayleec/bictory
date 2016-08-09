struct sss_1 {
  char a;             /* Violation : shall not be padding. */
  int  i[1];		  
  short s;            /* Violation : shall not be padding. */
};

struct sss_2 {
  int  i[1];
  char a[2];
  short s;
};