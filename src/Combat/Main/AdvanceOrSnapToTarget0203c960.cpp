#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3Fixed02030e2c { int x; int y; int z; };
ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_0203fc5c {
    char pad[0x40];
    float field40;
};
ARM int SetField40IfPositive(struct Struct_0203fc5c* obj, float value);

extern "C" double _dflt(int);

struct MoverObj0203c960 {
    char pad0[4];
    Vector3i position;
    char pad1[0x4c];
    int flags;
    char pad2[0x18];
    Vector3i target;
    char pad3[8];
    int speed;
};

// USA: func_0203c960
ARM void AdvanceOrSnapToTarget0203c960(struct MoverObj0203c960* obj) {
    Vector3i diff;
    Vector3fix_Subtract(&obj->target, &obj->position, &diff);
    int dist = Vector3fix_Length(&diff);
    if (obj->speed < dist) {
        int scale = fix32_Divide(obj->speed, dist);
        Vector3fixMultiplyScalar(&diff, scale, &diff);
        Vector3i sum;
        Vector3fix_Add(&obj->position, &diff, &sum);
        obj->position = sum;
        double speedD = _dflt(obj->speed);
        float f = (float)(speedD / 0.03 / 4096.0);
        SetField40IfPositive((struct Struct_0203fc5c*)obj, f);
        return;
    }
    obj->position = obj->target;
    obj->flags &= ~1;
}
