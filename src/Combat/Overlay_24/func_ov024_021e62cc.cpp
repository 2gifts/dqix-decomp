#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct OutStruct0215ccbc;
struct List021600f8 { char pad0[9]; unsigned char count; };
struct Node_021e62cc {
    char pad0[0x14];
    unsigned char slots[3];
    unsigned char slotCount;
    unsigned char depth;
};
struct Depth_021e62cc { char pad0[0xc]; short value; };
struct Combatant_021e62cc {
    char pad0[4];
    short id;
};
struct Ally_021e62cc {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* ext;
};
struct Skill_021e62cc { char pad0[0x10]; int flags; };
struct Obj_021e62cc {
    char pad0[4];
    struct List021600f8* list;
    void* chain;
    char padc[4];
    void* ctx;
};
struct Entry_021e62cc { int id; int total; };

int IsFlag10088Set(struct S_10088* obj);
int ClassifyField0x81fe(char*);
extern "C" int func_ov000_0215ffa0(struct Node_021e62cc* node);
struct Node_021e62cc* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
struct Depth_021e62cc* FindNodeAtDepth0215fff4(void* obj, int limit, int idx);
int IsCombatantFlag2Mask8192_021e6798(GameObject* c);
int IsCombatantFlag2Mask32_021e67b0(GameObject* c);
int AnySlotHasBit17At0x2f4(unsigned char* p);
extern "C" int func_ov000_02156068(void* battle, int id, int kind, int mode);
extern "C" short func_ov000_0215a004(void* world, int id1, int id2, int value, unsigned long long* bits, struct Skill_021e62cc* rec, int a6, int a7);
extern "C" struct OutStruct0215ccbc* func_ov000_0215e958(void* world);
extern "C" int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);
void AddEntryAndIncrementCount0215a88c(void* world, void* entry, int msg);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(int unused, struct OutStruct0215ccbc* out, GameObject* combatant,
                            short valC, short valA, short valB, unsigned long long words, unsigned char byteE);
void AppendToChainAndIncCount0215fe84(void* chain, void* node, int idx);

static inline short GetCurrentMP(ModifiableCombatStats* s) {
    return s->primaryStats.currMP;
}

// USA: func_ov024_021e62cc
extern "C" ARM void func_ov024_021e62cc(struct Obj_021e62cc* self, int id, struct Skill_021e62cc* skill) {
    GameState* gs = GameState::GetInstance();
    if (ClassifyField0x81fe((char*)self->ctx) != 0) return;
    if (!(skill->flags & 0x80)) return;
    GameObject* attacker = GetCombatantByID((int)self->ctx, id);
    if (!attacker) return;
    if (IsFlag10088Set((struct S_10088*)attacker)) return;

    int count = 0;
    struct Entry_021e62cc entries[8];
    memset(entries, count, sizeof(entries));
    for (int i = 0; i < self->list->count; i++) {
        struct Node_021e62cc* node = GetNodeAtIndex021600f8(self->list, i);
        if (!node) continue;
        int found = 0;
        for (int j = 1; j < node->slotCount; j++) {
            if (node->slots[j] == 3) found = 1;
        }
        if (found) continue;
        int owner = func_ov000_0215ffa0(node);
        if (id == owner) continue;
        int dup = 0;
        for (int k = 0; k < count; k++) {
            if (owner == entries[k].id) {
                dup = 1;
                for (int d = 0; d < node->depth; d++) {
                    struct Depth_021e62cc* p = FindNodeAtDepth0215fff4(node, d, 0);
                    if (p) entries[k].total += p->value;
                }
            }
        }
        if (dup) continue;
        entries[count].id = owner;
        for (int d = 0; d < node->depth; d++) {
            struct Depth_021e62cc* p = FindNodeAtDepth0215fff4(node, d, 0);
            if (p) entries[count].total += p->value;
        }
        count++;
    }

    for (int k = 0; k < count; k++) {
        GameObject* target = GetCombatantByID((int)self->ctx, (short)entries[k].id);
        if (!target) continue;
        if (IsFlag10088Set((struct S_10088*)target)) continue;
        if (IsCombatantFlag2Mask8192_021e6798(target)) continue;
        if (entries[k].total <= 0) continue;
        float rate = 0.25f;
        int party = 0;
        if (entries[k].id >= 0 && entries[k].id <= 3) party = 1;
        if (party) {
            GameObject* ally = GetCombatantWithFlag0x100(gs, entries[k].id);
            if (!ally) continue;
            struct Random* rnd = (struct Random*)self->ctx;
            int ok = 0;
            if (IsCombatantFlag2Mask32_021e67b0(ally)) {
                rate = 0.25f;
                ok = 1;
            } else if (AnySlotHasBit17At0x2f4(((struct Ally_021e62cc*)ally)->ext)) {
                if (NextRandomMax(rnd, 100) < 50) {
                    rate = 0.2f;
                    ok = 1;
                }
            }
            if (!ok) continue;
        } else {
            if (!IsCombatantFlag2Mask32_021e67b0(target)) continue;
        }
        int dmg = rate * entries[k].total;
        if (func_ov000_02156068(self->ctx, id, 0, 1)) {
            dmg = NextRandomMax((struct Random*)self->ctx, 2);
        }
        if (dmg <= 0) continue;
        unsigned long long bits = 0;
        short result = func_ov000_0215a004(self->ctx, ((struct Combatant_021e62cc*)target)->id, id, dmg, &bits, skill, 0, 0);
        struct OutStruct0215ccbc* entry = func_ov000_0215e958(self->ctx);
        if (!entry) return;
        AddEntryAndIncrementCount0215a88c(self->ctx, entry, SelectByIndexRange0to3_021da644(id, 0x1b4, 0x22b));
        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)self->ctx, entry, attacker, dmg, result, GetCurrentMP(attacker->currentStats_), bits, 0);
        AppendToChainAndIncCount0215fe84(self->chain, entry, 4);
        ((unsigned char*)self->ctx)[0x8e02]++;
        if (func_ov000_02159f18(self->ctx, bits, 2)) {
            entry = func_ov000_0215e958(self->ctx);
            if (!entry) return;
            AddEntryAndIncrementCount0215a88c(self->ctx, entry, SelectByIndexRange0to3_021da644(id, 0x1b3, 0x22a));
            _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih((int)self->ctx, entry, attacker, 0, result, GetCurrentMP(attacker->currentStats_), 0, 0);
            AppendToChainAndIncCount0215fe84(self->chain, entry, 4);
            ((unsigned char*)self->ctx)[0x8e02]++;
        }
        if (func_ov000_02159f18(self->ctx, bits, 2)) return;
    }
}
