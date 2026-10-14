#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct CombatStats {
    char pad0[0xc];
    unsigned short power;
    char pad1[0x2a - 0xe];
    short target2a;
    short target2c;
    char pad2[0x36 - 0x2e];
    short skill36;
    char pad3[0x3b - 0x38];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
};

struct Combatant {
    char pad0[0x138];
    CombatStats* stats;
    char pad1[0x184 - 0x13c];
    unsigned char busy;
};

struct ActionEntry {
    char pad0[0x1c];
    short f1c;
    short pad1e;
    unsigned short id;
    char pad22[0x30 - 0x22];
    int f30;
};

struct TargetNode {
    char pad0[0xe];
    short id;
    char pad10[0x17 - 0x10];
    unsigned char active;
    char pad18[0x24 - 0x18];
};

struct ActionNode {
    unsigned short action;
    char pad2[6];
    unsigned char entryCount;
    unsigned char targetCount;
    char pada[6];
    ActionEntry* entry;
    char pad14[0x28 - 0x14];
};

struct SkillData {
    char pad0[4];
    unsigned int kind : 12;
    char pad8[0x10 - 8];
    unsigned int flags;
    char pad14[0x18 - 0x14];
    unsigned int lo18 : 5;
    unsigned int type : 7;
    char pad1c[0x30 - 0x1c];
    short linked;
};

struct PartyInfo {
    unsigned short action;
    unsigned char target;
    char pad3;
    unsigned char flags;
};

struct Battle {
    char pad0[0x8e00];
    unsigned char tableCount;
    char pad8e01[0x8e14 - 0x8e01];
    signed char aborted;
    char pad8e15[0x8e18 - 0x8e15];
    char* field8e18;
    char pad8e1c[4];
    int field8e20;
    int workCount;
    char pad8e28[0x8e49 - 0x8e28];
    unsigned char mode;
    char pad8e4a[0x8e70 - 0x8e4a];
    ActionEntry* entries;
    TargetNode* targets;
    ActionNode* actions;
    int actionCount;
    unsigned char entryCount;
    unsigned char targetCount;
};

struct IdList { short v[16]; };
struct TargetList { short v[8]; };
struct PartyList { signed char v[4]; };
struct Candidate { int id; float weight; };
struct Sim { char buf[0x7c]; };
struct Big { char buf[0x678]; };

extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
void UpdateCombatantAttack(int, int);
void UpdateCombatantDefense(int, int);
void UpdateCombatantAgility(int, int);
void UpdateCombatantCharm(int, int);
void UpdateCombatantMagicalMight(int, int);
void UpdateCombatantMagicalMending(int, int);
void ClearData4Bytes_021f67f8(void);
extern "C" void __clear(void* buf, int n);
struct Random;
int NextRandomMax(Random*, int);
int ClassifyField0x81fe(char*);
float NextRandomFloatBetween(Random*, float, float);
extern "C" void func_020749ac(void* arr, int lo, int hi, int mode);
extern "C" void* memset(void* dst, int c, unsigned int n);
Combatant* GetCombatantWithFlag0x400(GameState*, int);
struct S02053dc0;
PartyInfo* GetField0x19cOrNull(S02053dc0*);
extern "C" void func_020dc548(signed char id, signed char* out, signed char* count);
void InitStruct02160030(void* obj);
struct Obj02157d14;
void ResetEntry02157d14(Obj02157d14*);
void ResetStruct02157cdc(void* obj);
extern "C" int func_ov000_02155f9c(void* self, int id, int checkSub);
extern "C" void func_ov024_021f73b8(Big* b);
extern "C" void func_ov024_021f9030(Big* b, void* self, int id, ActionNode* node);
int GetCombatantField0x148Bits3To4(int, int);
void ClearInt0208a910(int* out);
extern "C" int func_0208a91c(int* p0, void* self, int id, int* outCount, short* outTargets);
SkillData* SearchBothTables02079e2c(char* data, int id);
struct Container02070e60;
void* SearchWithLow15Comparator02070fd0(Container02070e60*, int);
struct Obj0204887c;
void ReplaceEntryAndFormat0204887c(Obj0204887c*, char*);
struct Node021600cc;
struct Obj021600cc;
void AppendNode021600cc(Obj021600cc*, Node021600cc*);
struct Node02160068;
struct Obj02160068;
void AppendNode02160068(Obj02160068*, Node02160068*);
extern "C" int func_ov000_0215f57c(void* self, int id);
void ProcessCombatEntries_0215f110(char*);
extern "C" void func_ov000_0215f1ac(void* self);
struct S_10088;
int IsFlag10088Set(S_10088*);
struct GameObject;
int IsFlag0x18Bit0x2000Set(GameObject*);
int IsCombatantModStatsFlag0x100Set(GameObject*);
ActionNode* GetWorkArrayEntry0215e9d8(void* self);
ActionEntry* GetTableEntry0x8e00Bound0x48(void* self);
struct List021600f8;
TargetNode* GetNodeAtIndex021600f8(List021600f8*, int);
struct List02160094;
ActionEntry* GetNodeAtIndex02160094(List02160094*, int);
extern "C" void func_ov000_0215767c(void* self, ActionNode* src, ActionNode* dst);
void InitStruct_021eb510(void*);
extern "C" void func_ov024_021eb5d0(Sim* s, void* self, ActionNode* a, ActionNode* b, int mode);
extern "C" void func_ov000_02157d3c(void* self, ActionNode* a, int flag);
extern "C" void func_ov000_0215bf5c(void* self, ActionNode* a);
extern "C" void func_ov000_0215bbbc(void* self, ActionNode* a);
extern "C" void func_ov000_0215c2d0(void* self, ActionNode* a);
extern "C" void func_ov000_0215b278(void* self, ActionNode* a);
extern "C" void func_ov000_0215ae80(void* self);
extern "C" void func_ov000_0215b5a0(void* self, ActionNode* a);
extern "C" void func_ov000_0215ab88(void* self);
extern "C" void func_ov000_0215b198(void* self);
extern "C" void func_ov000_0215c4cc(void* self);

