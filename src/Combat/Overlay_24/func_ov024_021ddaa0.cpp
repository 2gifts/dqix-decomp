#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087e18;
struct Obj02087e6c;

extern "C" int _Z23CanAdjustStatStageBit21P23StatStageStruct02087e18i(struct StatStageStruct02087e18* p, unsigned char decrease);
int ClampAndUpdateField0x58(struct Obj02087e6c* obj, int delta);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021ddaa0 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Flag_021ddaa0 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Obj_021ddaa0 {
    char pad0[0xc];
    void* field0xc;
    void* field0x10;
};

struct Info_021ddaa0 {
    char pad0[0x20];
    struct PackedPair_021ddaa0 f20;
    struct PackedPair_021ddaa0 f24;
    char pad28[0x30 - 0x28];
    short stageDelta;
};

// USA: func_ov024_021ddaa0
extern "C" ARM void* func_ov024_021ddaa0(struct Obj_021ddaa0* obj, int unused, int id, struct Info_021ddaa0* info, int unused4, int unused5, unsigned char flagArg) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    int applied = 0;
    int result = 0;
    if (flagArg) {
        int delta = info->stageDelta;
        if (delta < -2) delta = -2;
        if (delta > 2) delta = 2;
        int decrease = 0;
        if (delta < 0) decrease = 1;
        if (_Z23CanAdjustStatStageBit21P23StatStageStruct02087e18i((struct StatStageStruct02087e18*)c->currentStats_, decrease)) {
            result = ClampAndUpdateField0x58((struct Obj02087e6c*)c->currentStats_, (signed char)delta);
            applied = 1;
        }
    }
    unsigned short sel = 0;
    if (applied) {
        if (info->stageDelta > 0) {
            switch (result) {
                case 2: sel = 0x1b0; break;
                case 0: sel = 0x1af; break;
                default: sel = 0x1b1; break;
            }
        } else {
            switch (result) {
                case 0: sel = 0x1af; break;
                default: sel = 0x1ae; break;
            }
        }
    } else {
        sel = _Z31SelectByIndexRange0to3_021da644iii(id, info->f24.b, info->f24.c);
    }
    int extra = _Z31SelectByIndexRange0to3_021da644iii(id, info->f20.c, info->f24.a);
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    if (extra) {
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, extra);
    }
    func_ov024_021e8bf0(obj, obj->field0xc, &sel);
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
    struct Flag_021ddaa0* fl = (struct Flag_021ddaa0*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
    return entry;
}
