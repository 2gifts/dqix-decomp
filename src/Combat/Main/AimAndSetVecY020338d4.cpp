#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);

struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct Struct020338d4 {
    char pad[0x44];
    struct Vec3 vec;
};

// USA: func_020338d4
ARM void AimAndSetVecY020338d4(struct Struct020338d4* self, struct Vec3* target) {
    struct Vec3 v;
    Vector3fix_Subtract(target, &self->vec, &v);
    Vector3fix_Normalize(&v, &v);
    int angle = fix32ReduceAngle0To2Pi(fix32_Atan2(v.x, v.z));
    SetVecYFromValue02033874((struct Obj02033874*)self, angle);
}
