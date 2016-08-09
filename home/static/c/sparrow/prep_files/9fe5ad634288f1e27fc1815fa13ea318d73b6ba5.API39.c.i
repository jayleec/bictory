# 1 "/home/kskyj/sparrow4/util/testcode/c/API39.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/API39.c"
typedef struct bad {
  char a;
} bad_t;

void badFoo(bad_t badParam) {
  bad_t badVar;
}

typedef struct good {
  char a;
} good_t;

void goodFoo(good_t goodParam) {
  good_t goodVar;
}
