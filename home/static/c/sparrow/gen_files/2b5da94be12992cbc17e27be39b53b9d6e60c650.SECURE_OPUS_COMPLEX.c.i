/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:52 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/SECURE_OPUS_COMPLEX.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 271 "/usr/include/libio.h"
struct _IO_FILE; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 211 "/usr/local/lib/gcc/i686-pc-linux-gnu/4.5.3/include/stddef.h"
typedef unsigned size_t;
#line 49 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 214 "/usr/include/stdio.h"
extern int fclose(FILE *__stream);
#line 249 "/usr/include/stdio.h"
extern FILE *fopen(const char *__filename, const char *__modes);
#line 333 "/usr/include/stdio.h"
extern int fprintf(FILE *__stream, const char *__format, ...);
#line 339
extern int printf(const char *__format, ...);

extern int sprintf(char *__s, const char *__format, ...);
#line 363
extern int snprintf(char *__s, size_t __maxlen, const char *__format, ...);
#line 604 "/usr/include/stdio.h"
extern char *fgets(char *__s, int __n, FILE *__stream);
#line 151 "/usr/include/stdlib.h"
extern long atol(const char *__nptr);
#line 471 "/usr/include/stdlib.h"
extern void *malloc(size_t __size);
#line 488
extern void free(void *__ptr);
#line 543 "/usr/include/stdlib.h"
extern void exit(int __status);
#line 566 "/usr/include/stdlib.h"
extern char *getenv(const char *__name);
#line 712 "/usr/include/stdlib.h"
extern int system(const char *__command);
#line 64 "/usr/include/string.h"
extern void *memset(void *__s, int __c, size_t __n);
#line 127 "/usr/include/string.h"
extern char *strcpy(char *__dest, const char *__src);


extern char *strncpy(char *__dest, const char *__src, size_t __n);




extern char *strcat(char *__dest, const char *__src);


extern char *strncat(char *__dest, const char *__src, size_t __n);



extern int strcmp(const char *__s1, const char *__s2);
#line 397 "/usr/include/string.h"
extern size_t strlen(const char *__s);
#line 12 "/home/kskyj/sparrow4/util/testcode/c/SECURE_OPUS_COMPLEX.c"
extern void SQLExecDirect(int a, char *b, int c);
extern int ldap_search_ext_s(int *a, char *b, int c, char *d, void *e, int f, void *k, void *g, int h, int i, char **j);
extern int *ldap_simple_bind_s(int *a, char *b, char *c);
extern int *dlopen(char *a, int b);
extern void SQLConnect(char *a);
extern char *verify(char *a);
extern char *getpasswd();

extern void U51000089_1(int sqlh);
#line 40
extern void release(int a, char *buf);
#line 46
extern void memory_leak(int a);
#line 65
extern char *ret_null(int a);




extern void null_deref(int a);
#line 84
extern void rpt(int a);
#line 96
extern int unlink();



extern int ldap_injection(int a);
#line 113
extern int ldap_manipulation(int *ld, void *file, char *password, char *dn);
#line 135
extern int ldap_safe_manipulation(int *ld, char *username, char *password, char *dn);
#line 145
extern int resource_injection();
#line 151
extern int connect();
#line 157
extern int process_control(int a);
#line 171
extern int information_exposure(int a);
#line 187
extern int main(int argc, char **argv);



extern int sethostid();
#line 206
extern int searchData2LDAP(void *ld, char *username);
#line 226
extern void *integer_overflow(int reserve);
#line 236
extern void *safe_integer_overflow(int reserve);
#line 249
extern void safe_plaintext_passwd();
#line 263
extern void plaintext_passwd();
#line 278
extern int hardcoded_crypt(char *passwd, int salt);
extern int crypt();
#line 293
extern int safe_hardcoded_crypt(char *passwd, int salt);
#line 307
extern void unexpected_sign_extension2(int __2354_37_size);
#line 327
extern void unexpected_sign_extension(int size);
#line 345
extern void test_strcpy();
#line 355
extern void *aux_test_extreme(int *buf, char n);
#line 361
extern void test_extreme();
#line 145 "/usr/include/stdio.h"
extern struct _IO_FILE *stdin;

