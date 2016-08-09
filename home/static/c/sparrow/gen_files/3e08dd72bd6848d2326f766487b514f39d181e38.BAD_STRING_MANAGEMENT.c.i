/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:53 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRING_MANAGEMENT.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 4 "/home/kskyj/sparrow4/util/testcode/c/BAD_STRING_MANAGEMENT.c"
extern void _mbscpy(char *str1, char *str2);
extern void _mbscpy_s(char *str1, int size, char *str2);
extern void _mbscat(char *str1, char *str2);
extern void _mbscat_s(char *str1, char *str2);

extern void f(char *str1, int size, char *str2);
#line 4
void _mbscpy( char *__8_21_str1,  char *__8_34_str2) {   }
void _mbscpy_s( char *__9_23_str1,  int __9_33_size,  char *__9_46_str2) {   }
void _mbscat( char *__10_21_str1,  char *__10_34_str2) {   }
void _mbscat_s( char *__11_23_str1,  char *__11_36_str2) {   }

void f( char *__13_15_str1,  int __13_25_size,  char *__13_38_str2) {
_mbscpy(__13_15_str1, __13_38_str2);
_mbscpy_s(__13_15_str1, __13_25_size, __13_38_str2);
_mbscat(__13_15_str1, __13_38_str2);
_mbscat_s(__13_15_str1, __13_38_str2); 
}
