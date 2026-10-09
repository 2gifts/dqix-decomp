#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087b3c;
int CanAdjustStatStageBit12(struct StatStageStruct02087b3c* p, int decrease);
struct StatStageStruct02087b90;
int SetStatStageBit12(struct StatStageStruct02087b90* p, int delta);
void UpdateCombatantMagicalMight(int unused, int combatantId);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);

struct Params_021df284 {
    char pad0[0x24];
    unsigned int : 10;
    unsigned int firstSelector : 10;
    unsigned int secondSelector : 10;
    unsigned int : 2;
    char pad28[0x8];
    short stage;
};
struct ActionFlags_021df284 { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Obj_021df284 {
    char pad0[0xc];
    struct ActionFlags_021df284* action;
    void* ctx;
    int count;
};

extern "C" unsigned long long func_ov024_021e4b14(struct Obj_021df284* self, short arg, int id, struct Params_021df284* params, int d);
extern "C" int func_ov024_021e9904(struct Obj_021df284* ctx, int id, struct Params_021df284* params, unsigned char decrease, signed char stage);
extern "C" void* func_ov000_0215e958(void* ctx);
extern "C" void func_ov024_021e8bf0(struct Obj_021df284* obj, struct ActionFlags_021df284* action, unsigned short* sel);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

// USA: func_ov024_021df284
extern "C" ARM void* func_ov024_021df284(struct Obj_021df284* obj, short arg, int id, struct Params_021df284* params, int unused, int unused2, unsigned char enabled) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    bool applied = false;
    int decrease = 0;
    unsigned long long res = 0;
    unsigned short sel = 0;
    if (enabled != 0) {
        res = func_ov024_021e4b14(obj, arg, id, params, 1);
        int stage = params->stage;
        if (stage < -2) stage = -2;
        if (stage > 2) stage = 2;
        if (stage < 0) decrease = 1;
        if (CanAdjustStatStageBit12((struct StatStageStruct02087b3c*)c->currentStats_, (unsigned char)decrease)) {
            int result = SetStatStageBit12((struct StatStageStruct02087b90*)c->currentStats_, (signed char)stage);
            UpdateCombatantMagicalMight((int)obj->ctx, id);
            applied = true;
            sel = func_ov024_021e9904(obj, id, params, decrease, (signed char)result);
            obj->count++;
        }
    }
    if (!applied && res == 0) {
        sel = _Z31SelectByIndexRange0to3_021da644iii(id, params->firstSelector, params->secondSelector);
    }
    if (res != 0 && !applied) {
        sel = 0;
    }
    void* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    func_ov024_021e8bf0(obj, obj->action, &sel);
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, sel);
    func_ov000_0215cd44(obj->ctx, entry, c, 0, 0, 0, obj->action->flag != 0);
    return entry;
}