extern IdList data_ov000_02182d34;
extern PartyList data_ov000_02182a60;
extern TargetList data_ov000_02182ba4;
extern TargetList data_ov000_02182b04;

static inline Combatant* GetCombatant(int id) {
    GameState* bs = GameState::GetInstance();
    return (Combatant*)bs->GetCombatantByIndex(id);
}

static inline Combatant* GetFlagged0x400(int id) {
    GameState* bs = GameState::GetInstance();
    return GetCombatantWithFlag0x400((GameState*)bs, id);
}

// USA: func_ov000_0215d63c
extern "C" ARM void ProcessCombatTurn(Battle* self, SafeAllocator* alloc) {
    long j;
    void* gs = GameState::GetInstance();
    ActionDataTables* data = GetData02108e10();
    IdList ids = data_ov000_02182d34;
    long count = func_ov000_02153e40(self, ids.v, 0x10, 1);

    for (long i = 0; i < count; i++) {
        int id = ids.v[i];
        UpdateCombatantAttack((int)self, id);
        UpdateCombatantDefense((int)self, id);
        UpdateCombatantAgility((int)self, id);
        UpdateCombatantCharm((int)self, id);
        UpdateCombatantMagicalMight((int)self, id);
        UpdateCombatantMagicalMending((int)self, id);
    }

    ClearData4Bytes_021f67f8();

    Candidate cands[16];
    __clear(cands, sizeof(cands));
    unsigned char n = 0;
    for (long i = 0; i < count; i++) {
        short id = ids.v[i];
        Combatant* c = GetCombatant(id);
        if (c == 0) {
            continue;
        }
        if (self->field8e20 == 0) {
            if (self->mode == 2) {
                int party = 0;
                if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                    party = 1;
                }
                if (party) {
                    continue;
                }
                if (n != 0 && NextRandomMax((Random*)self, 100) >= 0x43) {
                    continue;
                }
            } else if (self->mode == 1) {
                int party = 0;
                if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                    party = 1;
                }
                if (!party) {
                    continue;
                }
            }
        }
        if (ClassifyField0x81fe((char*)self) != 0) {
            int id = ids.v[i];
            int party = 0;
            if (!(id < 0 || id > 3)) {
                party = 1;
            }
            if (party && id != 0) {
                continue;
            }
        }
        cands[n].id = ids.v[i];
        unsigned int power = c->stats->power;
        cands[n].weight = (float)power * NextRandomFloatBetween((Random*)self, 0.51f, 1.0f);
        n++;
    }

    count = n;
    func_020749ac(cands, 0, n - 1, 1);
    memset(&ids, 0, sizeof(ids));
    for (j = 0; j < count; j++) {
        ids.v[j] = cands[j].id;
    }

    self->entries = (ActionEntry*)alloc->Allocate(0x48 * sizeof(ActionEntry));
    self->entryCount = 0;
    self->targets = (TargetNode*)alloc->Allocate(0x88 * sizeof(TargetNode));
    self->targetCount = 0;
    self->actions = (ActionNode*)alloc->Allocate(0x48 * sizeof(ActionNode));
    self->actionCount = 0;

    for (long i = 0; i < count; i++) {
        int party = 0;
        if (ids.v[i] >= 0 && ids.v[i] <= 3) {
            party = 1;
        }
        if (party) {
            Combatant* c = (Combatant*)GetCombatantWithFlag0x100((GameState*)gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = GetField0x19cOrNull((S02053dc0*)c);
                if (info != 0 && (info->flags & 1)) {
                    PartyList members = data_ov000_02182a60;
                    signed char partyCount = 0;
                    func_020dc548(ids.v[i], members.v, &partyCount);
                    for (unsigned int j = 0; j < partyCount; j++) {
                        Combatant* m = (Combatant*)GetCombatantWithFlag0x100((GameState*)gs, members.v[j]);
                        if (m != 0) {
                            PartyInfo* mi = GetField0x19cOrNull((S02053dc0*)m);
                            if (mi != 0) {
                                mi->flags |= 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for (long i = 0; i < count; i++) {
        ActionNode* node = &self->actions[self->actionCount];
        InitStruct02160030(node);
        node->entryCount = 1;
        node->entry = &self->entries[self->entryCount];
        ResetEntry02157d14((Obj02157d14*)node->entry);
        node->entry->id = ids.v[i];

        TargetList targets = data_ov000_02182ba4;
        int numTargets = 0;
        int party = 0;
        if (ids.v[i] >= 0 && ids.v[i] <= 3) {
            party = 1;
        }
        if (party) {
            Combatant* c = (Combatant*)GetCombatantWithFlag0x100((GameState*)gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = GetField0x19cOrNull((S02053dc0*)c);
                if (info != 0 && (info->flags & 1)) {
                    continue;
                }
            }
        }

        if (func_ov000_02155f9c(self, ids.v[i], 1) != 0) {
            node->action = 0x1f7;
        } else {
            node->action = 2;
            int party = 0;
            if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                party = 1;
            }
            if (party) {
                Combatant* c = (Combatant*)GetCombatantWithFlag0x100((GameState*)gs, ids.v[i]);
                if (c != 0) {
                    PartyInfo* info = GetField0x19cOrNull((S02053dc0*)c);
                    if (info != 0) {
                        node->action = info->action;
                    }
                    if (node->action == 0) {
                        continue;
                    }
                    Big big;
                    func_ov024_021f73b8(&big);
                    func_ov024_021f9030(&big, self, ids.v[i], node);
                    if (node->action == 0x92) {
                        int target = info->target;
                        Combatant* t = GetCombatant(target);
                        if (t != 0) {
                            t->stats->target2c = ids.v[i];
                        }
                        c->stats->target2a = info->target;
                        numTargets = 1;
                        targets.v[0] = info->target;
                    }
                }
            } else {
                int kind = GetCombatantField0x148Bits3To4((int)self, (short)node->entry->id);
                int selfId = (short)node->entry->id;
                Combatant* me = GetFlagged0x400(selfId);
                if (kind != 2) {
                    int work;
                    ClearInt0208a910(&work);
                    node->action = func_0208a91c(&work, self, (unsigned short)node->entry->id, &numTargets, targets.v);
                    SkillData* sk = SearchBothTables02079e2c((char*)data, (short)node->action);
                    if (sk != 0) {
                        while (sk->type == 0x22) {
                            void* e = SearchWithLow15Comparator02070fd0((Container02070e60*)(self->field8e18 + 0x684), sk->linked);
                            if (e != 0) {
                                ReplaceEntryAndFormat0204887c((Obj0204887c*)me, (char*)e);
                                me->stats->skill36 = sk->linked;
                            }
                            memset(targets.v, -1, sizeof(targets));
                            numTargets = 0;
                            node->action = func_0208a91c(&work, self, (unsigned short)node->entry->id, &numTargets, targets.v);
                            sk = SearchBothTables02079e2c((char*)data, (short)node->action);
                            if (sk == 0) {
                                break;
                            }
                        }
                    }
                }
                if (node->action == 0x92 || node->action == 0x3a1) {
                    Combatant* t = GetCombatant(targets.v[0]);
                    if (t != 0) {
                        t->stats->target2c = ids.v[i];
                    }
                    me->stats->target2a = targets.v[0];
                }
            }
        }

        node->targetCount = 0;
        for (int j = 0; j < numTargets; j++) {
            TargetNode* tn = &self->targets[self->targetCount];
            ResetStruct02157cdc(tn);
            tn->id = targets.v[j];
            tn->active = 1;
            AppendNode021600cc((Obj021600cc*)node, (Node021600cc*)tn);
            self->targetCount++;
        }
        self->actionCount++;
        self->entryCount++;

        int extra = func_ov000_0215f57c(self, ids.v[i]);
        for (int k = 0; k < extra; k++) {
            ActionNode* node2 = &self->actions[self->actionCount];
            InitStruct02160030(node2);
            node2->entryCount = 1;
            node2->entry = &self->entries[self->entryCount];
            ResetEntry02157d14((Obj02157d14*)node2->entry);
            node2->entry->id = ids.v[i];

            TargetList targets2 = data_ov000_02182b04;
            int numTargets2 = 0;
            if (func_ov000_02155f9c(self, ids.v[i], 1) != 0) {
                node2->action = 0x1f7;
            } else {
                node2->action = 2;
                int kind = GetCombatantField0x148Bits3To4((int)self, (short)node2->entry->id);
                Combatant* me = GetCombatantWithFlag0x400((GameState*)gs, node2->entry->id);
                if (kind != 2) {
                    int work2;
                    ClearInt0208a910(&work2);
                    node2->action = func_0208a91c(&work2, self, (unsigned short)node2->entry->id, &numTargets2, targets2.v);
                    SkillData* sk = SearchBothTables02079e2c((char*)data, (short)node2->action);
                    if (sk != 0) {
                        while (sk->type == 0x22) {
                            void* e = SearchWithLow15Comparator02070fd0((Container02070e60*)(self->field8e18 + 0x684), sk->linked);
                            if (e != 0) {
                                ReplaceEntryAndFormat0204887c((Obj0204887c*)me, (char*)e);
                                me->stats->skill36 = sk->linked;
                            }
                            memset(targets2.v, -1, sizeof(targets2));
                            numTargets2 = 0;
                            node2->action = func_0208a91c(&work2, self, (unsigned short)node2->entry->id, &numTargets2, targets2.v);
                            sk = SearchBothTables02079e2c((char*)data, (short)node2->action);
                            if (sk == 0) {
                                break;
                            }
                        }
                    }
                }
                if (node2->action == 0x92 || node2->action == 0x3a1) {
                    Combatant* t = GetCombatant(targets2.v[0]);
                    if (t != 0) {
                        t->stats->target2c = node2->entry->id;
                    }
                    me->stats->target2a = targets2.v[0];
                }
            }

            node2->targetCount = 0;
            for (int j = 0; j < numTargets2; j++) {
                TargetNode* tn = &self->targets[self->targetCount];
                ResetStruct02157cdc(tn);
                tn->id = targets2.v[j];
                tn->active = 1;
                AppendNode021600cc((Obj021600cc*)node2, (Node021600cc*)tn);
                self->targetCount++;
            }
            self->actionCount++;
            self->entryCount++;
        }
    }

    ProcessCombatEntries_0215f110((char*)self);
    func_ov000_0215f1ac(self);

    for (j = 0; j < self->actionCount; j++) {
        ActionNode* node = &self->actions[j];
        int id = (short)node->entry->id;
        Combatant* c = GetCombatant(id);
        if (c == 0) {
            continue;
        }
        if (IsFlag10088Set((S_10088*)c) != 0) {
            continue;
        }
        if (c->stats->flag2) {
            continue;
        }
        if (IsFlag0x18Bit0x2000Set((GameObject*)c) != 0) {
            continue;
        }
        if (c->stats->flag0) {
            continue;
        }
        int party = (node->entry->id >= 0 && node->entry->id <= 3) ? 1 : 0;
        if (!party) {
            Combatant* m = GetFlagged0x400((short)node->entry->id);
            if (m != 0 && m->busy != 0) {
                continue;
            }
        }

        int modFlag = IsCombatantModStatsFlag0x100Set((GameObject*)c);
        ActionNode* w = GetWorkArrayEntry0215e9d8(self);
        if (w == 0) {
            break;
        }
        InitStruct02160030(w);
        func_ov000_0215767c(self, node, w);
        Sim sim;
        InitStruct_021eb510(&sim);
        InitStruct_021eb510(&sim);
        func_ov024_021eb5d0(&sim, self, w, node, 0);
        if (func_ov000_02155f9c(self, ids.v[j], 1) != 0) {
            modFlag = 0;
        }
        func_ov000_02157d3c(self, w, modFlag);
        self->workCount++;
        if (self->aborted != 0) {
            func_ov000_0215bf5c(self, w);
            func_ov000_0215bbbc(self, w);
            func_ov000_0215c2d0(self, w);
            break;
        }

        func_ov000_0215b278(self, w);
        if (modFlag == 0) {
            func_ov000_0215bf5c(self, w);
        }
        func_ov000_0215ae80(self);
        func_ov000_0215b5a0(self, w);
        func_ov000_0215ab88(self);
        func_ov000_0215b198(self);
        if (modFlag == 0) {
            func_ov000_0215bbbc(self, w);
            func_ov000_0215c2d0(self, w);
        }
        func_ov000_0215c4cc(self);
        if (modFlag == 0) {
            continue;
        }

        SkillData* sk = SearchBothTables02079e2c((char*)GetData02108e10(), (short)w->action);
        int again = 1;
        if (sk != 0 && (sk->flags & 0x400) && sk->kind != 0x1c) {
            ActionNode* echo = &self->actions[0x47];
            ActionNode* w2 = GetWorkArrayEntry0215e9d8(self);
            if (w2 != 0) {
                InitStruct02160030(w2);
                InitStruct02160030(echo);
                w2->action = echo->action = w->action;
                for (int j = 0; j < w->targetCount; j++) {
                    TargetNode* src = GetNodeAtIndex021600f8((List021600f8*)w, j);
                    int srcId = src->id;
                    Combatant* t = GetCombatant(srcId);
                    if (t == 0) {
                        continue;
                    }
                    if (IsFlag10088Set((S_10088*)t) != 0) {
                        continue;
                    }
                    if (IsFlag0x18Bit0x2000Set((GameObject*)t) != 0) {
                        break;
                    }
                    TargetNode* tn = &self->targets[self->targetCount];
                    ResetStruct02157cdc(tn);
                    tn->id = src->id;
                    tn->active = 1;
                    AppendNode021600cc((Obj021600cc*)echo, (Node021600cc*)tn);
                    self->targetCount++;
                }
                for (int k = 0; k < w->entryCount; k++) {
                    ActionEntry* src = GetNodeAtIndex02160094((List02160094*)w, k);
                    int srcId = (short)src->id;
                    Combatant* t = GetCombatant(srcId);
                    if (t == 0) {
                        break;
                    }
                    if (IsFlag10088Set((S_10088*)t) != 0) {
                        break;
                    }
                    if (IsFlag0x18Bit0x2000Set((GameObject*)t) != 0) {
                        break;
                    }
                    ActionEntry* e = GetTableEntry0x8e00Bound0x48(self);
                    if (e == 0) {
                        break;
                    }
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->f30 = 0;
                    e->id = src->id;
                    AppendNode02160068((Obj02160068*)w2, (Node02160068*)e);
                    self->tableCount++;
                    e = &self->entries[self->entryCount];
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->f30 = 0;
                    e->id = src->id;
                    AppendNode02160068((Obj02160068*)echo, (Node02160068*)e);
                    self->entryCount++;
                }
                if (echo->targetCount != 0 && w->entryCount == w2->entryCount) {
                    again = 0;
                    Sim sim2;
                    InitStruct_021eb510(&sim2);
                    InitStruct_021eb510(&sim2);
                    func_ov024_021eb5d0(&sim2, self, w2, echo, 1);
                    func_ov000_02157d3c(self, w2, 0);
                    self->workCount++;
                    if (self->aborted == 0) {
                        func_ov000_0215b278(self, w);
                    }
                    func_ov000_0215bf5c(self, w);
                    if (self->aborted == 0) {
                        func_ov000_0215ae80(self);
                        func_ov000_0215b5a0(self, w2);
                        func_ov000_0215ab88(self);
                        func_ov000_0215b198(self);
                    }
                    func_ov000_0215bbbc(self, w2);
                    func_ov000_0215c2d0(self, w2);
                    if (self->aborted == 0) {
                        func_ov000_0215c4cc(self);
                    }
                }
            }
        }
        if (again) {
            func_ov000_02157d3c(self, w, 0);
            func_ov000_0215bf5c(self, w);
            func_ov000_0215bbbc(self, w);
            func_ov000_0215c2d0(self, w);
        }
        if (self->aborted != 0) {
            break;
        }
    }

    alloc->Free(self->actions);
    alloc->Free(self->targets);
    alloc->Free(self->entries);
    self->entries = 0;
    self->entryCount = 0;
    self->targets = 0;
    self->targetCount = 0;
    self->actions = 0;
    self->actionCount = 0;
}