extern struct _IO_FILE *stderr;
#line 38 "/home/kskyj/sparrow4/util/testcode/c/SECURE_OPUS_COMPLEX.c"
char *global_pointer;
#line 12
void SQLExecDirect( int __2049_31_a,  char *__2049_40_b,  int __2049_47_c) {   }
int ldap_search_ext_s( int *__2050_35_a,  char *__2050_44_b,  int __2050_51_c,  char *__2050_59_d,  void *__2050_67_e,  int __2050_74_f,  void *__2050_83_k,  void *__2050_92_g,  int __2050_99_h,  int __2050_106_i,  char **__2050_116_j) { return *__2050_35_a; }
int *ldap_simple_bind_s( int *__2051_37_a,  char *__2051_46_b,  char *__2051_55_c) { return ((int *)0); }
int *dlopen( char *__2052_26_a,  int __2052_33_b) { return ((int *)0); }
void SQLConnect( char *__2053_29_a) {   }
char *verify( char *__2054_27_a) { return __2054_27_a; }
char *getpasswd() { return ((char *)99U); }

void U51000089_1( int __2057_22_sqlh) {
auto char *__2058_9_query;
auto char *__2059_9_tmp = "Safe";
auto int __2060_7_result; auto int __2060_15_i;
#line 21
__2058_9_query = (getenv(((const char *)"query_string")));


if (__2057_22_sqlh > 100) {
__2059_9_tmp = __2058_9_query;
__2060_7_result = 0;
} else  {
__2060_7_result = 50;
}
for (__2060_15_i = 0; (__2060_15_i < 50); __2060_15_i++) {
__2060_7_result += __2060_15_i;
}
if (__2057_22_sqlh > 0) {
SQLExecDirect(__2057_22_sqlh, __2059_9_tmp, 0);
} 
}



void release( int __2077_18_a,  char *__2077_27_buf) {
if (__2077_18_a > 100) {
free(((void *)__2077_27_buf));
} 
}

void memory_leak( int __2083_22_a) {
auto char *__2084_10_buf;
auto int __2085_7_result; auto int __2085_15_i;
if (__2083_22_a > 100) {
__2084_10_buf = ((char *)(malloc(10U)));
}
(*__2084_10_buf) = ((char)100);
__2085_7_result = 1000;
for (__2085_15_i = 0; (__2085_15_i < 50); __2085_15_i++) {
__2085_7_result += __2085_15_i;
}
if ((__2083_22_a > 100) && (__2083_22_a < 200)) {
global_pointer = __2084_10_buf;
} else  if (__2083_22_a > 200) {
release(__2083_22_a, __2084_10_buf);
} 

}

char *ret_null( int __2102_20_a) {
if (__2102_20_a > 50) { return ((char *)0); }
return "ABC";
}

void null_deref( int __2107_21_a) {
auto char *__2108_10_p;
auto char __2109_8_cgi_home[100];
#line 71
__2108_10_p = (ret_null(__2107_21_a));

if (__2107_21_a > 100) {
__2108_10_p = "SAFE";
}

if (__2107_21_a > 50) {
strncpy((__2109_8_cgi_home), ((const char *)__2108_10_p), 99U);
}
((__2109_8_cgi_home)[99]) = ((char)0); 
}


void rpt( int __2121_14_a) {
auto char *__2122_9_rName;
auto char __2123_8_buf[30];
auto char __2124_8_result[100];
#line 85
__2122_9_rName = (getenv(((const char *)"reportName")));


strcpy((__2124_8_result), ((const char *)"ABCD"));
strncpy((__2123_8_buf), ((const char *)"/home/www/tmp/"), 20U);
if (__2121_14_a > 100) {
strncat((__2123_8_buf), ((const char *)__2122_9_rName), 20U);
}
strcat((__2124_8_result), ((const char *)"EFG"));
strncat((__2124_8_result), ((const char *)"ThisIsMeaninglessDontCare"), 3U);
if (__2121_14_a > 50) {
unlink((__2123_8_buf));
} 
}

