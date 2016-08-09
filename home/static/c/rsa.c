typedef enum {
    EX_RT_OK = 0,
    EX_RT_NOT_OK = 1,
} Ex_ReturnType;

typedef  struct {
    const uint8 modulus[256U];
    uint32  pubExp;  
} EscPkcs1RsaEsV15_PubKeyT;

const EscPkcs1RsaEsV15_PubKeyT cgwPubKey = {
    { 0x00, 0x01, 0xc6,   /*The code is omitted. */ },
    0x11
};

extern uint8* plainData;

Ex_ReturnType HKMC_SecLIL_PkcsRsaEs_Encrypt (
const uint8 * PlainData,
uint16 Length,
uint8 * EncryptedData,
const EscPkcs1RsaEsV15_PubKeyT * RsaEsV15PubKey) 
{
    Ex_ReturnType status = EX_RT_OK;
    EscPkcs1RsaEsV15_EncryptDataT  encData;
    encData.message = PlainData;
    encData.messageLen = Length;
    encData.cipher = EncryptedData;
    encData.pubKey = RsaEsV15PubKey;

    status = EscPkcs1RsaEsV15_Encrypt(&encData);
    return status;
}

int main (void)
{
    Ex_ReturnType status = EX_RT_OK;
    uint8 cipherData[256] = { 0, };
        
    status = HKMC_SecLIL_PkcsRsaEs_Encrypt (plainData, sizeof(plainData), cipherData, cgwPubKey);
    return status;
}
