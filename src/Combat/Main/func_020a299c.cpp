#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Sub020a299c {
    char pad0[0x10];
    int b;
    Vec3 c;
    Vec3 d;
};

struct Obj020a299c {
    char pad0[0x10];
    Vec3 pos;
    char pad1[0x220 - 0x1c];
    Vec3 v220;
    char pad2[0x245 - 0x22c];
    unsigned char flags;
    char pad3[0x298 - 0x246];
    Sub020a299c sub;
};

struct Traj020a299c {
    char pad0[0x44];
    Vec3 v44;
};

extern "C" void __clear(void* ptr, int size);
extern "C" int func_02032124(struct Vec3* a, struct Sub020a299c* b);
extern "C" int _Z8fix32absi(int x);
extern "C" int fix32_Divide(int num, int denom);
extern "C" int _Z24fix32SignedAngleDistanceii(int a, int b);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int a);
extern "C" void Vector3fix_Add(const struct Vec3* a, const struct Vec3* b, struct Vec3* out);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const struct Vec3* in, int scale, struct Vec3* out);
extern "C" void _Z34CopyVec3ToField0x10AndCall0202e5d8PcPi(void* obj, int* vec);
void ApplyVec3Tail(void* obj, int* vec);

static inline int FxMul(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

static inline int Lerp(int a, int b, int t) {
    int x = FxMul(a, t);
    int y = FxMul(b, 0x1000 - t);
    return y + x;
}

// USA: func_020a299c
extern "C" ARM int func_020a299c(struct Obj020a299c* obj, const struct Vec3* v, const struct Traj020a299c* traj) {
    if ((obj->flags & 4) == 0 && (obj->flags & 8) == 0) {
        return 0;
    }
    struct Vec3 tv = traj->v44;
    struct Vec3 out;
    __clear(&out, 0xc);
    int d = func_02032124(&tv, (struct Sub020a299c*)&obj->sub);
    if (d > 0) {
        int t = fix32_Divide(_Z8fix32absi(d), obj->sub.b);
        if (t > 0x1000) {
            t = 0x1000;
        }
        if (obj->flags & 4) {
            out.x = _Z22fix32ReduceAngle0To2Pii(obj->v220.x + FxMul(_Z24fix32SignedAngleDistanceii(obj->v220.x, obj->sub.c.x), t));
        } else if (obj->flags & 8) {
            out.x = obj->v220.x;
        }
        out.y = Lerp(obj->sub.c.y, obj->v220.y, t);
        out.z = Lerp(obj->sub.c.z, obj->v220.z, t);
        struct Vec3 sv;
        struct Vec3 st;
        struct Vec3 tmp;
        struct Vec3 res;
        Vector3fix_Add(&obj->pos, &obj->sub.d, &tmp);
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(v, (int)(0x1000u - (unsigned int)t), &sv);
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&tmp, t, &st);
        Vector3fix_Add(&sv, &st, &res);
        _Z34CopyVec3ToField0x10AndCall0202e5d8PcPi(obj, (int*)&res);
        ApplyVec3Tail(obj, (int*)&out);
        return 1;
    }
    return 0;
}