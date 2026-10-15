#include <globaldefs.h>
#include "std_library_functions.h"

struct Stats {
    union { struct { short first, second; }; struct { unsigned short rawFirst, rawSecond; }; };
    char p0[0x10];
    unsigned int flags14;
    char p1[0xa];
    unsigned short pad22a : 14, pending : 1, pad22b : 1;
    unsigned char level;
};
struct GameObject { char p[0x138]; Stats* stats; int First() const { return stats->first; } int Second() const { return stats->second; } };
class GameState { public: static GameState* GetInstance(); GameObject* GetCombatantByIndex(int); };
struct List021600f8 { char p[9]; unsigned char count; };
struct Entry { char p[0xe]; short ids[4]; char q; unsigned char idCount; };
struct Node {
    char p0[0x1c]; short sentinel; char p1[2]; unsigned short id, field22, field24; char p2[0xa]; int tail;};
struct Work { unsigned short kind; char p[9]; unsigned char flags; };
struct State { char p0[0xe]; unsigned short id; char p1[7]; unsigned char flag; };
struct Out { char p[0x20]; int tail; };
struct IdList { short ids[8]; };
struct Battle { char p[0x8e00]; unsigned char count0, count1, count2; char q[0x21]; int workCount; };
struct S_10088;
struct Random;

extern "C" Entry* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8*, int);
extern "C" int _Z23IsFlag10088Set_02010088P7S_10088(S_10088*);
extern "C" int _Z37IsFlag0x18Bit0x2000Set_ov000_02153c0cP10GameObject(GameObject*);
extern "C" int _Z32CheckFlag0x14Bit0x10Set_020882f8Ph(unsigned char*);
extern "C" int _Z34IsFlag0x14Bit0x8Set_ov000_02156038P10GameObject(GameObject*);
extern "C" int _Z38IsFlag0x14Bit0x80000Set_ov000_02156050P10GameObject(GameObject*);
extern "C" int _Z36CheckField0x14FiveFlagsClear020881c4Ph(unsigned char*);
int NextRandomMax(Random*, int);
extern "C" void* _Z25GetWorkArrayEntry0215e9d8Pv(void*);
extern "C" void _Z18InitStruct02160030Pv(void*);
extern "C" void* _Z43GetTableEntry0x8e00Bound0x48_ov000_0215e918Pv(void*);
extern "C" void* _Z43GetTableEntry0x8e01Bound0x88_ov000_0215e938Pv(void*);
extern "C" void _Z19ResetStruct02157cdcPv(void*);
extern "C" void _Z33ResetAndSetFlag0x1000000_02088150Pv(void*);
extern "C" void _Z35SetFlag0x800000AndByte0x24_02088220Pvi(void*, int);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void*, void*, int);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void*, void*, int);
struct Obj02160068; struct Node02160068; struct Obj021600cc; struct Node021600cc;
extern "C" void _Z18AppendNode02160068P11Obj02160068P12Node02160068(Obj02160068*, Node02160068*);
extern "C" void _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(Obj021600cc*, Node021600cc*);
extern "C" {
Out* func_ov000_0215e958(void*);
int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void*, Out*, GameObject*, short, short, short, unsigned long long, unsigned char);
}
extern IdList data_ov000_02182be4;
extern int data_ov000_02182bf4[];

inline int IsParty(int id) { return id >= 0 && id <= 3; }

