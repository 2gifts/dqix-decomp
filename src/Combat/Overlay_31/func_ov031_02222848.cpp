#include <globaldefs.h>

struct Md5Ctx02222848 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int count_lo;
    unsigned int count_hi;
    unsigned char buf[0x40];
};

extern "C" void func_ov031_02221e84(Md5Ctx02222848* ctx);
extern "C" void func_ov031_02221eac(Md5Ctx02222848* ctx, unsigned char* data, unsigned int len);
extern "C" void func_ov031_02221f24(unsigned char* digest, Md5Ctx02222848* ctx);

// USA: func_ov031_02222848
extern "C" THUMB void func_ov031_02222848(unsigned char* digest, unsigned char* data, unsigned int len) {
    Md5Ctx02222848 ctx;

    func_ov031_02221e84(&ctx);
    func_ov031_02221eac(&ctx, data, len);
    func_ov031_02221f24(digest, &ctx);
}
