#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct OutStruct0215ccbc;
struct EffectWords_021e3f14 { int lo; int hi; };

struct FlagObj_021e05e4;
struct FlagObj_021da998;
struct FlagObj_021dd260;
extern "C" int _Z30IsFlagBit12Field18Set_021e05e4P16FlagObj_021e05e4(struct FlagObj_021e05e4* obj);
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(struct FlagObj_021da998* obj);
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(struct FlagObj_021dd260* obj);
void SetBool0x180Clear0x17f(unsigned char* obj, int value);
void ClearFlag0x1000AndBytes7eA1(unsigned char* stats);
void DecrementCounter0x24UpdateFlag0x14(void* obj);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void* obj, void* node, int idx);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* ctx);
extern "C" void func_ov000_02159eac(void* ctx, struct EffectWords_021e3f14* words, int effect);
extern "C" void func_ov000_0215cd44(void* ctx, struct OutStruct0215ccbc* entry, GameObject* c, int d,
    struct EffectWords_021e3f14 words, int g);

struct Stats_021e3f14 { char pad[0x24]; unsigned char stage; };
struct Obj_021e3f14 {
    char pad0[0xc];
    void* chain;
    void* ctx;
};

static inline int IsPartySlot(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e3f14
extern "C" ARM unsigned long long func_ov024_021e3f14(struct Obj_021e3f14* obj, int unused, int id, int unused2, int amount) {
    if (amount <= 0) return 0;
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    struct OutStruct0215ccbc* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    int added = 0;
    if (_Z30IsFlagBit12Field18Set_021e05e4P16FlagObj_021e05e4((struct FlagObj_021e05e4*)c)) {
        if (!IsPartySlot(id)) SetBool0x180Clear0x17f((unsigned char*)c, 1);
        ClearFlag0x1000AndBytes7eA1((unsigned char*)c->currentStats_);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, 0x164);
        added = 1;
    }
    struct EffectWords_021e3f14 words;
    words.lo = 0;
    words.hi = 0;
    if (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((struct FlagObj_021da998*)c) || _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260((struct FlagObj_021dd260*)c)) {
        DecrementCounter0x24UpdateFlag0x14(c->currentStats_);
        int msg = 0;
        unsigned char stage = ((struct Stats_021e3f14*)c->currentStats_)->stage;
        switch (stage) {
        case 0: msg = 0x17f; break;
        case 1: msg = 0x180; break;
        case 2: msg = 0x181; break;
        case 3: msg = 0x259; break;
        }
        if (stage == 3) func_ov000_02159eac(obj->ctx, &words, 8);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, msg);
        added = 1;
    }
    if (added) {
        func_ov000_0215cd44(obj->ctx, entry, c, 0, words, 0);
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(obj->chain, entry, 1);
        ((unsigned char*)obj->ctx)[0x8e02]++;
    }
    return 0;
}
