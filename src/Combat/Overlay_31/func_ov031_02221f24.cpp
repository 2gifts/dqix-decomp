#include "System/OverlayMD5.h"

extern const unsigned char data_ov031_0224b194[64];

// USA: func_ov031_02221f24
extern "C" THUMB void func_ov031_02221f24(unsigned char* digest, OverlayMD5Context* context) {
    unsigned char encodedBitCount[8];
    func_ov031_022227c0(encodedBitCount, context->bitCount, 8);
    unsigned int used = (context->bitCount[0] >> 3) & 0x3f;
    unsigned int padding = used < 0x38 ? 0x38 - used : 0x78 - used;
    func_ov031_02221eac(context, data_ov031_0224b194, padding);
    func_ov031_02221eac(context, encodedBitCount, 8);
    func_ov031_022227c0(digest, context->state, 0x10);
    func_ov031_02222830(context, 0, sizeof(*context));
}
