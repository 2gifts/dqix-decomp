#include "System/OverlayMD5.h"

// USA: func_ov031_02222848
extern "C" THUMB void func_ov031_02222848(unsigned char* digest, unsigned char* data, unsigned int len) {
    OverlayMD5Context ctx;

    func_ov031_02221e84(&ctx);
    func_ov031_02221eac(&ctx, data, len);
    func_ov031_02221f24(digest, &ctx);
}
