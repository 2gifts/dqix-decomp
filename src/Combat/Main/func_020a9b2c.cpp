#include <globaldefs.h>

extern "C" void* func_02012fe4();
extern "C" void VectorizedInvertedMemcpy(void* dst, const void* src, unsigned int size);

struct Params020a9b2c {
    unsigned char pad000[0xd98];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned short d;
    unsigned char e;
};

struct Mid020a9b2c {
    unsigned char pad000[0xc00];
    Params020a9b2c params;
};

struct Ctx020a9b2c {
    unsigned char pad000[0x198];
    Mid020a9b2c mid;
};

struct Tail020a9b2c {
    unsigned char pad000[0xb34];
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned char pad40[0x4];
    unsigned int f44;
    unsigned char pad48[0x19];
    unsigned char f61;
};

struct Block020a9b2c {
    unsigned char pad000[0x1000];
    Tail020a9b2c tail;
};

struct Battle020a9b2c {
    unsigned char pad000[0x840];
    Block020a9b2c block;
};

// USA: func_020a9b2c
extern "C" ARM int func_020a9b2c(Ctx020a9b2c* ctx) {
    Mid020a9b2c* mid = &ctx->mid;
    Params020a9b2c* params = &mid->params;
    Battle020a9b2c* battle = static_cast<Battle020a9b2c*>(func_02012fe4());
    Block020a9b2c* block = &battle->block;
    block->tail.f38 = params->a;
    block->tail.f34 = params->b;
    block->tail.f44 = params->c;
    block->tail.f3c = params->d & 0xff;
    block->tail.f61 = params->e != 0;
    VectorizedInvertedMemcpy(ctx, block, 0x1b30);
    return 1;
}
