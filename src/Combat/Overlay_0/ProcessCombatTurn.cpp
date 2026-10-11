#include <globaldefs.h>

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

extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" Combatant* _ZN9GameState19GetCombatantByIndexEi(void* gs, int id);
extern "C" char* _Z15GetData02108e10v(void);
extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
extern "C" void _Z21UpdateCombatantAttackii(void* self, int id);
extern "C" void _Z22UpdateCombatantDefenseii(void* self, int id);
extern "C" void _Z22UpdateCombatantAgilityii(void* self, int id);
extern "C" void _Z20UpdateCombatantCharmii(void* self, int id);
extern "C" void _Z27UpdateCombatantMagicalMightii(void* self, int id);
extern "C" void _Z29UpdateCombatantMagicalMendingii(void* self, int id);
extern "C" void _Z24ClearData4Bytes_021f67f8v(void);
extern "C" void __clear(void* buf, int n);
extern "C" int _Z13NextRandomMaxP6Randomi(void* rng, int max);
extern "C" int _Z19ClassifyField0x81fePc(void* self);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void* rng, float lo, float hi);
extern "C" void func_020749ac(void* arr, int lo, int hi, int mode);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* alloc, unsigned int size);
extern "C" void _ZN13SafeAllocator4FreeEPv(void* alloc, void* p);
extern "C" Combatant* _Z25GetCombatantWithFlag0x100P9GameStatei(void* gs, int id);
extern "C" Combatant* _Z25GetCombatantWithFlag0x400P9GameStatei(void* gs, int id);
extern "C" PartyInfo* _Z19GetField0x19cOrNullP9S02053dc0(Combatant* c);
extern "C" void func_020dc548(signed char id, signed char* out, signed char* count);
extern "C" void _Z18InitStruct02160030Pv(void* obj);
extern "C" void _Z18ResetEntry02157d14P11Obj02157d14(ActionEntry* e);
extern "C" void _Z19ResetStruct02157cdcPv(void* obj);
extern "C" int func_ov000_02155f9c(void* self, int id, int checkSub);
extern "C" void func_ov024_021f73b8(Big* b);
extern "C" void func_ov024_021f9030(Big* b, void* self, int id, ActionNode* node);
extern "C" int _Z30GetCombatantField0x148Bits3To4ii(void* self, int id);
extern "C" void _Z16ClearInt0208a910Pi(int* out);
extern "C" int func_0208a91c(int* p0, void* self, int id, int* outCount, short* outTargets);
extern "C" SkillData* _Z24SearchBothTables02079e2cPci(char* data, int id);
extern "C" void* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(void* container, int key);
extern "C" void _Z29ReplaceEntryAndFormat0204887cP11Obj0204887cPc(Combatant* c, void* e);
extern "C" void _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(ActionNode* obj, TargetNode* node);
extern "C" void _Z18AppendNode02160068P11Obj02160068P12Node02160068(ActionNode* obj, ActionEntry* node);
extern "C" int func_ov000_0215f57c(void* self, int id);
extern "C" void _Z29ProcessCombatEntries_0215f110Pc(void* self);
extern "C" void func_ov000_0215f1ac(void* self);
extern "C" int _Z14IsFlag10088SetP7S_10088(Combatant* c);
extern "C" int _Z22IsFlag0x18Bit0x2000SetP10GameObject(Combatant* c);
extern "C" int _Z31IsCombatantModStatsFlag0x100SetP10GameObject(Combatant* c);
extern "C" ActionNode* _Z25GetWorkArrayEntry0215e9d8Pv(void* self);
extern "C" ActionEntry* _Z28GetTableEntry0x8e00Bound0x48Pv(void* self);
extern "C" TargetNode* _Z22GetNodeAtIndex021600f8P12List021600f8i(ActionNode* list, int index);
extern "C" ActionEntry* _Z22GetNodeAtIndex02160094P12List02160094i(ActionNode* list, int index);
extern "C" void func_ov000_0215767c(void* self, ActionNode* src, ActionNode* dst);
extern "C" void _Z19InitStruct_021eb510Pv(Sim* s);
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
    return _Z25GetCombatantWithFlag0x400P9GameStatei(bs, id);
}

