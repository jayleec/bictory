/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:53 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.HARDCODED_SALT.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 8 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.HARDCODED_SALT.c"
extern void *crypt(const char *text, const char *salt);

extern void badSalt(const char *text);




extern void badSalt2(const char *text);
#line 21
extern void badSalt3(const char *text);
#line 28
extern void badSalt4(const char *text, char *os);
#line 37
extern void goodSalt(const char *text, const char *os);




extern void goodSalt2(const char *text, char *os);
#line 10
void badSalt( const char *__2948_27_text) {
auto char *__2949_9_out;
__2949_9_out = ((char *)(crypt(__2948_27_text, ((const char *)"xp")))); 
}

void badSalt2( const char *__2953_28_text) {
auto char *__2954_9_out;
auto char __2955_7_os[20] = "xp";
__2954_9_out = ((char *)(crypt(__2953_28_text, ((const char *)(__2955_7_os))))); 
}

void badSalt3( const char *__2959_28_text) {
auto char *__2960_9_out;
auto char __2961_7_os[20] = "xp";
auto char *__2962_9_osClone; __2962_9_osClone = (__2961_7_os);
__2960_9_out = ((char *)(crypt(__2959_28_text, ((const char *)__2962_9_osClone)))); 
}

void badSalt4( const char *__2966_28_text,  char *__2966_41_os) {
auto char *__2967_9_out;
auto char __2968_7_salt[20] = "xp";
if (__2966_28_text != ((const char *)0)) {
__2966_41_os = (__2968_7_salt);
}
__2967_9_out = ((char *)(crypt(__2966_28_text, ((const char *)__2966_41_os)))); 
}

void goodSalt( const char *__2975_28_text,  const char *__2975_47_os) {
auto char *__2976_9_out;
__2976_9_out = ((char *)(crypt(__2975_28_text, __2975_47_os))); 
}

void goodSalt2( const char *__2980_29_text,  char *__2980_42_os) {
auto char *__2981_9_out;
auto char __2982_7_salt[20] = "xp";
if (__2980_29_text != ((const char *)0)) {
__2980_42_os = (__2982_7_salt);
} else  {
__2981_9_out = ((char *)(crypt(__2980_29_text, ((const char *)__2980_42_os))));
} 
}
