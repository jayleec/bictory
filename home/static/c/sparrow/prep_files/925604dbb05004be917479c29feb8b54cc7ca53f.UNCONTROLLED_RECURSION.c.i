# 1 "/home/kskyj/sparrow4/util/testcode/c/UNCONTROLLED_RECURSION.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/UNCONTROLLED_RECURSION.c"

int fac(int n) {
 if(fac(n-1) && n > 0) {

 }

 if((n > 0 || fac(n-1)) && fac(n-1)) {

 }

 if(fac(n-1)) {

 }

 return n * fac(n-1);
}

int fac2(int n) {
 if(n <= 0) {
  return 1;
 }

 return n * fac2(n-1);
}

int fac3(int n) {
 return n > 0 ? n * fac3(n-1) : 1;
}

int fac4(int n) {
 return fac4(n) > 0 ? n * fac4(n-1) : 1;
}

int fac5(int n) {
 if(n >= 0) {
  switch(n) {
  case 0:
   return 1;
  default:
   return fac5(n-1);
  }
 } else {
  return -1;
 }
}
