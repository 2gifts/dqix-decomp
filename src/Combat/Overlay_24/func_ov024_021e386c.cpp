#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Ctx_021e9320;
struct Obj_021e8ca0;
int CheckField0x14FlagsClear(unsigned char* obj);
extern "C" int _Z25SelectResultCode_021e9320P12Ctx_021e9320ii(struct Ctx_021e9320* ctx, int id, int mode);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int a0, int flags, int mask);
void ResetStateFields0x18(unsigned char* obj);
extern "C" void* _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i(struct Obj_021e8ca0* obj, int id);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Stats_021e386c {
    char pad0[0x14];
    int stateFlags;
    char pad18[0x4a - 0x18];
    unsigned char resistRate;
};
struct Chance_021e386c {
    unsigned int enemy : 7;
    unsigned int party : 7;
    unsigned int rest : 18;
};
struct Skill_021e386c {
    char pad0[0x14];
    struct Chance_021e386c chance;
};
struct ActionFlags_021e386c { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Obj_021e386c {
    char pad0[0xc];
    struct ActionFlags_021e386c* action;
    void* ctx;
};

static inline struct Stats_021e386c* StatsOf(GameObject* c) {
    return (struct Stats_021e386c*)c->currentStats_;
}

static inline int IsPartySlot(int id) {
    return id >= 0 && id <= 3;
}

// JPN: func_ov024_021e4104
// USA: func_ov024_021e386c
extern "C" ARM unsigned long long func_ov024_021e386c(struct Obj_021e386c* obj, int actorId, int id, struct Skill_021e386c* skill, int amount) {
    if (amount <= 0) return 0;
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    if (StatsOf(c)->resistRate == 0) return 0;
    if (!CheckField0x14FlagsClear((unsigned char*)StatsOf(c))) return 0;
    int roll = NextRandomMax((struct Random*)obj->ctx, 100);
    float chance = 100.0f;
    if (!obj->action->flag) {
        if (IsPartySlot(actorId)) chance = skill->chance.party;
        else chance = skill->chance.enemy;
        chance = chance * (StatsOf(c)->resistRate / 100.0f);
    }
    if (roll >= chance) return 0;
    int sel = _Z25SelectResultCode_021e9320P12Ctx_021e9320ii((struct Ctx_021e9320*)obj, id, 1);
    union { struct { int lo; int hi; }; unsigned long long v; } words;
    words.lo = 0;
    words.hi = 0;
    if (_Z26IsFlagAllowedMask_021eb4b0iii((int)obj, StatsOf(c)->stateFlags, 0x20)) {
        func_ov000_02159eac(obj->ctx, &words, 0x2b);
    }
    ResetStateFields0x18((unsigned char*)StatsOf(c));
    func_ov000_02159eac(obj->ctx, &words, 0x17);
    void* entry = _Z34AddEntryToListAndIncCount_021e8ca0P12Obj_021e8ca0i((struct Obj_021e8ca0*)obj, sel);
    if (entry) {
        func_ov000_0215cd44(obj->ctx, entry, c, 0, 0, 0);
    }
    return words.v;
}
