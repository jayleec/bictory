/* STR32-C. Null-terminate byte strings as required */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NTBS_SIZE 5

void str32_bad1(char *source){
  char ntbs[5] = "abcd";
  ntbs[sizeof(ntbs)-1] = '\0';

  strncpy(ntbs, source, sizeof(ntbs)); 
  printf("str32_bad1: %s\n", ntbs);
}

void str32_bad2(char *source){
  char ntbs[5];
  
  memset(ntbs, 0, sizeof(ntbs)-1);
  strncpy(ntbs, source, sizeof(ntbs)-1); 
  printf("str32_bad2: %s\n", ntbs); 
}

void str32_good1(char *source){
  char ntbs[5];
  strncpy(ntbs, source, sizeof(ntbs)-1);
  ntbs[sizeof(ntbs)-1] = '\0';
  printf("str32_good1: %s\n", ntbs);
}

void str32_good2(char *source){
  char ntbs[5];
  /* ... */
  if (source) {
    if (strlen(source) < sizeof(ntbs)) {
      strcpy(ntbs, source);
    }
    else {
      /* handle string too large condition */
    }
  } else {
    /* handle 0 string condition */
  }
  printf("str32_good2: %s\n", ntbs);
}

int str32_main(){
  char *a = "aa";
  char *b = "123456789"; 
  str32_bad1(a);
  str32_bad1(b);  //@violation IMPROPER_NULL_TERMINATION
  str32_bad2(a);
  str32_bad2(b);  //@violation IMPROPER_NULL_TERMINATION
  str32_good1(a);
  // good 함수를 부르지만 b의 크기가 크기 때문에 문제 발생
  str32_good1(b); //@violation IMPROPER_NULL_TERMINATION
  str32_good2(a);
  str32_good2(b);
  return;
}


char *cur_msg = 0;
unsigned int cur_msg_size = 1024;


void str32_good3(void) {
  char *temp;
  unsigned int temp_size;
 
  /* ... */
 
  if (cur_msg != 0) {
    temp_size = cur_msg_size/2 + 1;
    temp = realloc(cur_msg, temp_size);
    if (temp == 0) {
      /* Handle error condition */
      return;
    }
    cur_msg = temp;
    cur_msg_size = temp_size;
 
    /* Ensure string is null-terminated */
    cur_msg[cur_msg_size - 1] = '\0';
  }
}
 
/* ... */
