#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void simple_int10(){
  int a = -1;
  int b = -20;
  int c = 10;
  c = a % b; //@violation NEGATIVE_MOD_OPERATION
}

                  
int insert1_bad(int index, int *list, int size, int value) {
  if (size != 0) {
    index = (index + 1) % size; //@violation NEGATIVE_MOD_OPERATION
    list[index] = value; 
    return index;
  }
  else {
    return -1;
  }
}


int insert2_bad(int index, int *list, int size, int value) {
  if (size != 0) {
    index = abs((index + 1) % size); //@violation NEGATIVE_MOD_OPERATION
    list[index] = value; 
    return index;
  }
  else {
    return -1;
  }
}

int insert2_good(int index, int *list, int size, int value) {
  if (size > 0 && index > 0) {
    index = abs(index % size); //@violation(NOT_EXPECTED) NEGATIVE_MOD_OPERATION
    list[index] = value; 
    return index;
  }
  else {
    return -1;
  }
}

int insert1_good(unsigned int* result, unsigned int index, unsigned int *list, unsigned int size, int value) {
  if (size != 0 && size != SIZE_MAX) {
    index = index % size; //@violation(NOT_EXPECTED) NEGATIVE_MOD_OPERATION
    list[index] = value; 
    *result = index;
    return 1;
  }
  else {
    return 0;
  }
}

void unreachable(int index){
  if (index > 0){
    // 실행됨 
    
    if(index < 0){
      // 실행 안됨
    }
    
    if(index + 1 <= 0){
      //실행됨 
    }
  }

}

void unreachable2(){
  int index = unknown();
  if (index > 0){
    // 실행됨 
    opus1_print(8);
    if(index < 0){
      // 실행 안됨
      opus1_print(88);
    
    }
    
    if(index + 1 <= 0){
      //실행됨 
      opus1_print(888);
    }
  }
}


void unreachable3(){
  int index = unknown();
  if (index - 1 > 0){
    opus1_print(9);

    if(index < 0){
      opus1_print(99);
    }
    
    if(index + 1 <= 0){
      opus1_print(999);
    }
  }
}