int ldap_injection( int __2137_24_a)
{
auto char *__2139_9_filter;
auto int __2140_7_rc;
auto int *__2141_8_ld = ((int *)0);
auto char *__2142_9_result;
#line 102
__2139_9_filter = (getenv(((const char *)"filter_string")));



if (__2137_24_a > 100) __2139_9_filter = "USER";
__2140_7_rc = (ldap_search_ext_s(__2141_8_ld, "", 0, __2139_9_filter, ((void *)0), 0, ((void *)0), ((void *)0), 0, 0, (&__2142_9_result)));
return 0;
}



int ldap_manipulation( int *__2150_28_ld,  void *__2150_38_file,  char *__2150_50_password,  char *__2150_66_dn) {
auto char __2151_8_base[100];
auto char __2152_8_manager[90];
auto int __2153_7_rc; auto int __2153_10_i; auto int __2153_12_n;
auto char *__2154_9_result;
__2153_7_rc = 0;
for (__2153_10_i = 0; (__2153_10_i < 50); __2153_10_i++) {
__2153_7_rc += (__2153_10_i + 1);
((__2152_8_manager)[__2153_10_i]) = ((char)97);
}
((__2152_8_manager)[__2153_10_i]) = ((char)48);
if (__2153_7_rc > 10) {
__2153_12_n = ((int)(fgets((__2152_8_manager), 90, ((FILE *)__2150_38_file))));
}
if (__2153_12_n == 0) return 0;
__2153_12_n = (snprintf((__2151_8_base), 100U, ((const char *)"(user=%s)"), (__2152_8_manager)));
if (__2153_12_n < 0) return 0;
ldap_simple_bind_s(__2150_28_ld, (__2152_8_manager), __2150_50_password);
__2153_7_rc = (ldap_search_ext_s(__2150_28_ld, (__2151_8_base), 0, "manager=m1", ((void *)0), 0, ((void *)0), ((void *)0), 0, 0, (&__2154_9_result)));
return __2153_7_rc;
}

int ldap_safe_manipulation( int *__2172_33_ld,  char *__2172_43_username,  char *__2172_59_password,  char *__2172_75_dn) {
auto int __2173_7_rc;
auto char *__2174_10_result;
if ((*__2172_33_ld) > 20) {
ldap_simple_bind_s(__2172_33_ld, __2172_43_username, __2172_59_password);
}
__2173_7_rc = (ldap_search_ext_s(__2172_33_ld, "ou=NewHires", 0, "manager=m1", ((void *)0), 0, ((void *)0), ((void *)0), 0, 0, (&__2174_10_result)));
return __2173_7_rc;
}

int resource_injection()
{
auto char *__2184_9_rPort;
auto int __2185_25_sockfd = 0;
auto char __2186_8_buf[25];
#line 147
__2184_9_rPort = (getenv(((const char *)"rPort")));


strcpy((__2186_8_buf), ((const char *)__2184_9_rPort));
if ((connect(__2185_25_sockfd, (&__2186_8_buf), 4U)) < 0) {
exit(1);
}
return 0;
}

int process_control( int __2194_25_a)
{
auto char *__2196_9_filename = "shared";
auto int *__2197_8_handle;
if (__2194_25_a > 0) {
__2196_9_filename = (getenv(((const char *)"SHAREDFILE")));
}
__2197_8_handle = (dlopen(__2196_9_filename, 0));
if (__2197_8_handle != ((int *)0)) {
exit(1);
}
return 0;
}

int information_exposure( int __2208_30_a) {
auto char *__2209_9_path;
auto char *__2210_9_new;
#line 172
__2209_9_path = (getenv(((const char *)"MYPATH")));
__2210_9_new = ((char *)(malloc(100U)));
if (__2210_9_new == ((char *)0)) return 1;
if (__2208_30_a > 100) {
sprintf(__2210_9_new, ((const char *)"%s\n"), __2209_9_path);
} else  {
memset(((void *)__2210_9_new), 0, 99U);
}
if ((2 * __2208_30_a) > 150) {
fprintf(stderr, ((const char *)__2210_9_new));
}
free(((void *)__2210_9_new));
return 0;
}

