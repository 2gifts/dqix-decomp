#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void func_020412f4(void* obj);
extern "C" void func_02041378(void* obj);

struct Obj02041298 {
    char pad0[0xac];
    unsigned short flags;
    char pad1[0x12];
    int fieldc0;
    char pad2[0x10];
    unsigned char bit0 : 1;
};

// USA: func_02041298
ARM void AdvanceAndAccumulate02041298(struct Obj02041298* obj, int amount) {
    if (obj->bit0) return;
    ((Object3D*)obj)->AdvanceEffects();
    if (obj->flags & 0x1) func_020412f4(obj);
    func_02041378(obj);
    if ((obj->flags & 0x1) == 0) {
        obj->fieldc0 = obj->fieldc0 + amount;
    } else {
        obj->fieldc0 = 0;
    }
}
