#include <stdio.h>
#include <stdlib.h>

void fio18_bad1(void *filedes, int size2){ 
  /* Assume size1 and size2 are appropriately initialized */
  char buffer[100];
  int size1 = 100;
  filedes = fopen("out.txt", "w+");
  if (filedes == 0) {
    /* Handle error */
    return;
  }

  if (buffer == 0) {
    /* Handle error */
    fclose(filedes);
    return;
  }

  size2 = size1; 

  fwrite(buffer, 1, size2, filedes); //@violation IMPROPER_NULL_TERMINATION
  
  buffer = 0;
  fclose(filedes);
}

void fio18_good1(void *filedes, int size2){ 
  /* Assume size1 and size2 are appropriately initialized */
  char *buffer;
  int size1 = 100;
  filedes = fopen("out.txt", "w+");
  if (filedes == 0) {
    /* Handle error */
    return;
  }
  
  buffer = (char *)calloc( 1, size1);
  if (buffer == 0) {
    /* Handle error */
    fclose(filedes);
    return;
  }
  
  size2 = strlen(buffer) + 1;

  fwrite(buffer, 1, size2, filedes);
  
  free(buffer);
  buffer = 0;
  fclose(filedes);
}