int main( int __2224_14_argc,  char **__2224_27_argv) {
auto char __2225_8_arg[80];
auto char __2226_8_cat[5] = "cat "; auto char *__2226_30_command;
auto int __2227_7_commandLength;
sethostid((atol(((const char *)(__2224_27_argv[2])))));

fgets((__2225_8_arg), 80, stdin);
__2227_7_commandLength = ((int)(((strlen(((const char *)(__2226_8_cat)))) + (strlen(((const char *)(__2225_8_arg))))) + 1U));
__2226_30_command = ((char *)(malloc(((size_t)__2227_7_commandLength))));
if (__2226_30_command == ((char *)0)) return 0;
strncpy(__2226_30_command, ((const char *)(__2226_8_cat)), ((size_t)__2227_7_commandLength));
strncat(__2226_30_command, ((const char *)(__2224_27_argv[1])), (((unsigned)__2227_7_commandLength) - (strlen(((const char *)(__2226_8_cat))))));
system(((const char *)__2226_30_command));
free(((void *)__2226_30_command));
printf(((const char *)"This is a debug code: %d"), __2224_14_argc);
return 0;
}


int searchData2LDAP( void *__2243_27_ld,  char *__2243_37_username) {
auto unsigned long __2244_17_rc;
auto char __2245_8_filter[20];
auto char *__2246_9_result;

auto int __2248_7_i;
#line 210
__2244_17_rc = 0UL;

for (__2248_7_i = 0; (__2248_7_i < 50); __2248_7_i++) {
__2244_17_rc += ((unsigned long)(__2248_7_i + 1));
}

snprintf((__2245_8_filter), 20U, ((const char *)"(name=%s)"), __2243_37_username);
__2244_17_rc = ((unsigned long)(ldap_search_ext_s(((int *)__2243_27_ld), "", 0, (__2245_8_filter), ((void *)0), 0, ((void *)0), ((void *)0), 0, 0, (&__2246_9_result))));

return (int)__2244_17_rc;
}
#line 226
void *integer_overflow( int __2263_29_reserve) {
auto void *__2264_9_rptr;
auto int __2265_7_size; __2265_7_size = ((int)(getenv(((const char *)"A"))));
__2265_7_size += __2263_29_reserve;
__2264_9_rptr = (malloc((((unsigned)__2265_7_size) * 4U)));
if (__2264_9_rptr == ((void *)0))
exit(1);
return __2264_9_rptr;
}

void *safe_integer_overflow( int __2273_34_reserve) {
auto void *__2274_9_rptr;
auto unsigned __2275_12_s;
auto int __2276_7_size; __2276_7_size = ((int)(getenv(((const char *)"B"))));
__2276_7_size += __2273_34_reserve;
__2275_12_s = (((unsigned)__2276_7_size) * 4U);
if (__2275_12_s < 0U) return ((void *)0);
__2274_9_rptr = (malloc(__2275_12_s));
if (__2274_9_rptr == ((void *)0))
exit(1);
return __2274_9_rptr;
}

void safe_plaintext_passwd() {
auto char __2287_8_passwd[20];
auto char *__2288_9_verifiedPwd;
auto void *__2289_9_fp;
auto int __2290_7_i; auto int __2290_11_result = 0;
#line 252
__2289_9_fp = ((void *)(fopen(((const char *)"config"), ((const char *)"r"))));

for (__2290_7_i = 0; (__2290_7_i < 10); __2290_7_i++) {
__2290_11_result += __2290_7_i;
}
if ((fgets((__2287_8_passwd), 20, ((FILE *)__2289_9_fp))) == ((char *)0)) return;
fclose(((FILE *)__2289_9_fp));
__2288_9_verifiedPwd = (verify((__2287_8_passwd)));
SQLConnect(__2288_9_verifiedPwd); 
}

void plaintext_passwd() {
auto char __2301_8_passwd[20];
auto char *__2302_9_verifiedPwd;
auto void *__2303_9_fp;
auto int __2304_7_i; auto int __2304_9_n; auto int __2304_11_result = 0;
#line 266
__2303_9_fp = ((void *)(fopen(((const char *)"config"), ((const char *)"r"))));

for (__2304_7_i = 0; (__2304_7_i < 10); __2304_7_i++) {
__2304_11_result += __2304_7_i;
}
__2304_9_n = ((int)(fgets((__2301_8_passwd), 20, ((FILE *)__2303_9_fp))));
if (__2304_9_n == 0) return;
fclose(((FILE *)__2303_9_fp));
__2302_9_verifiedPwd = (__2301_8_passwd);
SQLConnect(__2302_9_verifiedPwd); 
}

