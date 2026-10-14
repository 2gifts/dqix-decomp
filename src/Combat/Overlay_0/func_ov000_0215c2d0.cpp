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

struct List02160094;
ActionEntry* GetNodeAtIndex02160094(List02160094*, int);
ActionNode* GetWorkArrayEntry0215e9d8(void* self);
ActionEntry* GetTableEntry0x8e00Bound0x48_ov000_0215e918(void* self);
TargetNode* GetTableEntry0x8e01Bound0x88_ov000_0215e938(void* self);
void InitStruct02160030(void* obj);
void ResetStruct02157cdc(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
struct Node02160068;
struct Obj02160068;
void AppendNode02160068(Obj02160068*, Node02160068*);
struct Node021600cc;
struct Obj021600cc;
void AppendNode021600cc(Obj021600cc*, Node021600cc*);
extern "C" ResultEntry* func_ov000_0215e958(void* self);
struct OutStruct0215ccbc;
void PopulateEntry_0215ccbc(int, OutStruct0215ccbc*, GameObject*, short, short, short, int, int, unsigned char);
void AppendToChainAndIncCount0215ffc4(void* node, void* entry, int v);

static inline GameObject* GetCombatant(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

static inline short CurrHP(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
static inline short CurrMP(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov000_0215c2d0
extern "C" ARM void func_ov000_0215c2d0(Battle* self, ActionNode* src) {
    for (int i = 0; i < src->entryCount; i++) {
        ActionEntry* e = GetNodeAtIndex02160094((List02160094*)src, i);
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
        ActionNode* work = GetWorkArrayEntry0215e9d8(self);
        if (work == 0) {
            continue;
        }
        InitStruct02160030(work);
        ActionEntry* entry = GetTableEntry0x8e00Bound0x48_ov000_0215e918(self);
        if (entry == 0) {
            continue;
        }
        memset(entry, 0, 0x30);
        entry->f1c = -1;
        entry->f30 = 0;
        TargetNode* tn = GetTableEntry0x8e01Bound0x88_ov000_0215e938(self);
        if (tn == 0) {
            continue;
        }
        ResetStruct02157cdc(tn);
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
        PopulateEntry_0215ccbc((int)self, (OutStruct0215ccbc*)out, c, 0, CurrHP(c), CurrMP(c), 0, 0, 0);
        tn->id = e->id;
        tn->active = 1;
        AppendToChainAndIncCount0215ffc4(tn, out, 0);
        work->flags |= 4;
        AppendNode02160068((Obj02160068*)work, (Node02160068*)entry);
        AppendNode021600cc((Obj021600cc*)work, (Node021600cc*)tn);
        self->workCount++;
        self->tableCount++;
        self->targetCount++;
        self->resultCount++;
    }
}
