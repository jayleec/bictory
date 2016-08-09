# 1 "/home/kskyj/sparrow4/util/testcode/c/API37.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API37.c"
typedef struct bad {
 char a;
} bad_t;

void badFoo(void) {
 struct bad badVar;
 bad_t badVarTypeDef;

 struct {
  char b;
 } badAnonymous;
}

typedef struct good {
 char a;
} good_t;

void goodFoo(void) {
 struct good goodVar;
 good_t goodVarTypeDef;
}
