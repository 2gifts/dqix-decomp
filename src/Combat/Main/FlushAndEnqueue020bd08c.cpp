#include <globaldefs.h>

extern "C" void func_020ca3ec(int value, void* dst, int size);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int EnqueueEvent0x0C_020d1ee4(int a, int b, int c, int d);

struct Flag0210fd74 {
    char pad[0x48];
    int flag48;
};

struct Ctx0210fdbc {
    char pad0[0xc];
    void* p0xc;
    void* p0x10;
    unsigned int size14;
    char pad1[0x1c - 0x18];
    int f1c;
    char pad2[0x24 - 0x20];
    int f24;
    int f28;
    int f2c;
};

extern Flag0210fd74 data_0210fd74;
extern Ctx0210fdbc data_0210fdbc;

// USA: func_020bd08c  (semantic: FlushAndEnqueue020bd08c)
extern "C" ARM void func_020bd08c(void) {
    Ctx0210fdbc* ctx = &data_0210fdbc;
    if (data_0210fd74.flag48 == 0) return;
    ctx->f1c = 0;
    func_020ca3ec(0, ctx->p0xc, ctx->size14);
    func_020ca3ec(0, ctx->p0x10, ctx->size14);
    CleanInvalidateCacheRange(ctx->p0xc, ctx->size14);
    CleanInvalidateCacheRange(ctx->p0x10, ctx->size14);
    int shift = ctx->f2c;
    int mask = (shift >= 0) ? (1 << shift) : 0;
    EnqueueEvent0x0C_020d1ee4(ctx->f24, ctx->f28, mask, 0);
}
