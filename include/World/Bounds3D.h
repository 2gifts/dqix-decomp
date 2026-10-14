#pragma once

#include "System/Matrix.h"

struct Bounds3D {
    Vector3fix maximum;
    Vector3fix minimum;
};

typedef char Bounds3DSizeCheck[sizeof(Bounds3D) == 24 ? 1 : -1];
typedef char Bounds3DMinimumOffsetCheck[offsetof(Bounds3D, minimum) == 12 ? 1 : -1];

extern "C" int func_02031118(const Vector3fix* point, const Bounds3D* bounds);
extern "C" int func_020321e0(const Vector3fix* point, const Bounds3D* bounds,
                            int angle, const Vector3fix* pivot, int radiusSquared);
