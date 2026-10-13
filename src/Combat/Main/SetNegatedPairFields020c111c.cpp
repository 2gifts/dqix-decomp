#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

extern "C" THUMB void func_020c111c(Matrix2x2* rotation, fix32_t sine, fix32_t cosine) {
    rotation->values[0] = cosine;
    rotation->values[1] = sine;
    rotation->values[2] = -sine;
    rotation->values[3] = cosine;
}
