#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void func_ov024_021ea85c(void* obj, int id, int a2);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Flag_021e02b0 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Obj_021e02b0 {
    char pad0[0xc];
    void* field0xc;
    void* field0x10;
    int field0x14;
    char pad18[0x44 - 0x18];
    short field0x44;
};

// JPN: func_ov024_021e0b48
// USA: func_ov024_021e02b0
extern "C" ARM void* func_ov024_021e02b0(struct Obj_021e02b0* obj, int unused, int id, int unused3, int unused4, int unused5, unsigned char flagArg) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    if (flagArg) {
        func_ov024_021ea85c(obj, id, 0);
        func_ov000_02159eac(obj->field0x10, &local, 0x28);
        obj->field0x14++;
        if (obj->field0x44 < 0) {
            obj->field0x44 = id;
        }
    }
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    struct Flag_021e02b0* fl = (struct Flag_021e02b0*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
    return entry;
}
