# 1 "/home/kskyj/sparrow4/util/testcode/c/EMPTY_BRANCH.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/EMPTY_BRANCH.c"

void no_else_branch(int arg) {
 if (arg) {
 }
}

void empty_else_branch1(int arg) {
 if (arg) {
 } else {
 }
}


void empty_else_branch2(int arg) {
 if (arg) {
 } else;
}

void empty_else_branch3(int arg) {
 if (arg) {
 } else {
  ;
 }
}


void empty_else_branch_not_found(int arg) {
 if (arg) {
 } else {
          int a;
          a = 0;
 }
}


void empty_else_branch_not_found2(int arg) {
 if (arg) {
 } else {
          while (0) {
          }
 }
}


void no_cases(int arg) {
 int a;
 switch (arg) {
 default:
  a = 1;
 }
}

void empty_case(int arg) {
 int a;
 switch (arg) {
 case 1:
 case 2:
  a = 1;
 break;
 default:
  a = 2;
 }
}

void no_default(int arg) {
 int a;
 switch(arg) {
 case 1:
  a = 1;
  break;
 }
}

void empty_default(int arg) {
 int a;
 switch (arg) {
 case 1:
  a = 1;
  break;
 default:
  ;
 }
}
