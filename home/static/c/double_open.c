#include <stdio.h>
extern int k;

void autoever03_04_bad (void)
{
  int i = 0;
  void * pFile;
  for(i = 0; i < k; i++){
    pFile = fopen ("myfile.txt","w"); 
    if(k == 10){
      continue;
    }
    fclose(pFile);
  }
}

void autoever03_04_bad_simple (void)
{
  int i = 0;
  int x = 1;
  int y = 0;
  void * pFile;
  int k = 10;
  for(i = 0; i < k; i++){
    y = y / x;
    pFile = fopen ("myfile.txt","w"); 
    x = 1;
  }
}
  
void foo(char *s){
  char *result = strdup(s);
  void *f;
  if (result != 0)
    f = fopen(result, "r");
  free(result);
  fclose(f);
  return;
}

void double_open_bad(char *s, int x){
  void *f1, *f2;
  if (x > 0)
    f1 = fopen(s, "r");
  if (x > 10)
    f2 = fopen(s, "r"); //@violation DOUBLE_OPEN
  fclose(f1);
  fclose(f2); 
  return;
}

void gzip(){
  char *file_name;
  int fd;
  file_name = (char *) malloc(10);

  if(file_name != 0){
    fd = open (file_name, 1);

  }

  free(file_name);
  close(fd);
}
