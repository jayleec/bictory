/* ARR30-C. Do not form or use out of bounds pointers or array
   subscripts */
#include <stdio.h>
#include <stdlib.h>

int* arr30_bad1(int* table, int index){
  if (index < 100){
    return table + index;
  }
    return 0;
}

int arr30_bad2(int pos, int value) {
  int *table2 = (int*)malloc(sizeof(int)*10);
  int size = 0;
  size = 100;
  if (size < pos) {
    int *tmp;
    size = pos + 1;
    tmp = (int*)realloc(table2, sizeof(table2) * size);
    if (0 == tmp)
      return -1;
 
    table2 = tmp;
  }
  
  if(table2 == 0) return;

  table2[pos + pos] = value; 
  free(table2);
  return 0;
}

int main_arr30(){
  int *p;
  int table[100];
 
  p = arr30_bad1(table, -1);
  *p = 10; //@violation UNDERRUN.STATIC
  arr30_bad2(100, 10); //@violation OVERRUN.DYNAMIC
  return 0;
}
