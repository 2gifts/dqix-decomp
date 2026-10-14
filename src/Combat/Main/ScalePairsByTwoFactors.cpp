#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

ARM void ScalePairsByTwoFactors_020c1128(const Matrix2x2* source, Matrix2x2* destination,
                               fix32_t scaleX, fix32_t scaleY) {
    destination->values[0] = FIX32_MULTIPLY_SIMPLE(scaleX, source->values[0]);
    destination->values[1] = FIX32_MULTIPLY_SIMPLE(scaleX, source->values[1]);
    destination->values[2] = FIX32_MULTIPLY_SIMPLE(scaleY, source->values[2]);
    destination->values[3] = FIX32_MULTIPLY_SIMPLE(scaleY, source->values[3]);
}
