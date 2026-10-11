#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct StatStageStruct02087954;
int CanAdjustStatStageBit6(struct StatStageStruct02087954* p, int decrease);
extern "C" int func_020879a8(struct StatStageStruct02087954* p, int delta);
void UpdateCombatantAgility(int a, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Flag_021db994 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021db994 {
    char pad0[0xc];
    void* field0xc;
    void* field0x10;
    int count;
    char pad18[0x75 - 0x18];
    unsigned char field0x75;
};
struct Params_021db994 { char pad[0x30]; short stageDelta; };

extern "C" int func_ov024_021e96e4(struct Obj_021db994* ctx, int id,
    struct Params_021db994* params, int mode, signed char result,
    int resultFlag, unsigned char specialFlag);

// USA: func_ov024_021db994
extern "C" ARM void* func_ov024_021db994(struct Obj_021db994* obj, int unused, int id, struct Params_021db994* params, int unused2, int unused3, unsigned char flagArg) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    int changed = 0;
    int result = 0;
    int decrease = 0;
    int delta = params->stageDelta;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    if (delta < 0) decrease = 1;
    if (flagArg != 0) {
        if (!CanAdjustStatStageBit6((struct StatStageStruct02087954*)c->currentStats_, (unsigned char)decrease)) {
            obj->field0x75 = 0;
        } else {
            result = func_020879a8((struct StatStageStruct02087954*)c->currentStats_, (signed char)delta);
            UpdateCombatantAgility((int)obj->field0x10, id);
            changed = 1;
            obj->count++;
        }
    } else {
        obj->field0x75 = 0;
    }
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    unsigned short sel = func_ov024_021e96e4(obj, id, params, (unsigned char)decrease, (signed char)result, changed, flagArg);
    func_ov024_021e8bf0(obj, obj->field0xc, &sel);
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
    struct Flag_021db994* fl = (struct Flag_021db994*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
    return entry;
}
