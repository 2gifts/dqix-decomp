#include <globaldefs.h>

struct Vec3 { int x, y, z; };

extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
struct Vec3s32_020c3030;
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct Obj0202ea4c {
    char pad0[4];
    struct Vec3 posA;
    struct Vec3 posB;
    char pad1[0x70 - 0x1c];
    int angle;
    int heightDelta;
    int distance;
};

// USA: func_0202ea4c
ARM void ComputeAngleHeightDistance0202ea4c(struct Obj0202ea4c* obj) {
    struct Vec3 v;
    Vector3fix_Subtract(&obj->posA, &obj->posB, &v);
    v.y = 0;
    Vector3fix_Normalize(&v, &v);
    obj->angle = fix32ReduceAngle0To2Pi(fix32_Atan2(v.x, v.z));
    obj->heightDelta = obj->posA.y - obj->posB.y;
    obj->distance = Vector3fix_Distance((struct Vec3s32_020c3030*)&obj->posA, (struct Vec3s32_020c3030*)&obj->posB);
}
