/* void path_test1(unsigned int x){ */
/*   int y; */
/*   int a[10]; */
/*   if (x >= 0) { */
/*     a[x] = 10; */
/*   } else { */
/*     a[100] = 10; */
/*   } */
/* } */

/* void path_test2(char *str){ */
/*   char *id = 0; */
/*   unsigned int id_size = 0; */
/*   int len; */
/*   len = strlen(str) + 1; */
    
/*   if (len > id_size){ */
/*     id = (char *) malloc(len); */
/*     if (id == 0) return; */
/*     id_size = len; */
/*   } */

/*   *id = 'c'; //@violation(NOT_EXPECTED) NULL_DEREF */

/*   if (id != 0) free(id); */
/* } */

void path_test3(int x, int y){
  int result = 10;
  if (x > 100){
    if (y < 20){
      opus1_print(y + x);
      if (y < x){
        result = result / 0; //@violation DIV_BY_ZERO
      } else {
        result = result / 0; //@violation(NOT_EXPECTED) DIV_BY_ZERO
      } 
    }
  }
}
  
