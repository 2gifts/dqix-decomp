#include <globaldefs.h>
#include "GameState/GameState.h"

struct OutStruct0215ccbc;
struct List021600f8;
struct ListNode021600f8;
struct EffectWords_021e6104 { int lo; int hi; };

int TestBit3At0x2f4_020850fc(unsigned char* obj);
struct ListNode021600f8* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
void* FindNodeAtDepth0215fff4(void* obj, int limit, int idx);
short ApplyHPDelta0215a16c(void* unused, int id, int delta, short* outApplied);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* ctx);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct EffectWords_021e6104* words, int effect);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    int unused, struct OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    struct EffectWords_021e6104 words, unsigned char byteE);
void AppendToChainAndIncCount0215fe84(void* obj, void* node, int idx);

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

static inline short CurrMP(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

static inline unsigned short CurrHP(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }

static inline unsigned short MaxHP(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.maxHP; }

static inline int IsPartySlot(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e6104
extern "C" ARM int func_ov024_021e6104(struct Obj_021e6104* obj, int id, struct Skill_021e6104* skill) {
    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), id);
    if (!c) return 0;
    if ((skill->flags & 0x400000) && IsPartySlot(id) && TestBit3At0x2f4_020850fc(((struct Combatant_021e6104*)c)->ext)) {
        int total = 0;
        for (int i = 0; i < obj->list->count; i++) {
            struct ListNode021600f8* node = GetNodeAtIndex021600f8(obj->list, i);
            if (!node) continue;
            for (int j = 0; j < node->depth; j++) {
                struct Depth_021e6104* d = (struct Depth_021e6104*)FindNodeAtDepth0215fff4(node, j, 0);
                if (d) total += d->value;
            }
        }
        int heal = total >> 2;
        if (heal > 0 && CurrHP(c) < MaxHP(c)) {
            short applied = 0;
            short hp = ApplyHPDelta0215a16c(obj->ctx, id, heal, &applied);
            struct OutStruct0215ccbc* entry = func_ov000_0215e958(obj->ctx);
            if (!entry) return 0;
            AddEntryAndIncrementCount0215a88c(obj->ctx, entry, 0x215);
            struct EffectWords_021e6104 words;
            words.lo = 0;
            words.hi = 0;
            func_ov000_02159eac(obj->ctx, &words, 0x25);
            _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)obj->ctx, entry, c, -applied, hp,
                CurrMP(c), words, 0);
            AppendToChainAndIncCount0215fe84(obj->chain, entry, 3);
            ((unsigned char*)obj->ctx)[0x8e02]++;
        }
    }
    return 0;
}
