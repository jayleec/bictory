extern void __sparrow_print(char *);
int buffer[100];

void buffer_access(int len){
  if (len < 0) return;
  if (len > 98){
    len = 100 - 4; 
  }
  buffer[len] = 0; 
  buffer[len + 1] = 1;
  buffer[len + 2] = 2; //@violation OVERRUN.STATIC.BAD_COND
  buffer[len + 3] = 3; //@violation OVERRUN.STATIC.BAD_COND
}

void buffer_test(){
  char* title[] = {"a", "b", "c"};
  int cnt= sizeof(title) / sizeof(title[0]);
  __sparrow_print(title[2]);
}

void buffer_test2(int n){
  char arr[5];
  int p = n > 0? n - 1 : 0;
  int nx= n < 4? n + 1 : 4;
  arr[p] = 10;
  arr[nx] = 10;
}

int main(){
  buffer_test();
  buffer_test2(3);
  buffer_test2(-1);
  buffer_test2(5);
  return 1;
}
