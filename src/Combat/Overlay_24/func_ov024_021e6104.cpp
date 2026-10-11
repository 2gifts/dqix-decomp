#include <globaldefs.h>
#include "GameState/GameState.h"

struct OutStruct0215ccbc;
struct List021600f8;
struct ListNode021600f8;
struct EffectWords_021e6104 { int lo; int hi; };

int TestBit3At0x2f4(unsigned char* obj);
extern "C" struct ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct List021600f8* list, int index);
extern "C" void* _Z23FindNodeAtDepth0215fff4Pvii(void* obj, int limit, int idx);
extern "C" short _Z20ApplyHPDelta0215a16cPviiPs(void* unused, int id, int delta, short* outApplied);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* ctx);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct EffectWords_021e6104* words, int effect);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    int unused, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    struct EffectWords_021e6104 words, unsigned char byteE);
extern "C" void _Z32AppendToChainAndIncCount0215fe84PvS_i(void* obj, void* node, int idx);

struct List021600f8 { char pad0[9]; unsigned char count; };
struct ListNode021600f8 { char pad0[0x18]; unsigned char depth; };
struct Depth_021e6104 { char pad0[0xc]; short value; };
struct Combatant_021e6104 {
#if defined(jpn)
 char pad0[0x144];
#else
 char pad0[0x150];
#endif
 unsigned char* ext; };
struct Skill_021e6104 { char pad0[0x10]; int flags; };
struct Obj_021e6104 {
    char pad0[4];
    struct List021600f8* list;
    void* chain;
    char padc[4];
    void* ctx;
};

static inline short CurrMP(GameObject* c) {
    short v = c->currentStats_->primaryStats.currMP;
    return v;
}

static inline unsigned short CurrHP(GameObject* c) {
    unsigned short v = c->currentStats_->primaryStats.currHP;
    return v;
}

static inline unsigned short MaxHP(GameObject* c) {
    unsigned short v = c->currentStats_->primaryStats.maxHP;
    return v;
}

static inline int IsPartySlot(int id) {
    return id >= 0 && id <= 3;
}

// JPN: func_ov024_021e699c
// USA: func_ov024_021e6104
extern "C" ARM int func_ov024_021e6104(struct Obj_021e6104* obj, int id, struct Skill_021e6104* skill) {
    GameObject* c = GetCombatantWithFlag0x100(GameState::GetInstance(), id);
    if (!c) return 0;
    if ((skill->flags & 0x400000) && IsPartySlot(id) && TestBit3At0x2f4(((struct Combatant_021e6104*)c)->ext)) {
        int total = 0;
        for (int i = 0; i < obj->list->count; i++) {
            struct ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(obj->list, i);
            if (!node) continue;
            for (int j = 0; j < node->depth; j++) {
                struct Depth_021e6104* d = (struct Depth_021e6104*)_Z23FindNodeAtDepth0215fff4Pvii(node, j, 0);
                if (d) total += d->value;
            }
        }
        int heal = total >> 2;
        if (heal > 0 && CurrHP(c) < MaxHP(c)) {
            short applied = 0;
            short hp = _Z20ApplyHPDelta0215a16cPviiPs(obj->ctx, id, heal, &applied);
            struct OutStruct0215ccbc* entry = func_ov000_0215e958(obj->ctx);
            if (!entry) return 0;
            _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->ctx, entry, 0x215);
            struct EffectWords_021e6104 words;
            words.lo = 0;
            words.hi = 0;
            func_ov000_02159eac(obj->ctx, &words, 0x25);
            _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)obj->ctx, entry, c, -applied, hp,
                CurrMP(c), words, 0);
            _Z32AppendToChainAndIncCount0215fe84PvS_i(obj->chain, entry, 3);
            ((unsigned char*)obj->ctx)[0x8e02]++;
        }
    }
    return 0;
}
