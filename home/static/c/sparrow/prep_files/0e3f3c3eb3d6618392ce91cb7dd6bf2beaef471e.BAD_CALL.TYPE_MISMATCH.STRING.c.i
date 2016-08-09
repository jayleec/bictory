# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.TYPE_MISMATCH.STRING.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_CALL.TYPE_MISMATCH.STRING.c"



typedef unsigned int size_t;
typedef short wchar_t;

void wcsncpy(void *, void *, size_t);

void func() {
 char str1[] = "Hello";
 char str2[] = "00000";
 wcsncpy(str2, str1, 5);
}
