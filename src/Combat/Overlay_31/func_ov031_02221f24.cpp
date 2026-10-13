#include <globaldefs.h>

struct DigestContext02221f24 {
    unsigned int state[4];
    unsigned int bitCount[2];
    unsigned char buffer[64];
};
extern "C" void func_ov031_022227c0(void* destination, const void* source, unsigned int count);
extern "C" void func_ov031_02221eac(DigestContext02221f24* context, const void* input, unsigned int length);
extern "C" void func_ov031_02222830(void* destination, int value, unsigned int count);
extern const unsigned char data_ov031_0224b194[64];

// USA: func_ov031_02221f24
extern "C" THUMB void func_ov031_02221f24(unsigned char* digest, DigestContext02221f24* context) {
    unsigned int bitCount[2];
    func_ov031_022227c0(bitCount, context->bitCount, 8);
    unsigned int used = (context->bitCount[0] >> 3) & 0x3f;
    unsigned int padding = used < 0x38 ? 0x38 - used : 0x78 - used;
    func_ov031_02221eac(context, data_ov031_0224b194, padding);
    func_ov031_02221eac(context, bitCount, 8);
    func_ov031_022227c0(digest, context, 0x10);
    func_ov031_02222830(context, 0, sizeof(*context));
}
