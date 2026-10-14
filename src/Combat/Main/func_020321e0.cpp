#include <globaldefs.h>

#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

static inline int FxSquare(int a) {
    return (int)(((long long)a * a + 0x800) >> 12);
}

// USA: func_020321e0
extern "C" ARM int func_020321e0(const Vector3fix* self, const Bounds3D* bounds, int angle, const Vector3fix* pivot, int radiusSq) {
    Vector3fix out = *self;
    Vector3fix diff;
    Matrix4x3 mtxCopy;
    int len2;

    if (angle != 0) {
        int zSq, xSq;

        Vector3fix_Subtract(self, pivot, &diff);
        zSq = FxSquare(diff.z);
        xSq = FxSquare(diff.x);
        len2 = xSq + zSq;
        if (radiusSq < len2) {
            return 0;
        }
        mtxCopy = RotationMatrixY(fix32ReduceAngle0To2Pi(-angle));
        Mat4x3_ApplyToVector(&diff, &mtxCopy, &diff);
        Vector3fix_Add(&diff, pivot, &out);
    }
    return func_02031118(&out, bounds);
}
