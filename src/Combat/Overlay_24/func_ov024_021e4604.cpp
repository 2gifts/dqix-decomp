#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct FlagObj_021e47dc;

extern "C" int func_ov000_02156068(void* obj, int id, int a2, int a3);
extern "C" int _Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc(struct FlagObj_021e47dc* obj);
void ClearFlag0x400000AndBytes(unsigned char* stats);
extern "C" void func_ov000_0215a004(void* a0, int id1, int id2, int flags, void* buf, int extra, int flag, int mode);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);

struct Ctl_021e4604 {
    char pad0[0x1c];
    unsigned char pad1c : 7;
    unsigned char flag : 1;
};

struct Obj_021e4604 {
    char pad0[0xc];
    struct Ctl_021e4604* ctl;
    void* field0x10;
};

struct Stats_021e4604 {
    char pad0[0x48];
    unsigned char field0x48;
};

static inline unsigned short GetCurrentHP(GameObject* c) {
    unsigned short hp = c->currentStats_->primaryStats.currHP;
    return hp;
}

// JPN: func_ov024_021e4e9c
// USA: func_ov024_021e4604
extern "C" ARM unsigned long long func_ov024_021e4604(struct Obj_021e4604* obj, int srcId, int id, int extra) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!func_ov000_02156068(obj->field0x10, id, 0, 1)) {
        if ((int)((struct Stats_021e4604*)c->currentStats_)->field0x48 <= 0) return 0;
    }
    int roll = NextRandomMax((struct Random*)obj->field0x10, 100);
    float chance = 12.5f;
    if (!func_ov000_02156068(obj->field0x10, id, 0, 1)) {
        chance = chance * ((int)((struct Stats_021e4604*)c->currentStats_)->field0x48 / 100.0f);
    }
    if (obj->ctl->flag) chance = 100.0f;
    if (roll >= chance) return 0;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    if (_Z23IsFlagBit22Set_021e47dcP16FlagObj_021e47dc((struct FlagObj_021e47dc*)c)) {
        ClearFlag0x400000AndBytes((unsigned char*)c->currentStats_);
        func_ov000_0215a004(obj->field0x10, srcId, id, GetCurrentHP(c) - 1, &local, extra, obj->ctl->flag != 0, 0);
        func_ov000_02159eac(obj->field0x10, &local, 0x29);
    } else {
        func_ov000_0215a004(obj->field0x10, srcId, id, 0xffff, &local, extra, obj->ctl->flag != 0, 8);
        local.lo = 0;
        local.hi = 0;
        func_ov000_02159eac(obj->field0x10, &local, 0xd);
    }
    return local.v;
}