// USA: func_ov000_0215b5a0
extern "C" ARM void func_ov000_0215b5a0(Battle* self, List021600f8* list) {
    State* state;
    unsigned long long bits;
    int kind;
    IdList seen;
    long count;
    long slot;
    int i;
    Entry* entry;
    int entryId;
    int found;
    int j;
    short* ids;
    long k;
    GameState* gs;
    int id;
    Stats* stats;
    int level;
    Work* work;
    Node* copy;
    GameObject* unit;
    Out* out;
    int memberId;
    unsigned short nodeId;
    short partnerId;
    seen = data_ov000_02182be4;
    count = 0;
    for (i = 0; i < list->count; i++) {
        entry = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, i);
        if (!entry) continue;
        entryId = entry->ids[(signed char)(entry->idCount - 1)];
        found = 0;
        for (j = 0; j < count; j++) {
            if (entryId == seen.ids[j]) { found = 1; break; }
        }
        if (found) continue;
        slot = count;
        count = (short)(slot + 1);
        seen.ids[slot] = entryId;
    }
    ids = seen.ids;
    for (k = 0; k < count; k++) {
        gs = GameState::GetInstance();
        id = ids[k];
        unit = gs->GetCombatantByIndex(id);
        if (!unit) continue;
        stats = unit->stats;
        if (!stats->pending) continue;
        stats->pending = 0;
        if (_Z23IsFlag10088Set_02010088P7S_10088((S_10088*)unit)) continue;
        if (_Z37IsFlag0x18Bit0x2000Set_ov000_02153c0cP10GameObject(unit)) continue;
        if (_Z32CheckFlag0x14Bit0x10Set_020882f8Ph((unsigned char*)unit->stats)) continue;
        if (_Z34IsFlag0x14Bit0x8Set_ov000_02156038P10GameObject(unit)) continue;
        if (_Z38IsFlag0x14Bit0x80000Set_ov000_02156050P10GameObject(unit)) continue;
        if (unit->stats->flags14 & 0x1000000) continue;
        if (!_Z36CheckField0x14FiveFlagsClear020881c4Ph((unsigned char*)unit->stats)) continue;
        level = unit->stats->level;
        if (NextRandomMax((Random*)self, 100) >= data_ov000_02182bf4[level]) continue;
        work = (Work*)_Z25GetWorkArrayEntry0215e9d8Pv(self);
        if (!work) continue;
        _Z18InitStruct02160030Pv(work);
        copy = (Node*)_Z43GetTableEntry0x8e00Bound0x48_ov000_0215e918Pv(self);
        if (!copy) continue;
        memset(copy, 0, 0x30); copy->sentinel = -1; copy->tail = 0;
        state = (State*)_Z43GetTableEntry0x8e01Bound0x88_ov000_0215e938Pv(self);
        if (!state) continue;
        _Z19ResetStruct02157cdcPv(state);
        out = func_ov000_0215e958(self);
        if (!out) continue;
        memset(out, 0, 0x20); out->tail = 0;
        work->kind = 0x3a0;
        bits = 0;
        bits |= 0x1000000000ULL;
        if (level + 1 >= 4) {
            _Z33ResetAndSetFlag0x1000000_02088150Pv(unit->stats);
            bits |= 0x80ULL;
        } else {
            _Z35SetFlag0x800000AndByte0x24_02088220Pvi(unit->stats, level + 1);
        }
        kind = 0;
        switch (level + 1) {
        case 1: kind = 0x31; break;
        case 2: kind = 0x32; break;
        case 3: kind = 0x33; break;
        case 4: kind = 0x34; break;
        }
        memberId = ids[k];
        nodeId = memberId;
        copy->id = nodeId;
        copy->field22 = unit->stats->rawFirst; copy->field24 = unit->stats->rawSecond;
        {
            int second = unit->Second(); int first = unit->First();
            _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(self, out, unit, level + 1, first, second, bits, 0);
        }
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(self, out, kind);
        state->id = memberId; state->flag = 1;
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(state, out, 0);
        _Z18AppendNode02160068P11Obj02160068P12Node02160068((Obj02160068*)work, (Node02160068*)copy);
        _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc((Obj021600cc*)work, (Node021600cc*)state);
        work->flags |= 4;
        self->workCount++; self->count0++; self->count1++; self->count2++;
        if (!func_ov000_02159f18(self, bits, 7)) continue;

        work = (Work*)_Z25GetWorkArrayEntry0215e9d8Pv(self);
        if (!work) continue;
        _Z18InitStruct02160030Pv(work);
        copy = (Node*)_Z43GetTableEntry0x8e00Bound0x48_ov000_0215e918Pv(self);
        if (!copy) continue;
        memset(copy, 0, 0x30); copy->sentinel = -1; copy->tail = 0;
        state = (State*)_Z43GetTableEntry0x8e01Bound0x88_ov000_0215e938Pv(self);
        if (!state) continue;
        _Z19ResetStruct02157cdcPv(state);
        out = func_ov000_0215e958(self);
        if (!out) continue;
        memset(out, 0, 0x20); out->tail = 0;
        if (IsParty(id)) work->kind = 0x39c; else work->kind = 0x39d;
        partnerId = ids[k];
        copy->id = nodeId;
        copy->field22 = unit->stats->rawFirst; copy->field24 = unit->stats->rawSecond;
        work->flags |= 4;
        {
            int second = unit->Second(); int first = unit->First();
            _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(self, out, unit, 0, first, second, 0, 0);
        }
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(self, out, 0x35);
        state->id = partnerId; state->flag = 1;
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(state, out, 0);
        self->count2++;
        _Z18AppendNode02160068P11Obj02160068P12Node02160068((Obj02160068*)work, (Node02160068*)copy);
        _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc((Obj021600cc*)work, (Node021600cc*)state);
        self->workCount++; self->count0++; self->count1++; self->count2++;
    }
}
