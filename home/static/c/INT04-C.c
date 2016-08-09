#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define size_t unsigned int 

enum { MAX_TABLE_LENGTH = 256 };
const char *table[] = { "black", "white", "blue", "green" };


char** create_table(void) {
  const char* const lenstr = (char *)getenv("TABLE_SIZE");
  const unsigned int length = lenstr ? strtoul(lenstr, 0, 10) : 1;
  
  if (length > 256 / sizeof(char *))
    return 0;   /* indicate error to caller */
  
  const unsigned table_size = length * sizeof(char *); //@violation INTEGER_OVERFLOW
  char** const table = (char **)malloc(table_size);//@violation UNREASONABLE_PARAMETER
  
  if (table == 0)
    return 0;   /* indicate error to caller */
  
  /* initialize table... */
  return table;
}
 
char** create_table_safe(void) {
  const char* const lenstr = getenv("TABLE_SIZE");
  const unsigned int length = lenstr ? strtoul(lenstr, 0, 10) : 0;
 
  if (length <= 0 || length > 256)
    return 0;   /* indicate error to caller */
 
  const unsigned int table_size = length;
  char** const table = (char **)malloc(table_size); //@violation(NOT_EXPECTED) UNREASONABLE_PARAMETER
 
  if (table == 0)
    return 0;   /* indicate error to caller */
 
  /* initialize table... */
  return table;
}

void integer_overflow(){
  float f;
  int random[1000];
  f = (float) rand()/2000;
  random[50] = (int) (f * 1000); //@violation(NOT_EXPECTED) INTEGER_OVERFLOW
}

  
/* const char *set_background_color(void) { */
/*   int color_index; */
/*   GET_TAINTED_INTEGER(int, color_index); */
  
/*   const char *color = table[color_index];  /\* violation *\/ */
  
/*   /\* ... *\/ */
/*   return color; */
/* } */

int main(){
  
  return 1;
}
