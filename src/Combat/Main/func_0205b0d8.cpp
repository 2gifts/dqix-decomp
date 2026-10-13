#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

extern const fix16_t data_020e9450[4096 * 2];

static inline fix32_t SineSample(int sample) {
    return data_020e9450[sample * 2];
}

static inline fix32_t CosineSample(int sample) {
    return data_020e9450[sample * 2 + 1];
}

extern "C" ARM void func_0205b0d8(SpriteContext0205ac40* context, Matrix2x2* transform,
                                  Matrix2x2* affine, B174Outer* sprite) {
    Matrix2x2 rotation;
    if (sprite != NULL && transform != NULL && affine != NULL) {
        func_020c111c(&rotation, SineSample(sprite->angle >> 4), CosineSample(sprite->angle >> 4));
        ScalePairsByTwoFactors(&rotation, transform, sprite->scaleX, sprite->scaleY);
        ScalePairsByTwoFactors(&rotation, affine,
                              fix32_Divide(0x1000, sprite->scaleX),
                              fix32_Divide(0x1000, sprite->scaleY));
    }
}