int hardcoded_crypt( char *__2315_27_passwd,  int __2315_38_salt) {
auto char *__2316_9_cpasswd;
auto char *__2317_9_tmp;
auto char *__2318_9_str = "68af404n513073528n63c378";
auto int __2319_7_i; auto int __2319_9_result = 0;
#line 279
__2316_9_cpasswd = ((char *)(crypt(__2315_27_passwd, __2315_38_salt)));
__2317_9_tmp = __2316_9_cpasswd;


for (__2319_7_i = 0; (__2319_7_i < 10); __2319_7_i++) {
__2319_9_result += __2315_38_salt;
}
if (((strcmp(((const char *)__2317_9_tmp), ((const char *)__2318_9_str))) != 0) && (__2319_9_result > (__2315_38_salt * 2))) {
printf(((const char *)"Incorrect password \n"));
return (-1);
}
return 0;
}

int safe_hardcoded_crypt( char *__2330_32_passwd,  int __2330_43_salt) {
auto char *__2331_9_cpasswd;
auto char *__2332_9_saved;
auto int __2333_7_i; auto int __2333_9_result = 0;
#line 294
__2331_9_cpasswd = ((char *)(crypt(__2330_32_passwd, __2330_43_salt)));
__2332_9_saved = (getpasswd());

for (__2333_7_i = 0; (__2333_7_i < 10); __2333_7_i++) {
__2333_9_result += __2330_43_salt;
}
if (((strcmp(((const char *)__2331_9_cpasswd), ((const char *)__2332_9_saved))) != 0) && (__2333_9_result > (__2330_43_salt * 5))) {
printf(((const char *)"Incorrect password \n"));
return (-1);
}
return 0;
}

void unexpected_sign_extension2( int __2344_38___2354_37_size) {
auto char __2345_11___2355_8_buf[10];
auto char *__2346_12___2356_9_p;
auto unsigned __2347_15___2357_16_x;
__2346_12___2356_9_p = (__2345_11___2355_8_buf);


if (__2344_38___2354_37_size < 0) __2347_15___2357_16_x = ((unsigned)__2344_38___2354_37_size);

if (__2344_38___2354_37_size > 10) {
__2346_12___2356_9_p = ((char *)(malloc(((unsigned)__2344_38___2354_37_size))));
free(((void *)__2346_12___2356_9_p));
}

if (__2344_38___2354_37_size < 10) {
__2346_12___2356_9_p = ((char *)(malloc(((unsigned)__2344_38___2354_37_size))));
free(((void *)__2346_12___2356_9_p));
} 
}

void unexpected_sign_extension( int __2364_37_size) {
auto char __2365_8_buf[10];
auto char *__2366_9_p;
auto unsigned __2367_16_x;
#line 329
__2366_9_p = (__2365_8_buf);


if (__2364_37_size < 0) __2367_16_x = ((unsigned)__2364_37_size);

if (__2364_37_size > 10) {
__2366_9_p = ((char *)(malloc(((unsigned)__2364_37_size))));
free(((void *)__2366_9_p));
}

if (__2364_37_size < 10) {
__2366_9_p = ((char *)(malloc(((unsigned)__2364_37_size))));
free(((void *)__2366_9_p));
} 
}

void test_strcpy() {
auto char *__2383_10_a;


auto char __2386_10_buf[20];
#line 346
__2383_10_a = ((char *)(malloc(5U)));
if (__2383_10_a == ((char *)0)) return;


strcpy(__2383_10_a, ((const char *)(__2386_10_buf)));
free(((void *)__2383_10_a));
return;
}

void *aux_test_extreme( int *__2392_29_buf,  char __2392_39_n) {
(__2392_29_buf[(((int)__2392_39_n) + 2)]) = 0;

return (void *)__2392_29_buf;
}

void test_extreme() {
auto char *__2399_11_a;

__2399_11_a = ((char *)(malloc(12U)));
if (__2399_11_a == ((char *)0)) return;

aux_test_extreme(((int *)__2399_11_a), ((char)4));
free(((void *)__2399_11_a));
0; return;
}
