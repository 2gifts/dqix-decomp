#include <globaldefs.h>
#include "System/Matrix.h"

struct Mtx43_02030d84 { unsigned int v[12]; };
struct Mtx43_02030d84 RotationMatrixY(int angle);

extern "C" void func_0202eab8(void* obj);

struct Vec3Storage0202e894 {
    unsigned int v[3];
};

static inline void RotateAround0202e894(struct Vec3Storage0202e894* field10Copy, struct Vec3Storage0202e894* field4Copy, int angle) {
    struct Vec3Storage0202e894 diff;
    Vector3fix_Subtract((Vector3fix*)field10Copy, (Vector3fix*)field4Copy, (Vector3fix*)&diff);

    struct Mtx43_02030d84 mtxCopy = RotationMatrixY(angle);

    Mat4x3_ApplyToVector((Vector3fix*)&diff, (Matrix4x3*)&mtxCopy, (Vector3fix*)&diff);

    Vector3fix_Add((Vector3fix*)field4Copy, (Vector3fix*)&diff, (Vector3fix*)field10Copy);
}

// USA: func_0202e894
ARM void RotateOffsetAndAdvance0202e894(void* obj, int angle) {
    struct Vec3Storage0202e894 field4Copy;
    struct Vec3Storage0202e894 field10Copy;
    field4Copy = *(struct Vec3Storage0202e894*)((char*)obj + 0x4);
    field10Copy = *(struct Vec3Storage0202e894*)((char*)obj + 0x10);

    RotateAround0202e894(&field10Copy, &field4Copy, angle);

    *(Vector3i*)((char*)obj + 0x10) = *(Vector3i*)&field10Copy;

    func_0202eab8(obj);
}
