#include <stdio.h>
#include <stdlib.h>
 
int fio17_bad1 (unsigned int size) {
 
    void *fp;
    long length;
    char *buffer;
 
    fp = fopen("file.txt", "rb");
 
    if (fp == 0) {
      /* Handle file open error */
      exit(0);
    }
 
    /* Obtain file size */
    if (fseek(fp, 0, SEEK_END) != 0) {
      /* Handle repositioning error */
    }
 
    length = ftell(fp);
 
    if (fseek(fp, 0L, SEEK_SET) != 0) {
      /* Handle repositioning error */
    }
 
    /* Allocate memory to contain whole file */
    buffer = (char*) malloc(length); //@violation UNREASONABLE_PARAMETER
    if (buffer == 0) {
      /* Handle memory allocation error */
      exit(0);
    }
     
    /* size assigned here in some other code */
 
    if (fread(buffer, 1, size, fp) < size) { //@violation IMPROPER_NULL_TERMINATION 
      /* Handle file read error */
    }
    fclose(fp);
    free(buffer);
 
    return 0;
}


int fio17_good (unsigned int size) {
 
    void *fp;
    long length;
    char *buffer;
 
    fp = fopen("file.txt", "rb");
 
    if (fp == 0) {
      /* Handle file open error */
      exit(0);
    }
 
    /* Obtain file size */
    if (fseek(fp, 0, SEEK_END) != 0) {
      /* Handle repositioning error */
    }
    length = 100;
    if (fseek(fp, 0L, SEEK_SET) != 0) {
      /* Handle repositioning error */
    }
 
    /* Allocate memory to contain whole file */
    buffer = (char*) malloc(length); 
    if (buffer == 0) {
      /* Handle memory allocation error */
      exit(0);
    }
 
    /* ... Assign size here ... */
    if (size < length) { // 이걸 가지고 허위 경보를 없애야 하는데....
      /* Handle case when size isn't the length of file */
      exit(0);
    }
    /* ... Other code ... */
 
    if (fread(buffer, 1, size, fp) < size) {  //@violation(NOT_EXPECTED) IMPROPER_NULL_TERMINATION
      /* Handle file read error */
    }
 
    fclose(fp);
    free(buffer);
    return 0;
}
