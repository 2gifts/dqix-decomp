#include <globaldefs.h>
#include <System/Memory.h>

struct MD5Context020c0430 {
    unsigned long a, b, c, d;
    unsigned long long length;
    union {
        unsigned long buffer32[16];
        unsigned char buffer8[64];
    };
};

extern "C" void func_020c0368(MD5Context020c0430* context, const void* input, unsigned long length);
extern "C" void func_020c04e8(MD5Context020c0430* context);

extern unsigned char data_020f1f8c;

// USA: func_020c0430
extern "C" ARM void func_020c0430(unsigned char* digest, MD5Context020c0430* context) {
    unsigned long long bitLength;
    unsigned long index;
    unsigned long padLength;

    bitLength = context->length << 3;
    func_020c0368(context, &data_020f1f8c, 1);
    index = (unsigned long)(context->length & (64 - 1));
    padLength = 64 - index;
    if (padLength < sizeof(bitLength)) {
        VectorizedMemset(&context->buffer8[index], 0, padLength);
        func_020c04e8(context);
        index = 0;
        padLength = 64;
    }
    if (padLength > sizeof(bitLength))
        VectorizedMemset(&context->buffer8[index], 0, padLength - sizeof(bitLength));

    context->buffer32[14] = (unsigned long)bitLength;
    context->buffer32[15] = (unsigned long)(bitLength >> 32);
    func_020c04e8(context);
    VectorizedInvertedMemcpy(context, digest, 16);
    VectorizedMemset(context, 0, sizeof(MD5Context020c0430));
}
