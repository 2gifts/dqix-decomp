#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct OutStruct0215ccbc;
struct EffectWords_021e56c0 { int lo; int hi; };

short ApplyMPDelta0215a1d4(void* unused, int id, int delta, short* outApplied);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* ctx);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct EffectWords_021e56c0* words, int effect);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    int unused, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    struct EffectWords_021e56c0 words, unsigned char byteE);
void AppendToChainAndIncCount0215fe84(void* obj, void* node, int idx);

struct Chain_021e56c0 { char pad[0x24]; short mp; };
struct Obj_021e56c0 {
    char pad0[8];
    struct Chain_021e56c0* chain;
    char pad1[4];
    void* ctx;
};

// USA: func_ov024_021e56c0
extern "C" ARM void func_ov024_021e56c0(struct Obj_021e56c0* obj, int id, int unused, int value) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return;
    int amount = value >> 3;
    if (amount <= 0) return;
    short applied = 0;
    short mp = ApplyMPDelta0215a1d4(obj->ctx, id, amount, &applied);
    obj->chain->mp = mp;
    struct OutStruct0215ccbc* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return;
    AddEntryAndIncrementCount0215a88c(obj->ctx, entry, 0x214);
    struct EffectWords_021e56c0 words;
    words.lo = 0;
    words.hi = 0;
    func_ov000_02159eac(obj->ctx, &words, 0x22);
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)obj->ctx, entry, c, -amount,
        c->currentStats_->primaryStats.currHP, mp, words, 0);
    AppendToChainAndIncCount0215fe84(obj->chain, entry, 2);
    ((unsigned char*)obj->ctx)[0x8e02]++;
}
