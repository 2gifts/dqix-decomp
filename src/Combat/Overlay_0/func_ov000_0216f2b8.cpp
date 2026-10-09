#include <globaldefs.h>
#include "System/Matrix.h"
#include "Graphics/Vector.h"

struct Camera0216f2b8 {
    unsigned char pad0[4];
    Vector3fix pos;
    unsigned char pad10[0x220 - 0x10];
    unsigned char mode;
    unsigned char pad221[0x258 - 0x221];
    fix32_t height;
    unsigned char pad25c[4];
    unsigned char clampHeight;
};

extern "C" fix32_t func_ov000_0216f210(struct Camera0216f2b8* self, fix32_t* outLength);
extern "C" void func_0202eab8(struct Camera0216f2b8* self);

// USA: func_ov000_0216f2b8
extern "C" ARM void func_ov000_0216f2b8(struct Camera0216f2b8* self) {
    if (self->mode == 3) {
        return;
    }
    Vector3fix pos = self->pos;
    fix32_t length;
    bool changed = false;
    fix32_t target = func_ov000_0216f210(self, &length);
    if (length > 0x11000) {
        Vector3fix dir = pos;
        dir.y = 0;
        Vector3fix_Normalize(&dir, &dir);
        Vector3fixMultiplyScalar(&dir, 0x11000, &dir);
        pos.x = dir.x;
        pos.z = dir.z;
        changed = true;
    }
    target = FIX32_MULTIPLY(target - self->height, 0x333);
    self->height += target;
    if (self->clampHeight) {
        if (pos.y < self->height) {
            pos.y = self->height;
            changed = true;
        }
    }
    if (pos.y > 0x5000) {
        pos.y = 0x5000;
        changed = true;
    }
    if (changed) {
        self->pos = pos;
        func_0202eab8(self);
    }
}
