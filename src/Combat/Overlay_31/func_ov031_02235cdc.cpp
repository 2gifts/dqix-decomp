#include <globaldefs.h>
#include <System/Memory.h>

struct WirelessKeySettings {
    unsigned char field_0[0x480];
    unsigned char key[16];
    unsigned char field_490[0x56];
    unsigned char keyLength : 2;
    unsigned char textFormat : 6;
};
extern WirelessKeySettings* data_ov031_02290cfc;
extern "C" int _Z26FindFirstZeroByte_0223dd34Phi(unsigned char*, int);
extern "C" unsigned int _Z23HexCharToValue_02236760j(unsigned int);

// USA: func_ov031_02235cdc
extern "C" ARM void func_ov031_02235cdc(unsigned char* text) {
    int i;
    VectorizedMemset(data_ov031_02290cfc->key, 0, 16);
    int length = _Z26FindFirstZeroByte_0223dd34Phi(text, 32);
    switch (length) {
    case 0:
    case 10:
    case 26:
    case 32: {
        data_ov031_02290cfc->textFormat = 0;
        unsigned char* output = data_ov031_02290cfc->key;
        i = 0;
        if (i < length) do {
            unsigned char* pair = text + i;
            unsigned int high = _Z23HexCharToValue_02236760j(text[i]);
            unsigned int low = _Z23HexCharToValue_02236760j(pair[1]);
            *output++ = (high << 4) + low;
            i += 2;
        } while (i < length);
        break;
    }
    default:
        data_ov031_02290cfc->textFormat = 1;
        VectorizedInvertedMemcpy(text, data_ov031_02290cfc->key, 16);
        break;
    }
    switch (length) {
    case 0:
        data_ov031_02290cfc->keyLength = 0;
        break;
    case 5:
    case 10:
        data_ov031_02290cfc->keyLength = 1;
        break;
    case 13:
    case 26:
        data_ov031_02290cfc->keyLength = 2;
        break;
    default:
        data_ov031_02290cfc->keyLength = 3;
        break;
    }
}
