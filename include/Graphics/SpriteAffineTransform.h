#pragma once

#include <globaldefs.h>
#include "System/Matrix.h"

struct Matrix2x2 {
    fix32_t values[4];
};

struct SpriteContext0205ac40 {
    char unknown0[0x50];
    unsigned char subScreen;
};

struct B174Inner {
    unsigned short flag;
};

struct B174Outer {
    unsigned short count;
    unsigned short unknown2;
    B174Inner* inner;
    char unknown8[4];
    fix32_t scaleX;
    fix32_t scaleY;
    fix32_t position[2];
    unsigned short angle;
    unsigned short unknown1e;
    unsigned short matrixIndex;
    unsigned char firstObject;
    unsigned char transformed;
    unsigned char doubleSize;
    signed char palette;
    signed char priority;
};

typedef char VerifySpriteMatrixSize[sizeof(Matrix2x2) == 0x10 ? 1 : -1];
typedef char VerifySpriteScaleOffset[offsetof(B174Outer, scaleX) == 0xc ? 1 : -1];
typedef char VerifySpriteAngleOffset[offsetof(B174Outer, angle) == 0x1c ? 1 : -1];
typedef char VerifySpriteMatrixIndexOffset[offsetof(B174Outer, matrixIndex) == 0x20 ? 1 : -1];

extern "C" void func_020c111c(Matrix2x2* rotation, fix32_t sine, fix32_t cosine);
void ScalePairsByTwoFactors(const Matrix2x2* source, Matrix2x2* destination,
                           fix32_t scaleX, fix32_t scaleY);
extern "C" void func_0205b0d8(SpriteContext0205ac40* context, Matrix2x2* transform,
                             Matrix2x2* affine, B174Outer* sprite);
int GetBits10And11(int unused, B174Outer* sprite);
