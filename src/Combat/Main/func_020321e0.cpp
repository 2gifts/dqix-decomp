#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
struct Mtx43 { unsigned int v[12]; };
struct Bounds { int a; int b; int c; int d; int e; int f; };

static inline int FxSquare(int a) {
    return (int)(((long long)a * a + 0x800) >> 12);
}

extern "C" ARM void Vector3fix_Subtract(const struct Vec3* a, const struct Vec3* b, struct Vec3* out);
extern "C" ARM void Vector3fix_Add(const struct Vec3* a, const struct Vec3* b, struct Vec3* out);
extern "C" ARM void _Z15RotationMatrixYi(struct Mtx43* dst, int angle);
extern "C" ARM void Mat4x3_ApplyToVector(const struct Vec3* v, const struct Mtx43* m, struct Vec3* out);
extern "C" ARM int _Z22fix32ReduceAngle0To2Pii(int angle);
extern "C" ARM int func_02031118(struct Vec3* p, struct Bounds* b);

// USA: func_020321e0
extern "C" ARM int func_020321e0(const struct Vec3* self, struct Bounds* bounds, int angle, const struct Vec3* pivot, int radiusSq) {
    struct Vec3 out = *self;
    struct Vec3 diff;
    struct Mtx43 mtxCopy;
    struct Mtx43 mtx;
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
        _Z15RotationMatrixYi(&mtx, _Z22fix32ReduceAngle0To2Pii(-angle));
        mtxCopy = mtx;
        Mat4x3_ApplyToVector(&diff, &mtxCopy, &diff);
        Vector3fix_Add(&diff, pivot, &out);
    }
    return func_02031118(&out, bounds);
}
