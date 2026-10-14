#include <globaldefs.h>

struct ClearColorReg5588 {
    volatile unsigned int color;
    volatile unsigned short depth;
};

// USA: func_020c5588
ARM void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fogEnable) {
    struct ClearColorReg5588* reg = (struct ClearColorReg5588*)0x4000350;
    unsigned int value = color | (alpha << 16) | (polygonId << 24);
    if (fogEnable) value |= 0x8000;
    reg->color = value;
    reg->depth = depth;
}
