#include <globaldefs.h>

struct Vec3_020adfa8 { int x, y, z; };

short fix32cos(int x);
short fix32sin(int x);

struct Vec3s32_020c2f18;
extern "C" void Vector3fix_Normalize(struct Vec3s32_020c2f18* v, struct Vec3s32_020c2f18* out);

struct Vec3Target020ad1f0;
void SetVec3At0x0020ad1f0(struct Vec3Target020ad1f0* obj, int x, int y, int z);

struct Vec3Fixed02030e2c;
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Vec3;
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct ObjFields020adfa8 {
    char pad0[0x44];
    Vec3_020adfa8 f44;
    char pad50[0xae - 0x50];
    short fae;
    char padb0[0x164 - 0xb0];
    Vec3_020adfa8 f164;
    int f170;
    Vec3_020adfa8 f174;
    int f180;
};

// USA: func_020adfa8  (semantic: ComputeTrajectoryOffsets_020adfa8)
extern "C" ARM void func_020adfa8(ObjFields020adfa8* obj) {
    Vec3_020adfa8 v = obj->f44;
    int angle = obj->fae;
    Vec3_020adfa8 dir;
    int zval = fix32cos(angle);
    dir.x = fix32sin(angle);
    dir.y = 0;
    dir.z = zval;
    Vector3fix_Normalize((struct Vec3s32_020c2f18*)&dir, (struct Vec3s32_020c2f18*)&dir);
    Vec3_020adfa8 neg;
    SetVec3At0x0020ad1f0((struct Vec3Target020ad1f0*)&neg, -dir.x, -dir.y, -dir.z);
    Vec3_020adfa8 scaled;
    Vector3fixMultiplyScalar((Vector3i const*)&neg, 0x1ccc, (Vector3i*)&scaled);
    Vec3_020adfa8 sum1;
    Vector3fix_Add((struct Vec3*)&v, (struct Vec3*)&scaled, (struct Vec3*)&sum1);
    _ZN8Vector3iaSERKS_((int*)&obj->f164, (int*)&sum1);
    Vec3_020adfa8 sum2;
    Vector3fix_Add((struct Vec3*)&sum1, (struct Vec3*)&scaled, (struct Vec3*)&sum2);
    _ZN8Vector3iaSERKS_((int*)&obj->f174, (int*)&sum2);
    obj->f170 = angle;
    obj->f180 = angle;
}
