#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#define func_ov000_02161bb8 func_ov000_02163324
#else
#define LOW_REGION(j,u) (u)
#endif
#include "GameState/GameState.h"

struct Container02070e60;
struct BinarySearchByComparatorStruct;
struct S_10088;
struct FieldStruct02048934;
struct Random;
struct Obj02048850;
struct Param02048850;
struct SearchStruct0202c1a4;

extern "C" void* func_0202ae18(void);
extern "C" GameObject* _Z25GetCombatantWithFlag0x400P9GameStatei(GameState* battleStruct, int combatantId);
extern "C" void __clear(void* buf, int n);
extern "C" unsigned char* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(Container02070e60* table, int key);
extern "C" Param02048850* _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(BinarySearchByComparatorStruct* table, int key);
int IsFlag10088Set(S_10088* obj);
extern "C" int func_ov000_02161bb8(unsigned char* obj);
void SetRandomizedShort0x18802048934(void* p, FieldStruct02048934* f, Random* r);
extern "C" void func_020891cc(void* obj);
extern "C" void func_02089630(void* dst, void* src, int useExactValue);
void IncrementByteCounterWrapAt0x12(unsigned char* p);
void ResetNameState02048614(unsigned char* obj);
extern "C" void func_02049c88(void* obj, void* model);
void SetupFieldsFromParam02048850(Obj02048850* obj, Param02048850* param);
void BuildName020488ec(char* obj);
void ClearSubstructByte0x56(unsigned char* obj);
extern "C" void _Z21RegisterCombatantSlotP9GameStateiP10GameObject(GameState* battleStruct, int id, GameObject* combatant);
int CheckField0NonZero(int* obj);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);

struct Stats02161380 {
    unsigned short field_0;
    unsigned short field_2;
    unsigned short field_4;
    unsigned short field_6;
    unsigned char pad_8[0x10];
    unsigned int flags;
    unsigned char pad_1c[9];
    unsigned char slot;
    unsigned char pad_26[0xa4 - 0x26];
};

struct Combatant02161380 {
    Object3D object;
    unsigned char pad_ac[0x134 - 0xac];
    unsigned char* entryData;
    Stats02161380* stats;
    unsigned char pad_13c[0xc];
    unsigned char* entry;
    unsigned char pad_14c[0x30];
    unsigned char mode;
    unsigned char pad_17d[7];
    unsigned char active;
    unsigned char pad_185;
    unsigned short kind;
    unsigned short field_188;
    unsigned short field_18a;
    unsigned char group;
    unsigned char slot;
    unsigned char pad_18e[2];
};

struct Model02161380 { unsigned char data[0x70]; };

struct Roster02161380 {
    unsigned char pad_0[0x158];
    Stats02161380 stats[8];
};

struct Group02161380 {
    unsigned short kind;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char used : 4;
    unsigned char pad_b[2];
    unsigned char names[8];
    unsigned char nameCount;
    unsigned char pad_16[2];
};

struct Pair02161380 {
    unsigned char next;
    unsigned char pad_1;
    unsigned short kind;
    unsigned int slots;
};

// second view of Formation02161380's count byte; reads through it are not CSE'd with the direct ones
struct Counts02161380 {
    unsigned char alive : 4;
    unsigned char groupCount : 2;
    unsigned char pairCount : 2;
};

struct Formation02161380 {
    unsigned char total;
    unsigned char alive : 4;
    unsigned char groupCount : 2;
    unsigned char pairCount : 2;
    unsigned char pad_2[2];
    Group02161380 groups[3];
    Pair02161380 pairs[4];
};

struct BattleData02161380 {
    unsigned char pad_0[0x81b0];
    Formation02161380 formation;
};

struct Source02161380 {
    Object3D object;
};

