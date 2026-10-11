#include <globaldefs.h>

struct Pair0205b0d8 {
    int field0;
    int field4;
    int field8;
    int fieldc;
};

struct Matrix0205b0d8 {
    int values[4];
};

struct Sprite0205b0d8 {
    char padding_0[0xc];
    int scaleA;
    int scaleB;
    char padding_14[8];
    unsigned short modeIndex;
};

extern "C" THUMB void func_020c111c(Pair0205b0d8* obj, int b, int c);
void ScalePairsByTwoFactors(int* src, int* dst, int scaleA, int scaleB);
extern "C" int fix32_Divide(int num, int denom);
extern const short data_020e9450[0x10000 * 2];

static inline int tableSineEntry(int tableIndex) {
    return data_020e9450[tableIndex * 2];
}

static inline int tableCosineEntry(int tableIndex) {
    return data_020e9450[tableIndex * 2 + 1];
}

// USA: func_0205b0d8
extern "C" ARM void func_0205b0d8(void* context, Matrix0205b0d8* transform, Matrix0205b0d8* affine, Sprite0205b0d8* sprite) {
    int scratch[4];
    if (sprite != NULL && transform != NULL && affine != NULL) {
        func_020c111c((Pair0205b0d8*)scratch, tableSineEntry(sprite->modeIndex >> 4), tableCosineEntry(sprite->modeIndex >> 4));
        ScalePairsByTwoFactors(scratch, transform->values, sprite->scaleA, sprite->scaleB);
        ScalePairsByTwoFactors(scratch, affine->values, fix32_Divide(0x1000, sprite->scaleA), fix32_Divide(0x1000, sprite->scaleB));
    }
}
