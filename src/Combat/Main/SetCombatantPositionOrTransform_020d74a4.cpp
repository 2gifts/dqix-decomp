#include <globaldefs.h>
#include "System/Matrix.h"

struct Target020d74a4 {
    char pad[0xe8];
    Matrix4x3 mtx;
};

struct Combatant020d74a4 {
    char pad0[0x4];
    struct Target020d74a4* target;
    char pad1[0x3c];
    Vector3i pos;
    char pad2[0x5c];
    int flag0xac;
    char pad3[0x28];
};

// USA: func_020d74a4  (semantic: SetCombatantPositionOrTransform_020d74a4)
extern "C" ARM void func_020d74a4(struct Combatant020d74a4* base, int index, Vector3i v) {
    Matrix4x3 mtx;
    if (base[index].flag0xac == 0) {
        base[index].pos = v;
    } else {
        struct Target020d74a4* target;
        Mat4x3_WriteIdentity(&mtx);
        Mat4x3_ApplyTranslation(&mtx, &mtx, v.x, v.y, v.z);
        target = base[index].target;
        target->mtx = mtx;
    }
}
