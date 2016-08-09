/* MEM11-C. Do not assume infinite heap space */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
enum {MAX_LENGTH=100};
 
typedef struct namelist_s {
  double name[999999];
  double name1[999999];
  double name2[999999];
  double name3[999999];
  double name4[999999];
  double name5[999999];
  double name6[999999];
  double name7[999999];
  double name8[999999];
  double name9[999999];
  struct namelist_s* next;
} *namelist_t;

void mem11_bad1() {
  namelist_t names = NULL;
  char new_name[100];
 
  do {
    /* Adding unknown number of records to a list
       The user can enter as much data as he wants and exhaust the heap */
    puts("To quit, enter \"quit\"");
    puts("Enter record:");
    fgets(new_name, 100, stdin);
    if (strcmp(new_name, "quit") != 0) { 
      /* Names continue to be added without bothering about the size on the heap */
      unsigned int i = strlen(new_name) - 1;
      if (new_name[i] == '\n')  
        new_name[i] = '\0';  
      namelist_t new_entry = (namelist_t) malloc(sizeof( struct namelist_s)); //@violation UNREASONABLE_PARAMETER
      opus1_print(sizeof(struct namelist_s));
      if (new_entry == 0) {
        /* handle error */
        return;
      }
      strcpy(new_entry->name, new_name); 
      new_entry->next = names;
      names = new_entry;
    }
    puts(new_name); 
  } while (strcmp( new_name, "quit") != 0); 
 
  return 0;
}

