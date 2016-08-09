# 1 "/home/kskyj/sparrow4/util/testcode/c/MIS21.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/MIS21.c"
typedef struct bad_st
{
 char a [ 1 + 1];
 char b [ 2 + 1];
 char c [ 40 + 1];
 long double d;
 char e [ 1 + 1];
 long f;
 char g [ 2 + 1];
 char h [ 3 + 1];
 char i [ 8 + 1];
} aba_t_1;

typedef struct good_st
{
 char a [ 1 + 1];
 char b [ 2 + 1];
 char g [ 2 + 1];
 char h [ 3 + 1];
 char i [ 8 + 1];
} aba_t_2;
