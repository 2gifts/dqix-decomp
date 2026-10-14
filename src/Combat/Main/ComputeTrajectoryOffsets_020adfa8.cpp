#include <globaldefs.h>
#include "System/Matrix.h"

short fix32cos(int x);
short fix32sin(int x);

struct Vec3Target020ad1f0;
void SetVec3At0x0020ad1f0(struct Vec3Target020ad1f0* obj, int x, int y, int z);

void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct ObjFields020adfa8 {
    char pad0[0x44];
    Vector3i f44;
    char pad50[0xae - 0x50];
    short fae;
    char padb0[0x164 - 0xb0];
    Vector3i f164;
    int f170;
    Vector3i f174;
    int f180;
};

// USA: func_020adfa8  (semantic: ComputeTrajectoryOffsets_020adfa8)
extern "C" ARM void func_020adfa8(ObjFields020adfa8* obj) {
    Vector3i v = obj->f44;
    int angle = obj->fae;
    Vector3i dir;
    int zval = fix32cos(angle);
    dir.x = fix32sin(angle);
    dir.y = 0;
    dir.z = zval;
    Vector3fix_Normalize(&dir, &dir);
    Vector3i neg;
    SetVec3At0x0020ad1f0((struct Vec3Target020ad1f0*)&neg, -dir.x, -dir.y, -dir.z);
    Vector3i scaled;
    Vector3fixMultiplyScalar(&neg, 0x1ccc, &scaled);
    Vector3i sum1;
    Vector3fix_Add(&v, &scaled, &sum1);
    obj->f164 = sum1;
    Vector3i sum2;
    Vector3fix_Add(&sum1, &scaled, &sum2);
    obj->f174 = sum2;
    obj->f170 = angle;
    obj->f180 = angle;
}
