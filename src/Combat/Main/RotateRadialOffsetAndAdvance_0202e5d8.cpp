#include <globaldefs.h>

extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" int fix32_Sqrt(int value);

struct Vec3;
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Mtx43_02030d84 { unsigned int v[12]; };
struct Mtx43_02030d84 RotationMatrixY(int angle);

struct FixedVec3_2034;
struct FixedMtx3T_2034;
extern "C" void Mat4x3_ApplyToVector(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

static inline int FixedMulRound_0202e5d8(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Vec3Local_0202e5d8 {
    int x;
    int y;
    int z;
};

// USA: func_0202e5d8  (semantic: RotateRadialOffsetAndAdvance_0202e5d8)
extern "C" ARM void func_0202e5d8(void* obj, int angleArg, int radiusY, int heightZ) {
    int rotAngle;
    int sq1, sq2, diff;
    struct Vec3Local_0202e5d8 v;
    struct Mtx43_02030d84 mtxCopy;

    rotAngle = _Z22fix32ReduceAngle0To2Pii(angleArg);
    *(int*)((char*)obj + 0x70) = rotAngle;
    *(int*)((char*)obj + 0x74) = radiusY;
    *(int*)((char*)obj + 0x78) = heightZ;

    sq1 = FixedMulRound_0202e5d8(radiusY, radiusY);
    sq2 = FixedMulRound_0202e5d8(heightZ, heightZ);
    diff = sq2 - sq1;

    v.x = 0;
    v.y = radiusY;
    v.z = fix32_Sqrt(diff);

    mtxCopy = RotationMatrixY(rotAngle);

    Mat4x3_ApplyToVector((struct FixedVec3_2034*)&v, (struct FixedMtx3T_2034*)&mtxCopy, (struct FixedVec3_2034*)&v);

    Vector3fix_Add((struct Vec3*)((char*)obj + 0x10), (struct Vec3*)&v, (struct Vec3*)((char*)obj + 4));
}
