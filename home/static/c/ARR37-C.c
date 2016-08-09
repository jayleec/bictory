#include<stdio.h>
#include <stddef.h>

struct numbers {
  short num_a;
  short num_b;
  /* . . . */
  short num_z;
};
 
int sum_numbers(const struct numbers *numb){
  int total = 0;
  const short *numb_ptr;
 
  for (numb_ptr = &numb->num_a;
       numb_ptr <= &numb->num_z;
       numb_ptr++) {  // violation 
    total += *(numb_ptr); 
  }
 
  return total;
}
 
/* However, this solution is likely to cause exactly the sort of
   painful experience the programmer who wrote the noncompliant code
   example was trying to avoid. */

void problem(){
  struct numbers my_numbers = { 1, 2, 3 };
  int x = sum_numbers(&my_numbers);
  printf("%d\n",x);
}

int sum_numbers2(const short *numb, size_t dim) {
  int total = 0;
  const short *numb_ptr;
 
  for (numb_ptr = numb; numb_ptr < numb + dim; numb_ptr++) {
    total += *(numb_ptr);
  }
 
  return total;
}

void safe(void) {
  short my_numbers[9] = { 1, 2, 3 };
  int x = sum_numbers2(my_numbers,
              sizeof(my_numbers)/sizeof(my_numbers[0]));
  printf("%d\n",x);
}

int main(void) {
  problem();
  safe();
  return 0;
}

 
