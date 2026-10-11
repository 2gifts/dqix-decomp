#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct OutStruct0215ccbc;
struct EffectWords_021e0bf4 { int lo; int hi; };

extern "C" short _Z17ConsumeMP0215a124Pvii(void* unused, int id, int amount);
extern "C" void func_ov000_02159eac(void* ctx, struct EffectWords_021e0bf4* words, int effect);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* ctx);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    int unused, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    struct EffectWords_021e0bf4 words, unsigned char byteE);

struct ActionFlags_021e0bf4 { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Obj_021e0bf4 {
    char pad0[0xc];
    struct ActionFlags_021e0bf4* action;
    void* ctx;
    int drainCount;
};

// USA: func_ov024_021e0bf4
extern "C" ARM struct OutStruct0215ccbc* func_ov024_021e0bf4(struct Obj_021e0bf4* obj, int unused, int id, int unused2, int amount) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    if (c->currentStats_->primaryStats.currMP < amount) amount = c->currentStats_->primaryStats.currMP;
    short mp = _Z17ConsumeMP0215a124Pvii(obj->ctx, id, amount);
    struct EffectWords_021e0bf4 words;
    words.lo = 0;
    words.hi = 0;
    if (amount > 0) {
        func_ov000_02159eac(obj->ctx, &words, 1);
        func_ov000_02159eac(obj->ctx, &words, 0x2a);
    }
    if (amount > 0) obj->drainCount++;
    struct OutStruct0215ccbc* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    unsigned short hp = c->currentStats_->primaryStats.currHP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)obj->ctx, entry, c, amount, hp, mp, words, flag);
    return entry;
}
