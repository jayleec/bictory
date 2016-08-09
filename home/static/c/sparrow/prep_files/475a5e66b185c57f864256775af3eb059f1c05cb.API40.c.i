# 1 "/home/kskyj/sparrow4/util/testcode/c/API40.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API40.c"
int sums[10];

int getBadSum(int badIndex) {
 int sum = 0;

 if(sum == 0) {
  if(badIndex + 1 > 0) {
   return sums[badIndex];
  }
  return sums[badIndex];
 }

 return sums[badIndex];
}

int getGoodSumG(int goodIndex) {
 int sum = 0;

 if(goodIndex >=0 && goodIndex < 10) {
  return sums[goodIndex];
 }

 return -1;
}
