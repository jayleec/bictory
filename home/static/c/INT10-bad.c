int insert2_good(int index, int *list, int size, int value) {
  if (size > 0){
    if(index > 0) {
      index = abs(index % size); //@violation(NOT_EXPECTED) NEGATIVE_MOD_OPERATION
      list[index] = value; 
    }
    return index;
  }
  else {
    return -1;
  }
}