// JPN: func_ov000_0215edbc
// USA: func_ov000_0215d63c
extern "C" ARM void ProcessCombatTurn(Battle* self, SafeAllocator* alloc) {
    long j;
    void* gs = _ZN9GameState11GetInstanceEv();
    char* data = _Z15GetData02108e10v();
    IdList ids = data_ov000_02182d34;
    long count = func_ov000_02153e40(self, ids.v, 0x10, 1);

    for (long i = 0; i < count; i++) {
        int id = ids.v[i];
        _Z21UpdateCombatantAttackii(self, id);
        _Z22UpdateCombatantDefenseii(self, id);
        _Z22UpdateCombatantAgilityii(self, id);
        _Z20UpdateCombatantCharmii(self, id);
        _Z27UpdateCombatantMagicalMightii(self, id);
        _Z29UpdateCombatantMagicalMendingii(self, id);
    }

    _Z24ClearData4Bytes_021f67f8v();

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
                if (n != 0 && _Z13NextRandomMaxP6Randomi(self, 100) >= 0x43) {
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
        if (_Z19ClassifyField0x81fePc(self) != 0) {
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
        cands[n].weight = (float)power * _Z22NextRandomFloatBetweenP6Randomff(self, 0.51f, 1.0f);
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
            Combatant* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = _Z19GetField0x19cOrNullP9S02053dc0(c);
                if (info != 0 && (info->flags & 1)) {
                    PartyList members = data_ov000_02182a60;
                    signed char partyCount = 0;
                    func_020dc548(ids.v[i], members.v, &partyCount);
                    for (unsigned int j = 0; j < partyCount; j++) {
                        Combatant* m = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, members.v[j]);
                        if (m != 0) {
                            PartyInfo* mi = _Z19GetField0x19cOrNullP9S02053dc0(m);
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
        _Z18InitStruct02160030Pv(node);
        node->entryCount = 1;
        node->entry = &self->entries[self->entryCount];
        _Z18ResetEntry02157d14P11Obj02157d14(node->entry);
        node->entry->id = ids.v[i];

        TargetList targets = data_ov000_02182ba4;
        int numTargets = 0;
        int party = 0;
        if (ids.v[i] >= 0 && ids.v[i] <= 3) {
            party = 1;
        }
        if (party) {
            Combatant* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = _Z19GetField0x19cOrNullP9S02053dc0(c);
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
                Combatant* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, ids.v[i]);
                if (c != 0) {
                    PartyInfo* info = _Z19GetField0x19cOrNullP9S02053dc0(c);
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
                int kind = _Z30GetCombatantField0x148Bits3To4ii(self, (short)node->entry->id);
                int selfId = (short)node->entry->id;
                Combatant* me = GetFlagged0x400(selfId);
                if (kind != 2) {
                    int work;
                    _Z16ClearInt0208a910Pi(&work);
                    node->action = func_0208a91c(&work, self, (unsigned short)node->entry->id, &numTargets, targets.v);
                    SkillData* sk = _Z24SearchBothTables02079e2cPci(data, (short)node->action);
                    if (sk != 0) {
                        while (sk->type == 0x22) {
                            void* e = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(self->field8e18 + 0x684, sk->linked);
                            if (e != 0) {
                                _Z29ReplaceEntryAndFormat0204887cP11Obj0204887cPc(me, e);
                                me->stats->skill36 = sk->linked;
                            }
                            memset(targets.v, -1, sizeof(targets));
                            numTargets = 0;
                            node->action = func_0208a91c(&work, self, (unsigned short)node->entry->id, &numTargets, targets.v);
                            sk = _Z24SearchBothTables02079e2cPci(data, (short)node->action);
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
            _Z19ResetStruct02157cdcPv(tn);
            tn->id = targets.v[j];
            tn->active = 1;
            _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(node, tn);
            self->targetCount++;
        }
        self->actionCount++;
        self->entryCount++;

        int extra = func_ov000_0215f57c(self, ids.v[i]);
        for (int k = 0; k < extra; k++) {
            ActionNode* node2 = &self->actions[self->actionCount];
            _Z18InitStruct02160030Pv(node2);
            node2->entryCount = 1;
            node2->entry = &self->entries[self->entryCount];
            _Z18ResetEntry02157d14P11Obj02157d14(node2->entry);
            node2->entry->id = ids.v[i];

            TargetList targets2 = data_ov000_02182b04;
            int numTargets2 = 0;
            if (func_ov000_02155f9c(self, ids.v[i], 1) != 0) {
                node2->action = 0x1f7;
            } else {
                node2->action = 2;
                int kind = _Z30GetCombatantField0x148Bits3To4ii(self, (short)node2->entry->id);
                Combatant* me = _Z25GetCombatantWithFlag0x400P9GameStatei(gs, node2->entry->id);
                if (kind != 2) {
                    int work2;
                    _Z16ClearInt0208a910Pi(&work2);
                    node2->action = func_0208a91c(&work2, self, (unsigned short)node2->entry->id, &numTargets2, targets2.v);
                    SkillData* sk = _Z24SearchBothTables02079e2cPci(data, (short)node2->action);
                    if (sk != 0) {
                        while (sk->type == 0x22) {
                            void* e = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(self->field8e18 + 0x684, sk->linked);
                            if (e != 0) {
                                _Z29ReplaceEntryAndFormat0204887cP11Obj0204887cPc(me, e);
                                me->stats->skill36 = sk->linked;
                            }
                            memset(targets2.v, -1, sizeof(targets2));
                            numTargets2 = 0;
                            node2->action = func_0208a91c(&work2, self, (unsigned short)node2->entry->id, &numTargets2, targets2.v);
                            sk = _Z24SearchBothTables02079e2cPci(data, (short)node2->action);
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
                _Z19ResetStruct02157cdcPv(tn);
                tn->id = targets2.v[j];
                tn->active = 1;
                _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(node2, tn);
                self->targetCount++;
            }
            self->actionCount++;
            self->entryCount++;
        }
    }

    _Z29ProcessCombatEntries_0215f110Pc(self);
    func_ov000_0215f1ac(self);

    for (j = 0; j < self->actionCount; j++) {
        ActionNode* node = &self->actions[j];
        int id = (short)node->entry->id;
        Combatant* c = GetCombatant(id);
        if (c == 0) {
            continue;
        }
        if (_Z14IsFlag10088SetP7S_10088(c) != 0) {
            continue;
        }
        if (c->stats->flag2) {
            continue;
        }
        if (_Z22IsFlag0x18Bit0x2000SetP10GameObject(c) != 0) {
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

        int modFlag = _Z31IsCombatantModStatsFlag0x100SetP10GameObject(c);
        ActionNode* w = _Z25GetWorkArrayEntry0215e9d8Pv(self);
        if (w == 0) {
            break;
        }
        _Z18InitStruct02160030Pv(w);
        func_ov000_0215767c(self, node, w);
        Sim sim;
        _Z19InitStruct_021eb510Pv(&sim);
        _Z19InitStruct_021eb510Pv(&sim);
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

        SkillData* sk = _Z24SearchBothTables02079e2cPci(_Z15GetData02108e10v(), (short)w->action);
        int again = 1;
        if (sk != 0 && (sk->flags & 0x400) && sk->kind != 0x1c) {
            ActionNode* echo = &self->actions[0x47];
            ActionNode* w2 = _Z25GetWorkArrayEntry0215e9d8Pv(self);
            if (w2 != 0) {
                _Z18InitStruct02160030Pv(w2);
                _Z18InitStruct02160030Pv(echo);
                w2->action = echo->action = w->action;
                for (int j = 0; j < w->targetCount; j++) {
                    TargetNode* src = _Z22GetNodeAtIndex021600f8P12List021600f8i(w, j);
                    int srcId = src->id;
                    Combatant* t = GetCombatant(srcId);
                    if (t == 0) {
                        continue;
                    }
                    if (_Z14IsFlag10088SetP7S_10088(t) != 0) {
                        continue;
                    }
                    if (_Z22IsFlag0x18Bit0x2000SetP10GameObject(t) != 0) {
                        break;
                    }
                    TargetNode* tn = &self->targets[self->targetCount];
                    _Z19ResetStruct02157cdcPv(tn);
                    tn->id = src->id;
                    tn->active = 1;
                    _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(echo, tn);
                    self->targetCount++;
                }
                for (int k = 0; k < w->entryCount; k++) {
                    ActionEntry* src = _Z22GetNodeAtIndex02160094P12List02160094i(w, k);
                    int srcId = (short)src->id;
                    Combatant* t = GetCombatant(srcId);
                    if (t == 0) {
                        break;
                    }
                    if (_Z14IsFlag10088SetP7S_10088(t) != 0) {
                        break;
                    }
                    if (_Z22IsFlag0x18Bit0x2000SetP10GameObject(t) != 0) {
                        break;
                    }
                    ActionEntry* e = _Z28GetTableEntry0x8e00Bound0x48Pv(self);
                    if (e == 0) {
                        break;
                    }
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->f30 = 0;
                    e->id = src->id;
                    _Z18AppendNode02160068P11Obj02160068P12Node02160068(w2, e);
                    self->tableCount++;
                    e = &self->entries[self->entryCount];
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->f30 = 0;
                    e->id = src->id;
                    _Z18AppendNode02160068P11Obj02160068P12Node02160068(echo, e);
                    self->entryCount++;
                }
                if (echo->targetCount != 0 && w->entryCount == w2->entryCount) {
                    again = 0;
                    Sim sim2;
                    _Z19InitStruct_021eb510Pv(&sim2);
                    _Z19InitStruct_021eb510Pv(&sim2);
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
