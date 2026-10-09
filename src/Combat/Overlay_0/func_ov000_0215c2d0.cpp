#include <globaldefs.h>
#include "GameState/GameState.h"

struct ResultEntry {
    char pad0[0x20];
    int f20;
};

struct ActionEntry {
    char pad0[4];
    int f4;
    char pad8[0x1c - 8];
    short f1c;
    short f1e;
    unsigned short id;
    char pad22[0x27 - 0x22];
    unsigned char hits;
    char pad28[0x30 - 0x28];
    int f30;
};

struct TargetNode {
    char pad0[0xe];
    short id;
    char pad10[0x17 - 0x10];
    unsigned char active;
};

struct ActionNode {
    unsigned short action;
    char pad2[6];
    unsigned char entryCount;
    unsigned char targetCount;
    char pada;
    unsigned char flags;
};

struct Battle {
    char pad0[0x8e00];
    unsigned char tableCount;
    unsigned char targetCount;
    unsigned char resultCount;
    char pad8e03[0x8e24 - 0x8e03];
    int workCount;
};

extern "C" ActionEntry* _Z22GetNodeAtIndex02160094P12List02160094i(ActionNode* list, int index);
extern "C" ActionNode* _Z25GetWorkArrayEntry0215e9d8Pv(void* self);
extern "C" ActionEntry* _Z28GetTableEntry0x8e00Bound0x48Pv(void* self);
extern "C" TargetNode* _Z28GetTableEntry0x8e01Bound0x88Pv(void* self);
extern "C" void _Z18InitStruct02160030Pv(void* obj);
extern "C" void _Z19ResetStruct02157cdcPv(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void _Z18AppendNode02160068P11Obj02160068P12Node02160068(ActionNode* obj, ActionEntry* node);
extern "C" void _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(ActionNode* obj, TargetNode* node);
extern "C" ResultEntry* func_ov000_0215e958(void* self);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    void* self, ResultEntry* out, GameObject* combatant, short valC, short valA, short valB,
    int wordC, int wordD, unsigned char byteE);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void* node, void* entry, int v);

static inline GameObject* GetCombatant(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

static inline short CurrHP(GameObject* c) { short v = c->currentStats_->primaryStats.currHP; return v; }
static inline short CurrMP(GameObject* c) { short v = c->currentStats_->primaryStats.currMP; return v; }

// USA: func_ov000_0215c2d0
extern "C" ARM void func_ov000_0215c2d0(Battle* self, ActionNode* src) {
    for (int i = 0; i < src->entryCount; i++) {
        ActionEntry* e = _Z22GetNodeAtIndex02160094P12List02160094i(src, i);
        if (e == 0) {
            continue;
        }
        GameObject* c = GetCombatant((short)e->id);
        if (c == 0) {
            continue;
        }
        int hits = e->hits;
        if (hits <= 0) {
            continue;
        }
        ActionNode* work = _Z25GetWorkArrayEntry0215e9d8Pv(self);
        if (work == 0) {
            continue;
        }
        _Z18InitStruct02160030Pv(work);
        ActionEntry* entry = _Z28GetTableEntry0x8e00Bound0x48Pv(self);
        if (entry == 0) {
            continue;
        }
        memset(entry, 0, 0x30);
        entry->f1c = -1;
        entry->f30 = 0;
        TargetNode* tn = _Z28GetTableEntry0x8e01Bound0x88Pv(self);
        if (tn == 0) {
            continue;
        }
        _Z19ResetStruct02157cdcPv(tn);
        ResultEntry* out = func_ov000_0215e958(self);
        if (out == 0) {
            continue;
        }
        memset(out, 0, 0x20);
        out->f20 = 0;
        work->action = 0x3b0;
        memcpy(entry, e, sizeof(ActionEntry));
        e->f4 = 0;
        e->hits = 0;
        e->f1c = -1;
        e->f1e = 0;
        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
            self, out, c, 0, CurrHP(c), CurrMP(c), 0, 0, 0);
        tn->id = e->id;
        tn->active = 1;
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(tn, out, 0);
        work->flags |= 4;
        _Z18AppendNode02160068P11Obj02160068P12Node02160068(work, entry);
        _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(work, tn);
        self->workCount++;
        self->tableCount++;
        self->targetCount++;
        self->resultCount++;
    }
}
