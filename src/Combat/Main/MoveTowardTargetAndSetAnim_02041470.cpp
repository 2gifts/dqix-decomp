#include <globaldefs.h>
#include "System/Matrix.h"
#include "World/Object3D.h"

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

int fix32ReduceAngle0To2Pi(int angle);

extern char data_020efe6c;
extern char data_020efe71;

struct Obj02041470 : Object3D {
    unsigned short fac;
    int fb0;
    Vector3i posCurrent;
    char pad2[0xd0 - 0xc0];
    int fd0;
    unsigned char bit0d4 : 1;
    unsigned char runFlag : 1;
    unsigned char restd4 : 6;
};

// USA: func_02041470  (semantic: MoveTowardTargetAndSetAnim_02041470)
extern "C" ARM void func_02041470(struct Obj02041470* obj, Vector3i* target) {
    int dist = Vector3fix_Distance(target, &obj->position_);
    if (dist == 0) {
        return;
    }
    obj->posCurrent = *target;
    obj->fac |= 1;
    int mode = obj->fd0;
    if (!obj->runFlag) {
        obj->MaybeSetRegularAnimation(&data_020efe6c, mode);
    } else {
        obj->MaybeSetRegularAnimation(&data_020efe71, mode);
    }
    if (!(obj->fac & 4)) {
        Vector3i diff;
        Vector3fix_Subtract(&obj->posCurrent, &obj->position_, &diff);
        int scale = fix32_Divide(0x1000, dist);
        Vector3fixMultiplyScalar(&diff, scale, &diff);
        int angle = fix32_Atan2(diff.x, diff.z);
        obj->fb0 = fix32ReduceAngle0To2Pi(angle);
    }
}
