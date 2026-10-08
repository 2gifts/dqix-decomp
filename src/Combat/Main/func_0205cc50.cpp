#include <globaldefs.h>

extern "C" int _Z26GetGlobalField0x1c020421a0v();
struct Struct_0205bd58;
extern "C" void _Z17SetFields0205bd58P15Struct_0205bd58iiiii(Struct_0205bd58 *fields, int count, int a, int b, int c, int d);

struct CombatPairPrefix {
    unsigned char unknown_0[0x58];
    short stateX;
    short stateY;
    unsigned char unknown_5c[0x20];
    int pairCount;
    unsigned char unknown_80[0x34];
    short inputX;
    short inputY;
    short width;
    short height;
    unsigned char unknown_bc[0x14];
    int maximumPayloadSize;
    int unknown_d4;
    int entryStride;
    int entryCount;
    unsigned short widths[8];
    unsigned short offsets[8];
    unsigned short payloadSizes[8];
    unsigned short rowSizes[8];
};

// USA: func_0205cc50
extern "C" ARM void func_0205cc50(void *object, int alignWidth, int adjustment) {
    CombatPairPrefix *pair = static_cast<CombatPairPrefix *>(object);
    _Z26GetGlobalField0x1c020421a0v();

    int count       = pair->pairCount;
    int totalHeight = count * 12 + 16;
    pair->width     = pair->maximumPayloadSize + 24;
    pair->height    = totalHeight + (count - 1) * (pair->entryStride - 12);
    if (alignWidth != 0) {
        short alignedWidth = (short) ((pair->width + 7) & ~7);
        pair->width        = alignedWidth + adjustment;
    }
    for (int index = 0; index < pair->entryCount; ++index) {
        pair->widths[index]  = 12;
        pair->offsets[index] = pair->entryStride * index + 8;
    }
    short x      = pair->inputX;
    short y      = pair->inputY;
    pair->stateX = x;
    pair->stateY = y;
    _Z17SetFields0205bd58P15Struct_0205bd58iiiii(reinterpret_cast<Struct_0205bd58 *>(static_cast<unsigned char *>(object) + 0x20), pair->entryCount,
                      (int) pair->widths, (int) pair->offsets, (int) pair->payloadSizes, (int) pair->rowSizes);
}
