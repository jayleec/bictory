# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRING_MANAGEMENT.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRING_MANAGEMENT.c"



void _mbscpy(char * str1, char * str2) {}
void _mbscpy_s(char * str1, int size, char * str2) {}
void _mbscat(char * str1, char * str2) {}
void _mbscat_s(char * str1, char * str2) {}

void f(char * str1, int size, char * str2) {
 _mbscpy(str1, str2);
 _mbscpy_s(str1, size, str2);
 _mbscat(str1, str2);
 _mbscat_s(str1, str2);
}
