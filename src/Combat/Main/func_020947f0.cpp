#include <globaldefs.h>

struct PaletteAnimation020947f0 {
    char pad0[0x344];
    float phase;
    char pad348[0x3c8 - 0x348];
    unsigned char state : 7;
    unsigned char display : 1;
};
struct PackFields020946f8Struct { unsigned int attributes01; unsigned short attributes2; };
extern "C" double func_02009424(double);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainObjStandardPalette(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubObjStandardPalette(const void*, unsigned int, unsigned int);
int GetDisplayModeCode0209378c(int);
extern "C" unsigned int func_020937f0(int);
PackFields020946f8Struct* TeardownUnlessFlag02093704(int);
void PackFields020946f8(PackFields020946f8Struct*, int, int, int, int, int, int, int, int, int, int, int);

// USA: func_020947f0
extern "C" ARM void func_020947f0(PaletteAnimation020947f0* animation) {
    float amount = (float)func_02009424((double)animation->phase);
    amount += 1.0f;
    amount *= 0.5f;
    short intensity = (short)(31.0f * amount);
    if (intensity < 0) intensity = 0;
    if (intensity > 31) intensity = 31;
    unsigned short color = intensity | (intensity << 5) | (intensity << 10);
    CleanInvalidateCacheRange(&color, 2);
    if (animation->display == 0) LoadToMainObjStandardPalette(&color, 0x1fe, 2);
    else LoadToSubObjStandardPalette(&color, 0x1fe, 2);
    int shift = GetDisplayModeCode0209378c(animation->display);
    unsigned int size = func_020937f0(animation->display);
    if (size) {
        unsigned int tile = (size - 0x800) >> shift;
        int stride = 0x100 >> shift;
        PackFields020946f8Struct* entries = TeardownUnlessFlag02093704(animation->display);
        int x = 0;
        for (unsigned char i = 0; i < 8; ++i) {
            PackFields020946f8(entries + (i + 5), x, 0, 0, 0, 0, 0, 0x80004000, 0, tile, 15, 0);
            tile += stride;
            x += 32;
        }
    }
}
