enum { SIZE = 32 };
 
void func(void) {
  int nums[SIZE];
  char *c_str[SIZE];
  int *next_num_ptr = nums;
  int free_bytes;
 
  /* Increment next_num_ptr as array fills */
 
  free_bytes = c_str - (char **)next_num_ptr;  //@violation 
}
 
void func_safe(void) {
  int nums[SIZE];
  char *c_str[SIZE];
  int *next_num_ptr = nums;
  int free_bytes;
 
  /* Increment next_num_ptr as array fills */
 
  free_bytes = (&(nums[SIZE]) - next_num_ptr) * sizeof(int);
}

int main(){
  func();
  func_safe();
  return 0;
}
