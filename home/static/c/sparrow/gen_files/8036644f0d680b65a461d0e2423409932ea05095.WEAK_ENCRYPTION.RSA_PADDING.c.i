/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:55 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.RSA_PADDING.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float;
#line 9 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.RSA_PADDING.c"
typedef int RSA;


extern void _Z18RSA_public_encryptiPcS_Pii(int size, char *text, char *out, RSA *rsa, int option);
extern RSA *_Z7RSA_newv(void);

extern void _Z10badPaddingPci(char *text, int size);
#line 21
extern void _Z11goodPaddingPci(char *text, int size);
#line 15
void _Z10badPaddingPci( char *__12_24_text,  int __12_34_size) {
auto char __13_7_out[512];
auto RSA *__14_8_rsa_p; __14_8_rsa_p = (_Z7RSA_newv());
_Z18RSA_public_encryptiPcS_Pii(__12_34_size, __12_24_text, (__13_7_out), __14_8_rsa_p, 0); 
}

void _Z11goodPaddingPci( char *__18_25_text,  int __18_35_size) {
auto char __19_7_out[512];
auto RSA *__20_8_rsa_p; __20_8_rsa_p = (_Z7RSA_newv());
_Z18RSA_public_encryptiPcS_Pii(__18_35_size, __18_25_text, (__19_7_out), __20_8_rsa_p, 1); 
}