struct Scene02161380 {
    unsigned char pad_0[LOW_REGION(0x218,0x29c)];
    BattleData02161380* data;
    Roster02161380* roster;
    unsigned char pad_2a4[0xc14];
    Source02161380* sources[4];
    unsigned short field_ec8;
    unsigned char pad_eca[LOW_REGION(0x51ce,0x4f5a)];
    Combatant02161380 combatants[8];
    Model02161380 models[8];
};

// USA: func_ov000_02161380
extern "C" ARM int func_ov000_02161380(Scene02161380* scene, int kind, int group, int unused) {
    Container02070e60* names;
    GameState* game;
    void* search;
    BinarySearchByComparatorStruct* infos;
    int id;
    Param02048850* info;
    int pass;
    Stats02161380* stats2;
    int oldSlot;
    unsigned short v0;
    Stats02161380* stats;
    int slot;
    unsigned char* entry;
    Combatant02161380* c;
    int start;
    Combatant02161380* nc;
    Formation02161380* f;
    f = &scene->data->formation;
    int limit = 5;
    if (kind == 0x10a) limit = 8;
    if (limit <= f->alive) return -1;

    Source02161380* source = 0;
    for (int i = 0; i < 4; i++) {
        Source02161380* candidate = scene->sources[i];
        if (candidate && kind == candidate->object.unknown_2_) {
            source = candidate;
            break;
        }
    }
    if (!source) return -1;

    game = GameState::GetInstance();
    search = func_0202ae18();
    names = (Container02070e60*)((unsigned char*)scene->roster + 0x684);
    infos = (BinarySearchByComparatorStruct*)((unsigned char*)scene->roster + 0x678);
    id = -1;
    for (int i = 0; i < 8; i++) {
        if (_Z25GetCombatantWithFlag0x400P9GameStatei(game, i + 0xc0) == 0) {
            id = (short)(i + 0xc0);
            break;
        }
    }

    int found = 0;
    int pair = -1;
    if (group < 0) {
        for (int g = 0; g < f->groupCount; g++) {
            if (kind == f->groups[g].kind) {
                group = g;
                found = 1;
                break;
            }
        }
    } else {
        found = 1;
    }

    if (!found) {
        if (f->groupCount >= 3) {
            int g;
            for (g = 0; g < ((Counts02161380*)((unsigned char*)f + 1))->groupCount; g++) {
                if (f->groups[g].used == 0) {
                    group = g;
                    break;
                }
            }
            if (g >= 3) return -1;
            for (int p = 0; p < f->pairCount; p++) {
                if (kind == f->pairs[p].kind) {
                    pair = p;
                    break;
                }
            }
            if (pair <= -1) {
                unsigned int count = ((Counts02161380*)((unsigned char*)f + 1))->pairCount;
                if (count >= 4) return -1;
                pair = count;
                f->pairCount = pair + 1;
                memset(&f->pairs[pair], 0, sizeof(Pair02161380));
                f->pairs[pair].kind = kind;
                f->pairs[pair].next = 1;
            }
            start = 0;
            if (id < 0) {
                id = (short)(f->groups[group].ids[0] + 0xc0);
                start = 1;
            }
            unsigned char buf[8];
            __clear(buf, 8);
            unsigned char n = 0;
            for (; start < f->groups[group].count; start++) {
                buf[n++] = f->groups[group].ids[start];
            }
            memset(&f->groups[group], 0, sizeof(Group02161380));
            f->groups[group].kind = kind;
            memcpy(f->groups[group].names, buf, 8);
            f->groups[group].nameCount = n;
        } else {
            group = f->groupCount;
            pair = f->pairCount;
            f->groupCount = group + 1;
            f->pairCount++;
            memset(&f->groups[group], 0, sizeof(Group02161380));
            memset(&f->pairs[pair], 0, sizeof(Pair02161380));
            unsigned short k = kind;
            f->groups[group].kind = k;
            f->pairs[pair].kind = k;
            f->pairs[pair].next = 1;
        }
    } else {
        for (int p = 0; p < f->pairCount; p++) {
            if (f->pairs[p].kind == f->groups[group].kind) {
                pair = p;
                break;
            }
        }
    }

    entry = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(names, kind);
    info = _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(infos, (short)kind);
    if (!entry) return -1;
    if (!info) return -1;

    for (pass = 0; pass < 2; pass++) {
        for (int j = 0; j < f->groups[group].count; j++) {
            c = (Combatant02161380*)_Z25GetCombatantWithFlag0x400P9GameStatei(game, f->groups[group].ids[j] + 0xc0);
            if (!c) continue;
            unsigned char flags[2];
            flags[0] = (c->stats->flags & 0x2000) != 0;
            flags[1] = IsFlag10088Set((S_10088*)c);
            if (flags[pass] == 0) continue;
            if (c->active != 0) continue;

            f->groups[group].used++;
            f->alive++;
            oldSlot = c->stats->slot;
            slot = func_ov000_02161bb8((unsigned char*)&f->pairs[pair]);
            SetRandomizedShort0x18802048934(c, (FieldStruct02048934*)entry, (Random*)scene->data);
            v0 = c->field_188;
            unsigned short v2 = c->field_18a;
            stats = c->stats;
            func_020891cc(stats);
            func_02089630(stats, entry + 0x2c, 0);
            c->stats->field_0 = v0;
            c->stats->field_4 = v0;
            c->stats->field_2 = v2;
            c->stats->field_6 = v2;
            c->kind = kind;
            c->group = group;
            c->slot = slot;
            c->active = 1;
            f->pairs[pair].slots |= 1 << c->slot;
            IncrementByteCounterWrapAt0x12((unsigned char*)&f->pairs[pair]);
            f->pairs[pair].slots &= ~(1 << oldSlot);
            return (short)(f->groups[group].ids[j] + 0xc0);
        }
    }

    if (id >= 0xc0) {
        int index = id - 0xc0;
        stats2 = &scene->roster->stats[index];
        nc = &scene->combatants[index];
        func_020891cc(stats2);
        if (nc) {
            ResetNameState02048614((unsigned char*)nc);
            func_02049c88(nc, &scene->models[index]);
            func_02089630(stats2, entry + 0x2c, 0);
            nc->object.SetField06(scene->field_ec8);
            nc->stats = stats2;
            nc->entryData = entry + 0x2c;
            nc->entry = entry;
            SetupFieldsFromParam02048850((Obj02048850*)nc, info);
            SetRandomizedShort0x18802048934(nc, (FieldStruct02048934*)entry, (Random*)scene->data);
            unsigned short v0 = nc->field_188;
            unsigned short v2 = nc->field_18a;
            nc->stats->field_0 = v0;
            nc->stats->field_4 = v0;
            nc->stats->field_2 = v2;
            nc->stats->field_6 = v2;
            unsigned char* slots = (unsigned char*)&f->pairs[pair];
            unsigned char slot = func_ov000_02161bb8(slots);
            if (slot == 1) slot = 0;
            nc->object.unknown_2_ = kind;
            nc->mode = group;
            nc->stats->slot = slot;
            BuildName020488ec((char*)nc);
            nc->kind = kind;
            nc->group = group;
            nc->slot = slot;
            nc->active = 1;
            nc->object.MakeHidden();
            ClearSubstructByte0x56((unsigned char*)nc);
            f->pairs[pair].slots |= 1 << nc->slot;
            IncrementByteCounterWrapAt0x12(slots);
            _Z21RegisterCombatantSlotP9GameStateiP10GameObject(game, id, (GameObject*)nc);
            f->groups[group].ids[f->groups[group].count] = index;
            f->groups[group].count++;
            f->groups[group].used++;
            f->total++;
            f->alive++;
            if (CheckField0NonZero((int*)search)) {
                GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search);
            }
            return id;
        }
    }
    return -1;
}
