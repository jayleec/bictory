/* FIO31-C. Do not open a file that is already open */

/* Opening a file that is already open has implementation-defined
   behavior, according to the C Standard, subclause 7.21.3, paragraph
   8 [ISO/IEC 9899:2011]: */
/* Functions that open additional (nontemporary) ﬁles require a file
   name, which is a string. The rules for composing valid ﬁle names
   are implementation-deﬁned. Whether the same file can be
   simultaneously open multiple times is also
   implementation-deﬁned. */
/* Some platforms may forbid a file simultaneously being opened
   multiple times, but platforms that allow it may facilitate
   dangerous race conditions. This is because it is possible for an
   open file to be moved or deleted on many platforms. If a program
   re-opens a file using the same pathname, there is no guarantee that
   the same file is being accessed. */

#include <stdio.h>

void simple_double_open1(){
  void *file = fopen("sparrow","a");
  void *file2= fopen("sparrow","a"); //@violation DOUBLE_OPEN
  fclose(file);
  fclose(file2);
  return;
}

void do_stuff(void) {
  void *logfile = fopen("log", "a");
  if (logfile == 0) {
    /* Handle error */
  }
 
  /* Write logs pertaining to do_stuff() */
  fprintf(logfile, "do_stuff\n");
  
  fclose(logfile);
  return;
}
 
int main(void) {
  void *logfile = fopen("log", "a");
  if (logfile == 0) {
    /* Handle error */
  }
 
  /* Write logs pertaining to main() */
  fprintf(logfile, "main\n");
 
  do_stuff();
 
  fclose(logfile);
  return 0;
}



void do_stuff2(void *logfile) {
  /* Write logs pertaining to do_stuff() */
  fprintf(logfile, "do_stuff\n");
}
 
int main2(void) {
  void *logfile = fopen("log", "a");
  if (logfile == 0){
    /* Handle error */
  }
 
  /* Write logs pertaining to main() */
  fprintf(logfile, "main\n");
 
  do_stuff2(logfile);
 
  fclose(logfile);
  return 0;
}

