#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Vec3_02030ef0 {
    int x;
    int y;
    int z;
};

extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" int Vector3fix_Length(int* v);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct Vector3i;
void Vector3fixDivideScalar(Vector3i const*, int, Vector3i*);

struct MoveState020a1034 {
    int flag_0x0;
    struct Vec3 pos_0x4;
    struct Vec3 target_0x10;
    char unk_1c[0x8];
    int steps_0x24;
};

// USA: func_020a1034
ARM void AdvanceVec3TowardTarget020a1034(struct MoveState020a1034* obj) {
    struct Vec3 diff;
    Vector3fix_Subtract(&obj->target_0x10, &obj->pos_0x4, &diff);
    if (Vector3fix_Length((int*)&diff) < 0x199) {
        _ZN8Vector3iaSERKS_((int*)&obj->pos_0x4, (int*)&obj->target_0x10);
        obj->flag_0x0 = 0;
    } else {
        struct Vec3 quotient;
        Vector3fixDivideScalar((Vector3i const*)&diff, obj->steps_0x24, (Vector3i*)&quotient);
        Vector3fix_Add(&obj->pos_0x4, &quotient, &obj->pos_0x4);
    }
}
