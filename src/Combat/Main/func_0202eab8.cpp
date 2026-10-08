#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Obj0202eab8 {
    char pad0[4];
    struct Vec3 posA;
    struct Vec3 posB;
    char pad1c[0x70 - 0x1c];
    int angle;
    int heightDelta;
    int distance;
};

struct Vec3f0202eab8 {
    float x;
    float y;
    float z;
};

extern "C" float _fflt(int fix32);
extern "C" float _fdiv(float a, float b);
extern "C" float _fsub(float a, float b);
extern "C" float _fadd(float a, float b);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
extern "C" float _d2f(double value);
extern "C" double func_0200c578(float value);
extern "C" double func_02009598(double a, double b);
extern "C" float func_0200c9b4(float value);
extern "C" void func_0202e5d8(struct Obj0202eab8* obj, int angle, int radiusY, int heightZ);

// UpdateSphericalFromOffset0202eab8
// USA: func_0202eab8
// Shape matters: the three component offsets must live in a stack aggregate (this frame is
// 0xc, slots assigned in first-store order dx@0, dy@4, dz@8), and the z offset must also be
// copied into a named float used ONLY as the atan2 argument. That copy is what makes
// mwccarm emit `mov r6, r0 ; str r6, [sp,#8]` and then reuse r6 for the high word of the
// first double. Named float locals alone (all in callee-saved regs) give 0x198; the plain
// aggregate gives 0x1a0. Losing variants are kept beside this file.
extern "C" ARM void func_0202eab8(struct Obj0202eab8* obj) {
    struct Vec3f0202eab8 delta;
    delta.x = _fsub(_fdiv(_fflt(obj->posA.x), 4096.0f), _fdiv(_fflt(obj->posB.x), 4096.0f));
    delta.y = _fsub(_fdiv(_fflt(obj->posA.y), 4096.0f), _fdiv(_fflt(obj->posB.y), 4096.0f));
    delta.z = _fsub(_fdiv(_fflt(obj->posA.z), 4096.0f), _fdiv(_fflt(obj->posB.z), 4096.0f));

    float deltaZ = delta.z;
    float angle = _d2f(func_02009598(func_0200c578(delta.x), func_0200c578(deltaZ)));
    if (angle < 0.0f) {
        angle = _fadd(angle, 6.2831855f);
    }
    obj->angle = _ffix(_fmul(4096.0f, angle));
    obj->heightDelta = _ffix(_fmul(4096.0f, delta.y));

    float dist = func_0200c9b4(_fadd(_fmul(delta.z, delta.z),
                                    _fadd(_fmul(delta.x, delta.x), _fmul(delta.y, delta.y))));
    obj->distance = _ffix(_fmul(4096.0f, dist));

    func_0202e5d8(obj, obj->angle, obj->heightDelta, obj->distance);
}
