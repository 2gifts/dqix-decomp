#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct OutStruct0215ccbc;
struct EffectWords_021ddf5c { int lo; int hi; };

extern "C" short _Z20ApplyMPDelta0215a1d4PviiPs(void* unused, int id, int delta, short* outApplied);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* ctx);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct EffectWords_021ddf5c* words, int effect);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    int unused, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    struct EffectWords_021ddf5c words, unsigned char byteE);

struct PackedPair_021ddf5c {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Code_021ddf5c { unsigned int code : 12; unsigned int rest : 20; };
struct ActionFlags_021ddf5c { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Obj_021ddf5c {
    char pad0[0xc];
    struct ActionFlags_021ddf5c* action;
    void* ctx;
    int healCount;
};
struct Range_021ddf5c {
    char pad0[4];
    struct Code_021ddf5c f4;
    char pad8[0x18];
    struct PackedPair_021ddf5c f20;
    struct PackedPair_021ddf5c f24;
};

static inline int IsPartySlot(int id) {
    return id >= 0 && id <= 3;
}

// JPN: func_ov024_021de808
// USA: func_ov024_021ddf5c
extern "C" ARM struct OutStruct0215ccbc* func_ov024_021ddf5c(struct Obj_021ddf5c* obj, int unused, int id, struct Range_021ddf5c* range, int amount) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    unsigned short code = range->f4.code;
    if (code == 0x19b || code == 0x22e) amount = c->currentStats_->primaryStats.maxMP;
    short applied = 0;
    short mp = _Z20ApplyMPDelta0215a1d4PviiPs(obj->ctx, id, amount, &applied);
    int full = 0;
    if (!IsPartySlot(id) && c->currentStats_->primaryStats.currMP >= 0xff) full = 1;
    unsigned short sel;
    if (applied > 0 || full) {
        sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
        obj->healCount++;
    } else {
        sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
    }
    struct OutStruct0215ccbc* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, sel);
    struct EffectWords_021ddf5c words;
    words.lo = 0;
    words.hi = 0;
    func_ov000_02159eac(obj->ctx, &words, 0x22);
    unsigned short hp = c->currentStats_->primaryStats.currHP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)obj->ctx, entry, c, -applied, hp, mp, words, flag);
    return entry;
}
