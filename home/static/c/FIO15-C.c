/* fopen */
void fio15(){
  char *file_name = "TEST.C";
  void *fp;
  
  /* initialize file_name */

  fp = fopen(file_name, "w");
  if (fp == 0) {
    /* Handle error */
  }

  /*... Process file ...*/
  
  if (fclose(fp) != 0) {
    /* Handle error */
  }

  if (remove(file_name) != 0) { //@violation RACE_CONDITION
    /* Handle error */
  }
}
