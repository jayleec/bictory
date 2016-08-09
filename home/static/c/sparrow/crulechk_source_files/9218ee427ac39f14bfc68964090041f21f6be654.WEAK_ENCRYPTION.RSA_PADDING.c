// @checker WEAK_ENCRYPTION.RSA_PADDING
// Dummy defines
#define RSA_NO_PADDING 0
#define RSA_PKCS1_OAEP_PADDING 1

#define MAX_TEXT 512

// Dummy typedefs
typedef int RSA;

// Dummy function
extern void RSA_public_encrypt(int size, char * text, char * out, RSA * rsa, int option);
extern RSA * RSA_new();

void badPadding(char * text, int size) {
	char out[MAX_TEXT];
	RSA * rsa_p = RSA_new();
	RSA_public_encrypt(size, text, out, rsa_p, RSA_NO_PADDING); // @violation WEAK_ENCRYPTION.RSA_PADDING
}

void goodPadding(char * text, int size) {
	char out[MAX_TEXT];
	RSA * rsa_p = RSA_new();
	RSA_public_encrypt(size, text, out, rsa_p, RSA_PKCS1_OAEP_PADDING);
}
