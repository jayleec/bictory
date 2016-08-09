# 1 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.RSA_PADDING.c"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<built-in>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/<command-line>"
# 1 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.RSA_PADDING.c"
# 9 "/home/kskyj/sparrow4/util/testcode/c/WEAK_ENCRYPTION.RSA_PADDING.c"
typedef int RSA;


extern void RSA_public_encrypt(int size, char * text, char * out, RSA * rsa, int option);
extern RSA * RSA_new();

void badPadding(char * text, int size) {
 char out[512];
 RSA * rsa_p = RSA_new();
 RSA_public_encrypt(size, text, out, rsa_p, 0);
}

void goodPadding(char * text, int size) {
 char out[512];
 RSA * rsa_p = RSA_new();
 RSA_public_encrypt(size, text, out, rsa_p, 1);
}
