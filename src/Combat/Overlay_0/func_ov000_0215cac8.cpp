#include <globaldefs.h>
#include "GameState/GameState.h"

struct OutStruct0215ccbc;

struct SkillData {
    char pad0[0x20];
    unsigned int category : 10;
};

struct ActionEntry {
    char pad0[0x1c];
    short f1c;
    short pad1e;
    unsigned short id;
    unsigned short hp;
    unsigned short mp;
    char pad26[0x30 - 0x26];
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
    char pad2[0x18 - 2];
    unsigned short category;
};

struct Battle {
    char pad0[0x8e00];
    unsigned char tableCount;
    unsigned char targetCount;
    unsigned char resultCount;
    char pad8e03[0x8e24 - 0x8e03];
    int workCount;
};

extern "C" ActionNode* _Z25GetWorkArrayEntry0215e9d8Pv(void* self);
extern "C" ActionEntry* _Z28GetTableEntry0x8e00Bound0x48Pv(void* self);
extern "C" TargetNode* _Z28GetTableEntry0x8e01Bound0x88Pv(void* self);
extern "C" void _Z18InitStruct02160030Pv(void* obj);
extern "C" void _Z19ResetStruct02157cdcPv(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" char* _Z15GetData02108e10v(void);
extern "C" SkillData* _Z24SearchBothTables02079e2cPci(char* data, int id);
extern "C" void _Z18AppendNode02160068P11Obj02160068P12Node02160068(ActionNode* obj, ActionEntry* node);
extern "C" void _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(ActionNode* obj, TargetNode* node);
extern "C" OutStruct0215ccbc* func_ov000_0215e958(void* self);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
    void* self, OutStruct0215ccbc* out, GameObject* combatant, short valC, short valA, short valB,
    int wordC, int wordD, unsigned char byteE);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void* node, void* entry, int v);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* self, void* entry, int value);

static inline GameObject* GetCombatant(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

static inline short CurrHP(GameObject* c) { short v = c->currentStats_->primaryStats.currHP; return v; }
static inline short CurrMP(GameObject* c) { short v = c->currentStats_->primaryStats.currMP; return v; }

// USA: func_ov000_0215cac8
extern "C" ARM void func_ov000_0215cac8(Battle* self, short* ids, int count, short action,
                                        unsigned short* values, unsigned char* valueCounts) {
    ActionNode* work = _Z25GetWorkArrayEntry0215e9d8Pv(self);
    ActionEntry* entry = _Z28GetTableEntry0x8e00Bound0x48Pv(self);
    if (work == 0 || entry == 0) {
        return;
    }
    _Z18InitStruct02160030Pv(work);
    memset(entry, 0, 0x30);
    entry->f1c = -1;
    entry->f30 = 0;
    work->action = action;
    SkillData* sk = _Z24SearchBothTables02079e2cPci(_Z15GetData02108e10v(), (short)work->action);
    if (sk != 0) {
        work->category = sk->category;
    }
    GameObject* c = GetCombatant(ids[0]);
    entry->id = ids[0];
    if (c != 0) {
        entry->hp = c->currentStats_->primaryStats.currHP;
        entry->mp = c->currentStats_->primaryStats.currMP;
    }
    _Z18AppendNode02160068P11Obj02160068P12Node02160068(work, entry);

    for (int i = 0; i < count; i++) {
        TargetNode* tn = _Z28GetTableEntry0x8e01Bound0x88Pv(self);
        if (tn == 0) {
            continue;
        }
        _Z19ResetStruct02157cdcPv(tn);
        GameObject* target = GetCombatant(ids[i]);
        OutStruct0215ccbc* out = func_ov000_0215e958(self);
        if (out == 0) {
            continue;
        }
        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
            self, out, target, 0, CurrHP(target), CurrMP(target), 0, 0, 0);
        tn->id = ids[i];
        tn->active = 1;
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(tn, out, 0);
        for (int j = 0; j < valueCounts[i]; j++) {
            _Z33AddEntryAndIncrementCount0215a88cPvS_i(self, out, *values++);
        }
        _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(work, tn);
        self->targetCount++;
        self->resultCount++;
    }
    self->workCount++;
    self->tableCount++;
}
