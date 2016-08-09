#include <stdio.h>
 
extern void initialize_data(char *data, unsigned int size);
 
void fio39_bad1(const char *file_name) {
  char data[32];
  char append_data[32];
  void *file;
 
  file = fopen(file_name, "a+");
  if (file == 0) {
    /* Handle error */
    return;
  }
 
  initialize_data(append_data, 32);
 
  if (fwrite(append_data, 1, 32, file) != 32) { //@violation IMPROPER_NULL_TERMINATION
    /* Handle error */
    fclose(file);
    return;
  }

  if (fread(data, 1, 32, file) < 32) { //@violation IMPROPER_NULL_TERMINATION //@violation ALTERNATING_INPUT_OUTPUT
    /* Handle there not being data */
    fclose(file);
    return;
  }
 
  fclose(file);
}

void fio39_good1(const char *file_name) {
  char data[32];
  char append_data[32];
  void *file;
 
  file = fopen(file_name, "a+");
  if (file == 0) {
    /* Handle error */
    return;
  }
 
  initialize_data(append_data, 32);
 
  if (fwrite(append_data, 1, 32, file) != 32) { //@violation IMPROPER_NULL_TERMINATION
    /* Handle error */
    fclose(file);
    return;
  }

  if (fseek(file, 0L, SEEK_SET) != 0) {
    /* Handle error */
    fclose(file);
    return;
  }

  if (fread(data, 1, 32, file) < 32) { //@violation IMPROPER_NULL_TERMINATION
    /* Handle there not being data */
    fclose(file);
    return;
  }
 
  fclose(file);
}

