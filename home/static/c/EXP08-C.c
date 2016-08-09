#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct big {
  unsigned long long ull_1; /* Typically 8 bytes */
  unsigned long long ull_2; /* Typically 8 bytes */
  unsigned long long ull_3; /* Typically 8 bytes */
  int si_4; /* Typically 4 bytes */
  int si_5; /* Typically 4 bytes */
};

void EXP08_1(){
  int buf[100];
  int *buf_ptr = buf;
  
  while (buf_ptr < (buf + sizeof(buf))) {
    *buf_ptr++ = 10;
  }
}

void EXP08_1_good(){
  int buf[100];
  int *buf_ptr = buf;
  
  while (buf_ptr < (buf + 100)) {
    *buf_ptr++ = 10;
  }
}

/* ... */
 
int EXP08_2(void) {
  unsigned int skip = 8; //offsetof(struct big, ull_2);
  struct big *s = (struct big *)malloc(sizeof(struct big));
  if (!s) {
    return -1; /* Indicate malloc() failure */
  }
  
  memset(s + skip, 0, sizeof(struct big) - skip);
  /* ... */
  free(s);
  s = NULL;
  
  return 0;
}

int EXP08_2_good(void) {
  unsigned int skip = 8;  //offsetof(struct big, ull_2);
  struct big *s = (struct big *)malloc(sizeof(struct big));
  if (!s) {
    return -1; /* Indicate malloc() failure */
  }
  
  memset((char *)s + skip, 0, sizeof(struct big) - skip);
  /* ... */
  free(s);
  s = NULL;
  
  return 0;
}

void EXP08_3_bad(){
  int *p = malloc(100);
  
  p++;
  
  free(p);
  return; //@violation LEAK.MEMORY 
}

