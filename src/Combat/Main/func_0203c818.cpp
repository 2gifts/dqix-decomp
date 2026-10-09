#include <globaldefs.h>
#include "System/Matrix.h"

extern "C" void _Z21UpdateStride0x14ValueP13State0203f20c(void* obj);
extern "C" void func_0203ca24(void* obj, void* p23c);
extern "C" void _Z29AdvanceOrSnapToTarget0203c960P16MoverObj0203c960(void* obj);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);

struct Obj0203c818 {
    char pad0[4];
    Vector3fix f04;
    char pad10[0x5c - 0x10];
    int f5c;
    int f60;
    int f64;
    int f68;
    Vector3fix f6c;
    char pad78[0x88 - 0x78];
    int f88;
};

// USA: func_0203c818
extern "C" ARM void func_0203c818(Obj0203c818* obj, void* p23c, int a2, int a3) {
    _Z21UpdateStride0x14ValueP13State0203f20c(obj);

    if ((obj->f5c & 0x10) || (obj->f5c & 0x20)) {
        func_0203ca24(obj, p23c);
    } else {
        int moved;
        int step;
        int diff;

        if (obj->f5c & 1) {
            _Z29AdvanceOrSnapToTarget0203c960P16MoverObj0203c960(obj);
        }

        moved = 0;
        step = obj->f68 * a3;
        diff = 0;

        if (obj->f60 < obj->f64) {
            diff = obj->f64 - obj->f60;
            if (diff > 0x3244) {
                diff -= 0x3244 * 2;
            }
        } else if (obj->f64 < obj->f60) {
            diff = -(obj->f60 - obj->f64);
            if (diff < -0x3244) {
                diff += 0x3244 * 2;
            }
        }

        if (diff > 0) {
            if (diff < step) {
                obj->f60 = obj->f64;
            } else {
                obj->f60 = obj->f60 + step;
            }
            obj->f5c |= 2;
            moved = 1;
        } else if (diff < 0) {
            if (-diff < step) {
                obj->f60 = obj->f64;
            } else {
                obj->f60 = obj->f60 - step;
            }
            obj->f5c |= 2;
            moved = 1;
        }

        if (moved == 0) {
            obj->f5c &= ~2;
        }

        obj->f60 = _Z22fix32ReduceAngle0To2Pii(obj->f60);
        obj->f6c = obj->f04;

        if (!(obj->f5c & 1)) {
            obj->f88 = obj->f88 + a2;
        } else {
            obj->f88 = 0;
        }
    }
}