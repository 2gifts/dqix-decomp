#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3_02030ef0 {
    int x;
    int y;
    int z;
};

void Vector3fixDivideScalar(Vector3i const*, int, Vector3i*);

struct MoveState020a1034 {
    int flag_0x0;
    Vector3i pos_0x4;
    Vector3i target_0x10;
    char unk_1c[0x8];
    int steps_0x24;
};

// USA: func_020a1034
ARM void AdvanceVec3TowardTarget020a1034(struct MoveState020a1034* obj) {
    Vector3i diff;
    Vector3fix_Subtract(&obj->target_0x10, &obj->pos_0x4, &diff);
    if (Vector3fix_Length(&diff) < 0x199) {
        obj->pos_0x4 = obj->target_0x10;
        obj->flag_0x0 = 0;
    } else {
        Vector3i quotient;
        Vector3fixDivideScalar(&diff, obj->steps_0x24, &quotient);
        Vector3fix_Add(&obj->pos_0x4, &quotient, &obj->pos_0x4);
    }
}
