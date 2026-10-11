#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int CanAdjustField0x58(void* obj, int dir);
struct StatStageStruct020877c0;
extern "C" int func_020877c0(struct StatStageStruct020877c0* p, int delta);
void UpdateCombatantAttack(int unused, int combatantId);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);

struct Params_021db5ec {
    char pad0[0x30];
    short stage;
};
struct ActionFlags_021db5ec { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Obj_021db5ec {
    char pad0[0xc];
    struct ActionFlags_021db5ec* action;
    void* ctx;
    char pad14[0x72 - 0x14];
    unsigned char field0x72;
    char pad73[2];
    unsigned char field0x75;
};

extern "C" unsigned long long func_ov024_021e4b14(struct Obj_021db5ec* self, short arg, int id, struct Params_021db5ec* params, int d);
extern "C" int func_ov024_021e94c4(struct Obj_021db5ec* ctx, int id, struct Params_021db5ec* params, unsigned char mode, signed char value, unsigned char useValue, unsigned char forceDefault);
extern "C" void* func_ov000_0215e958(void* ctx);
extern "C" void func_ov024_021e8bf0(struct Obj_021db5ec* obj, struct ActionFlags_021db5ec* action, unsigned short* sel);
extern "C" void func_ov000_0215cd44(void* ctx, void* entry, GameObject* c, int valC, unsigned long long words, unsigned char flag);

// USA: func_ov024_021db5ec
extern "C" ARM void* func_ov024_021db5ec(struct Obj_021db5ec* obj, short arg, int id, struct Params_021db5ec* params, int unused, int unused2, unsigned char enabled) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    unsigned long long res = 0;
    bool applied = false;
    int decrease = 0;
    int stage = params->stage;
    int result = 0;
    if (stage < -2) stage = -2;
    if (stage > 2) stage = 2;
    if (stage < 0) decrease = 1;
    if (enabled != 0) {
        res = func_ov024_021e4b14(obj, arg, id, params, 1);
        if (CanAdjustField0x58(c->currentStats_, (unsigned char)decrease)) {
            result = func_020877c0((struct StatStageStruct020877c0*)c->currentStats_, (signed char)stage);
            UpdateCombatantAttack((int)obj->ctx, id);
            applied = true;
        } else {
            obj->field0x75 = 0;
        }
    } else {
        obj->field0x75 = 0;
    }
    void* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    unsigned short sel = func_ov024_021e94c4(obj, id, params, decrease, (signed char)result, applied, enabled);
    if (res != 0 && !applied) {
        sel = 0;
    }
    int inRange = (id >= 0 && id <= 3);
    if (inRange && applied) {
        if (decrease == 0) obj->field0x72 = 1;
    }
    func_ov024_021e8bf0(obj, obj->action, &sel);
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, sel);
    func_ov000_0215cd44(obj->ctx, entry, c, 0, res, obj->action->flag != 0);
    return entry;
}
