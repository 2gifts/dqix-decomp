#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3Fixed02030e2c {
    int x;
    int y;
    int z;
};

struct Struct02041538;

void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
void RefreshSelectionState02041538(struct Struct02041538* self);

struct MoveObj020412f4 {
    char pad0[0x44];
    Vector3i pos;
    char pad1[0xb4 - 0x50];
    Vector3i target;
    char pad2[0xc8 - 0xc0];
    int step;
};

// USA: func_020412f4  (semantic: AdvanceTowardOrSnap020412f4)
extern "C" ARM void func_020412f4(struct MoveObj020412f4* obj) {
    Vector3i diff;
    Vector3fix_Subtract(&obj->target, &obj->pos, &diff);
    int length = Vector3fix_Length(&diff);
    if (obj->step < length) {
        int scale = fix32_Divide(obj->step, length);
        Vector3fixMultiplyScalar(&diff, scale, &diff);
        Vector3i sum;
        Vector3fix_Add(&obj->pos, &diff, &sum);
        obj->pos = sum;
    } else {
        obj->pos = obj->target;
        RefreshSelectionState02041538((struct Struct02041538*)obj);
    }
}
