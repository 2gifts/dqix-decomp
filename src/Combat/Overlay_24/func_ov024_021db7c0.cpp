#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087860;
struct StatStageStruct020878b4;
struct Obj_021db7c0;
struct Info_021db7c0;

extern "C" unsigned long long func_ov024_021e4b14(struct Obj_021db7c0* obj, int a, int id, struct Info_021db7c0* info, int d);
extern "C" int _Z22CanAdjustStatStageBit3P23StatStageStruct02087860i(struct StatStageStruct02087860* p, unsigned char decrease);
extern "C" int func_020878b4(struct StatStageStruct020878b4* p, int delta);
void UpdateCombatantDefense(int unused, int combatantId);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" unsigned short func_ov024_021e95d4(struct Obj_021db7c0* obj, int id, struct Info_021db7c0* info, unsigned char decrease, signed char adjustment, int changed, unsigned char flag);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Flag_021db7c0 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Obj_021db7c0 {
    char pad0[0xc];
    void* field0xc;
    void* field0x10;
    char pad14[0x73 - 0x14];
    unsigned char field0x73;
    char pad74;
    unsigned char field0x75;
};

struct Info_021db7c0 {
    char pad0[0x30];
    short stageDelta;
};

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021db7c0
extern "C" ARM void* func_ov024_021db7c0(struct Obj_021db7c0* obj, short a, int id, struct Info_021db7c0* info, int unused4, int unused5, unsigned char flagArg) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    unsigned long long res = 0;
    int applied = 0;
    int decrease = 0;
    int delta = info->stageDelta;
    int result = 0;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    if (delta < 0) decrease = 1;
    if (flagArg) {
        res = func_ov024_021e4b14(obj, a, id, info, 1);
        if (_Z22CanAdjustStatStageBit3P23StatStageStruct02087860i((struct StatStageStruct02087860*)c->currentStats_, decrease)) {
            result = func_020878b4((struct StatStageStruct020878b4*)c->currentStats_, (signed char)delta);
            UpdateCombatantDefense((int)obj->field0x10, id);
            applied = 1;
        } else {
            obj->field0x75 = 0;
        }
    } else {
        obj->field0x75 = 0;
    }
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    unsigned short sel = func_ov024_021e95d4(obj, id, info, decrease, result, applied, flagArg);
    if (res != 0 && !applied) {
        sel = 0;
    }
    if (IsPartyMember(id) && applied) {
        if (!decrease) obj->field0x73 = 1;
    }
    func_ov024_021e8bf0(obj, obj->field0xc, &sel);
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
    struct Flag_021db7c0* fl = (struct Flag_021db7c0*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, res, fl->flag != 0);
    return entry;
}
