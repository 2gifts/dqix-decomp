#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct StatStageStruct020877c0;
int CanAdjustField0x58(void* obj, int dir);
extern "C" int func_020877c0(struct StatStageStruct020877c0* p, int delta);
void UpdateCombatantAttack(int a, int id);
struct Obj_021e8ca0;
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Flag_021e2ebc { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e2ebc { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Params_021e2ebc { char pad[0x32]; short stageDelta; };

extern "C" int func_ov024_021e94c4(struct Obj_021e2ebc* ctx, int id,
    struct Params_021e2ebc* params, unsigned char mode, signed char value,
    unsigned char useValue, unsigned char forceDefault);

// USA: func_ov024_021e2ebc
extern "C" ARM unsigned long long func_ov024_021e2ebc(struct Obj_021e2ebc* obj, int unused, int id, struct Params_021e2ebc* params, int enabled) {
    if (enabled <= 0) return 0;
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    int rnd = NextRandomMax((struct Random*)obj->field0x10, 100);
    int delta = params->stageDelta;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    int decrease = 0;
    if (delta < 0) {
        if (*((unsigned char*)c->currentStats_ + 0x4f) == 0) return 0;
        struct Flag_021e2ebc* fl = (struct Flag_021e2ebc*)((char*)obj->field0xc + 0x1c);
        if (!fl->flag) {
            float limit = *((unsigned char*)c->currentStats_ + 0x4f);
            if ((float)rnd >= limit) return 0;
        }
        decrease = 1;
    }
    int changed = 0;
    int result = 0;
    if (CanAdjustField0x58(c->currentStats_, (unsigned char)decrease)) {
        result = func_020877c0((struct StatStageStruct020877c0*)c->currentStats_, (signed char)delta);
        UpdateCombatantAttack((int)obj->field0x10, id);
        changed = 1;
    }
    if (changed) {
        int sel = func_ov024_021e94c4(obj, id, params, decrease, (signed char)result, 1, 1);
        void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, sel);
        if (entry) {
            func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, 0);
        }
    }
    return 0;
}
