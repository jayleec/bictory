/* Translated by the Edison Design Group C++/C front end (version 4.8) */
/* Thu Jul 07 09:51:58 2016 */
int __EDGCPFE__4_8;
void *memcpy(); void *memset();
#line 1 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.RISKY_ALGORITHM.c"
struct _Complex_long_double; struct _Complex_double; struct _Complex_float;
#line 6 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.RISKY_ALGORITHM.c"
struct _EVP_CIPHER_CTX; typedef struct _Complex_long_double _Complex_long_double; typedef struct _Complex_double _Complex_double; typedef struct _Complex_float _Complex_float; struct _EVP_CIPHER_CTX {
int dummy;};
typedef struct _EVP_CIPHER_CTX EVP_CIPHER_CTX;

extern void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *);
extern void EVP_EncryptInit(EVP_CIPHER_CTX *, void *, unsigned char *, unsigned char *);
extern void *EVP_des_ecb();
extern void *EVP_aes_128_cbc();

extern void badAlgorithm(unsigned char *key, unsigned char *iv);
#line 24
extern void goodAlgorithm(unsigned char *key, unsigned char *iv);
#line 15
void badAlgorithm( unsigned char *__1109_35_key,  unsigned char *__1109_56_iv) {
auto EVP_CIPHER_CTX __1110_17_ctx;
EVP_CIPHER_CTX_init((&__1110_17_ctx));



EVP_EncryptInit((&__1110_17_ctx), (EVP_des_ecb()), __1109_35_key, __1109_56_iv); 
}

void goodAlgorithm( unsigned char *__1118_36_key,  unsigned char *__1118_57_iv) {
auto EVP_CIPHER_CTX __1119_17_ctx;
EVP_CIPHER_CTX_init((&__1119_17_ctx));



EVP_EncryptInit((&__1119_17_ctx), (EVP_aes_128_cbc()), __1118_36_key, __1118_57_iv); 
}
