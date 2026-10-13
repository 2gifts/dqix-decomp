#include <globaldefs.h>

struct Vec3;
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Mtx43_02030d84 { unsigned int v[12]; };
struct Mtx43_02030d84 RotationMatrixY(int angle);

struct FixedVec3_2034;
struct FixedMtx3T_2034;
extern "C" void Mat4x3_ApplyToVector(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

extern "C" void func_0202eab8(void* obj);

struct Vec3Storage0202e894 {
    unsigned int v[3];
};

static inline void RotateAround0202e894(struct Vec3Storage0202e894* field10Copy, struct Vec3Storage0202e894* field4Copy, int angle) {
    struct Vec3Storage0202e894 diff;
    Vector3fix_Subtract((struct Vec3*)field10Copy, (struct Vec3*)field4Copy, (struct Vec3*)&diff);

    struct Mtx43_02030d84 mtxCopy = RotationMatrixY(angle);

    Mat4x3_ApplyToVector((struct FixedVec3_2034*)&diff, (struct FixedMtx3T_2034*)&mtxCopy, (struct FixedVec3_2034*)&diff);

    Vector3fix_Add((struct Vec3*)field4Copy, (struct Vec3*)&diff, (struct Vec3*)field10Copy);
}

// USA: func_0202e894
ARM void RotateOffsetAndAdvance0202e894(void* obj, int angle) {
    struct Vec3Storage0202e894 field4Copy;
    struct Vec3Storage0202e894 field10Copy;
    field4Copy = *(struct Vec3Storage0202e894*)((char*)obj + 0x4);
    field10Copy = *(struct Vec3Storage0202e894*)((char*)obj + 0x10);

    RotateAround0202e894(&field10Copy, &field4Copy, angle);

    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x10), (int*)&field10Copy);

    func_0202eab8(obj);
}
