#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
extern "C" struct CombatantStruct* _Z25GetCombatantWithFlag0x100P9GameStatei(struct GameState* gs, int combatantId);

class GameState {
public:
    static GameState* GetInstance();
};
struct S_10088;
struct Random;
struct S021719c0;
struct S02171698;

struct Elem_021f68c8 {
    short f0;
    char f2;
    char f3;
    float f4;
    char pad[4];
};

struct StatFlags_021f7478 {
    char pad[0x3b];
    unsigned char lo : 3;
    unsigned char hasExtraAction : 1;
};

struct MoveSet_021f7478 {
    char pad0[0x18];
    unsigned short moves[6];
    char pad24[0x48];
    unsigned char res[7];
};

struct Combatant_021f7478 {
    char pad0[2];
    short kindId;
    short id;
    char pad6[0x12e];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
#if defined(jpn)
    char pad13c[8];
    unsigned char* f150;
    struct MoveSet_021f7478* moveSet;
    char pad14c[0x30];
#else
    char pad13c[0xc];
    struct MoveSet_021f7478* moveSet;
    char pad14c[4];
    unsigned char* f150;
    char pad154[0x28];
#endif
    unsigned char side;
};

struct MoveData_021f7478 {
    int w0;
    unsigned int id : 12;
    unsigned int pad4 : 20;
    unsigned int lo8 : 8;
    unsigned int targetKind : 2;
    unsigned int pad8 : 12;
    unsigned int category : 5;
    unsigned int usable : 1;
    unsigned int pad8b : 4;
    int wc;
    unsigned int flags;
    int w14;
    unsigned int element : 5;
    unsigned int effect : 7;
    unsigned int pad18 : 20;
};

struct LearnedMove_021f7478 {
    char pad0[8];
    unsigned int lo : 19;
    unsigned int flag : 1;
    unsigned int hi : 12;
    char padc[0xa];
    unsigned short moveId;
    short uses;
};

struct Group_021f7478 {
    unsigned char b0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
    char pad2[4];
    unsigned char ids[8];
    unsigned char memberCount : 4;
    char padf[9];
};

struct PartyWork_021f7478 {
    char pad[0x25];
    unsigned char f25;
};

struct Battle_021f7478 {
    char pad[0x8e18];
    unsigned char* partyWork;
};

struct Entry_021f7478 {
    unsigned short id;
    signed char slot;
    unsigned char flag;
};

struct Obj_021f7478 {
    char* battle;
    short id;
    unsigned char mode;
    unsigned char f7;
    struct Combatant_021f7478* self;
    int total;
    unsigned char enabled[0x15];
    char pad25[3];
    const unsigned char* table;
    char pad2c[4];
    float f30;
    char pad34[0x10];
    float levelRatio[4];
    unsigned char rolls[0x15];
    unsigned char flags69[9];
    char pad72[2];
    int f74;
    int f78;
    struct Combatant_021f7478* list[8];
    int count;
    unsigned char groupSlots[3][8];
    int groupCounts[3];
    int hp[8];
    float ratio[8];
    int partyHP[4];
    float partyRatio[4];
    float f124;
    int lowest;
    int firstFlagged;
    int nLow;
    int nQuarter;
    unsigned char f138;
    unsigned char manyLow;
    char pad13a[2];
    int resMax[6];
    int resMin[6];
    int f16c;
    float f170;
    int numEntries;
    struct Entry_021f7478 entries[0x80];
    struct Elem_021f68c8 first[4];
    struct Elem_021f68c8 elems[14][4];
    void* f648;
    void* f64c;
    int f650;
    unsigned char f654;
};

extern "C" void _Z23InitElemArray4_021f68c8P13Elem_021f68c8(struct Elem_021f68c8* arr);
struct Combatant_021f7478* GetCombatantWithFlag0x400ByID(int unused, int id);
struct Combatant_021f7478* GetCombatantByID(int unused, int id);
int IsFlag10088Set(struct S_10088* obj);
extern "C" int _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(GameObject* obj);
extern "C" float func_ov024_021db358(struct Combatant_021f7478* obj);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" void __clear(void* dst, int count);
extern "C" double func_0200c578(float);
extern "C" double func_02008f5c(double);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void* func_02012fe4(void);
extern "C" int func_ov000_02159cb4(int a, int id);
void* GetActiveCombatWork(void);
extern "C" void* _Z20GetOffsetPtr02160f08Pv(void* obj);
extern "C" void* _Z25FindByKeyIndexed_021f69b4Pci(char* base, int key);
extern "C" int _Z20CountNonZero021719c0P9S021719c0(struct S021719c0* p);
extern "C" void func_ov000_0217c32c(void* p);
extern "C" int _Z20IsBitFlagSet0217c4e8Pvi(void* p, int i);
extern "C" struct MoveData_021f7478* _Z27GetBoundedField420_0217199cPvi(void* p, int i);
extern "C" int _Z20CountNonZero02171698P9S02171698(struct S02171698* p);
extern "C" struct MoveData_021f7478* _Z27GetBoundedField156_02171674Pvi(void* p, int i);
void* GetData02108e10(void);
extern "C" int func_ov000_02171bc0(void* p);
extern "C" struct LearnedMove_021f7478* _Z33GetPointerField_02171b9c_02171b9cPvi(void* p, int i);
extern "C" struct MoveData_021f7478* _Z24SearchBothTables02079e2cPci(char* p, int key);
int GetBits23To25At0x2f4(unsigned char* obj);
extern "C" char* _ZN17ActiveGrottoClass15GetDetailedDataEv(void* grotto);
extern "C" unsigned short _ZNK23DetailedTreasureMapData17LegacyBossMapData26MaybeGetCurrentAlternateIDEv(void* legacy);
extern "C" int _ZN23DetailedTreasureMapData17LegacyBossMapData17CanUseLevelUpMoveEt(void* legacy, int moveId);
float NextRandomFloat01(struct Random* rng);
int NextRandomMax(struct Random* rng, int max);
int NextRandomBetween(struct Random* rng, int lo, int hi);
float NextRandomFloatBetween(struct Random* rng, float lo, float hi);

extern unsigned char data_ov024_02200154[];
extern const signed char data_ov024_021fefb0[];
extern const unsigned char data_ov024_021ff084[];
extern const unsigned char data_ov024_021ff0d8[];
extern const unsigned char data_ov024_021ff12c[];
extern const unsigned char data_ov024_021ff180[];

static inline unsigned short GetCurrHP(struct Combatant_021f7478* c) { return c->currentStats->primaryStats.currHP; }
static inline unsigned short GetMaxHP(struct Combatant_021f7478* c) { return c->currentStats->primaryStats.maxHP; }
static inline unsigned short GetAttack(struct Combatant_021f7478* c) { return c->currentStats->primaryStats.attack; }
static inline unsigned short GetDefense(struct Combatant_021f7478* c) { return c->currentStats->primaryStats.defense; }

static inline int BlendHP(unsigned short max, unsigned short cur, float weight) {
    return (int)(0.1f * (float)cur + weight * (float)max);
}

static inline float HalfDiff(unsigned short attack, unsigned short defense) {
    return ((float)attack - (float)defense / 2.0f) / 2.0f;
}

static inline float HalfDiffInt(int attack, unsigned short defense) {
    return ((float)attack - (float)defense / 2.0f) / 2.0f;
}

// JPN: func_ov024_021f7c44
// USA: func_ov024_021f7478
extern "C" ARM void func_ov024_021f7478(struct Obj_021f7478* obj) {
#if defined(jpn)
 enum { regionalGrottoOffset=0x240c };
#else
 enum { regionalGrottoOffset=0x23ec };
#endif
    int fromMax[8];
    int blended[8];
    short bufA[4];
    short bufB[4];
    unsigned char res[6];
    int i;
    const unsigned char* table;
    unsigned char chance;
    unsigned char scale;

    obj->f170 = 0.4f;
    obj->numEntries = 0;
    _Z23InitElemArray4_021f68c8P13Elem_021f68c8(obj->first);
    for (int i = 0; i < 14; i++) {
        _Z23InitElemArray4_021f68c8P13Elem_021f68c8(obj->elems[i]);
    }

    GameState* gs = GameState::GetInstance();
    obj->self = (struct Combatant_021f7478*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, obj->id);
    memset(obj->groupCounts, 0, 0xc);

    int cnt;
    int j;
    struct Group_021f7478* groups = (struct Group_021f7478*)(obj->battle + 0x81b0);
    for (i = 0; i < groups->groupCount; i++) {
        cnt = 0;
        for (j = 0; j < groups[i].memberCount; j++) {
            struct Combatant_021f7478* c = GetCombatantWithFlag0x400ByID((int)obj->battle, (short)(groups[i].ids[j] + 0xc0));
            if (c == 0) continue;
            if (IsFlag10088Set((struct S_10088*)c)) continue;
            if (_Z33IsCombatantFlag2Mask8192_021e6798P10GameObject((GameObject*)c)) continue;
            obj->list[obj->count] = c;
            obj->groupSlots[i][cnt] = obj->count;
            obj->hp[obj->count] = c->currentStats->primaryStats.currHP;
            if (obj->mode == 0) {
                if (func_ov024_021db358(c) <= 1.0f) {
                    {
                    unsigned short cur = GetCurrHP(c);
                    unsigned short max = GetMaxHP(c);
                    obj->hp[obj->count] = (int)(0.9f * max + 0.1f * cur);
                    }
                }
            } else {
                if (func_ov024_021db358(c) <= 0.33333f) {
                    unsigned short cur = GetCurrHP(c);
                    unsigned short max = GetMaxHP(c);
                    int v = (int)(0.3f * max + 0.1f * cur);
                    if (v > obj->hp[i]) {
                        obj->hp[obj->count] = v;
                    }
                }
            }
            obj->count++;
            cnt++;
        }
        obj->groupCounts[i] = cnt;
    }

    obj->f74 = func_ov000_0215e9fc((int)obj->battle, bufA, 4, 0);
    obj->f78 = func_ov000_0215e9fc((int)obj->battle, bufB, 4, 1);

    int maxAttack = 0;
    obj->lowest = 0;
    obj->firstFlagged = -1;
    obj->manyLow = 0;
    obj->nLow = 0;
    obj->nQuarter = 0;
    for (long i = 0; i < 4; i++) {
        obj->partyRatio[i] = 1.0f;
        if (!TestBitAt0x34(((struct Battle_021f7478*)obj->battle)->partyWork, (unsigned char)i)) continue;
        struct Combatant_021f7478* c = GetCombatantByID((int)obj->battle, (short)i);
        if (c == 0) continue;
        obj->partyRatio[i] = func_ov024_021db358(c);
        obj->partyHP[i] = c->currentStats->primaryStats.currHP;
        if (IsFlag10088Set((struct S_10088*)c)) {
            if (obj->firstFlagged < 0) obj->firstFlagged = i;
            obj->partyRatio[i] = 1.0f;
            continue;
        }
        if (obj->partyRatio[i] < obj->partyRatio[obj->lowest]) obj->lowest = i;
        if (obj->partyRatio[i] <= 0.08f) obj->nLow++;
        if (obj->partyRatio[i] <= 0.25f) obj->nQuarter++;
        if (maxAttack < c->currentStats->primaryStats.attack) maxAttack = c->currentStats->primaryStats.attack;
    }
    if (obj->nQuarter >= 2) obj->manyLow = 1;

    struct Combatant_021f7478* self = (struct Combatant_021f7478*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, obj->id);
    memset(obj->ratio, 0, 0x20);
    for (int i = 0; i < obj->count; i++) {
        float v = HalfDiff(GetAttack(self), GetDefense(obj->list[i]));
        if (v < 1.0f) v = 1.0f;
        obj->ratio[i] = v;
    }

    __clear(fromMax, 0x20);
    __clear(blended, 0x20);
    for (int i = 0; i < obj->count; i++) {
        float v = HalfDiffInt(maxAttack, GetDefense(obj->list[i]));
        if (v < 1.0f) v = 1.0f;
        fromMax[i] = (int)v;
        blended[i] = (int)(((float)fromMax[i] + obj->ratio[i]) / 2.0f);
    }

    int total = 0;
    int count = obj->count;
    for (int i = 0; i < count; i++) {
        total += (int)(float)func_02008f5c(func_0200c578((float)obj->hp[i] / (0.5f + 0.9375f * (float)blended[i]))) + 1;
    }
    obj->total = total;

    GetFieldAt0x150((unsigned char*)self);
    obj->numEntries = 0;
    struct Entry_021f7478* entries = obj->entries;
    func_02012fe4();
    struct Entry_021f7478* e = &entries[obj->numEntries];
    e->id = 1;
    e->slot = -1;
    e->flag = 0;
    obj->numEntries++;

    if (((struct StatFlags_021f7478*)self->currentStats)->hasExtraAction) {
        int extra = func_ov000_02159cb4((int)obj->battle, self->id);
        if (extra != 0) {
            struct Entry_021f7478* e = &entries[obj->numEntries];
            e->id = extra;
            e->slot = -1;
            e->flag = 0;
            obj->numEntries++;
        }
    }

    void* work = _Z25FindByKeyIndexed_021f69b4Pci((char*)_Z20GetOffsetPtr02160f08Pv(GetActiveCombatWork()), obj->id);
    int n = _Z20CountNonZero021719c0P9S021719c0((struct S021719c0*)work);
    if (n > 0) {
        if (data_ov024_02200154[obj->id] == 0) {
            func_ov000_0217c32c(work);
            data_ov024_02200154[obj->id] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (!_Z20IsBitFlagSet0217c4e8Pvi(work, i)) continue;
            struct MoveData_021f7478* m = _Z27GetBoundedField420_0217199cPvi(work, i);
            if (m == 0) continue;
            if (!m->usable) continue;
            struct Entry_021f7478* e = &entries[obj->numEntries];
            e->id = m->id;
            e->slot = -1;
            e->flag = 0;
            obj->numEntries++;
            if (obj->numEntries == 0x80) return;
        }
    }

    n = _Z20CountNonZero02171698P9S02171698((struct S02171698*)work);
    for (int i = 0; i < n; i++) {
        struct MoveData_021f7478* m = _Z27GetBoundedField156_02171674Pvi(work, i);
        if (m == 0) continue;
        if (!m->usable) continue;
        struct Entry_021f7478* e = &entries[obj->numEntries];
        e->id = m->id;
        e->slot = -1;
        e->flag = 0;
        obj->numEntries++;
        if (obj->numEntries == 0x80) return;
    }

    void* moveTable = GetData02108e10();
    int n3 = func_ov000_02171bc0(work);
    for (int i = 0; i < n3; i++) {
        struct LearnedMove_021f7478* lm = _Z33GetPointerField_02171b9c_02171b9cPvi(work, i);
        if (lm == 0) continue;
        if (lm->uses <= 0) continue;
        unsigned short moveId = lm->moveId;
        if (moveId == 0) continue;
        struct MoveData_021f7478* m = _Z24SearchBothTables02079e2cPci((char*)moveTable, (short)moveId);
        if (m == 0) continue;
        if (!m->usable) continue;
        unsigned char flag = lm->flag ? 1 : 0;
        struct Entry_021f7478* e = &entries[obj->numEntries];
        e->id = moveId;
        e->slot = i;
        e->flag = flag;
        obj->numEntries++;
        if (obj->numEntries == 0x80) return;
    }

    obj->f654 = 0;
    const signed char* pair = data_ov024_021fefb0;
    self = (struct Combatant_021f7478*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, obj->id);
    if (self != 0) {
        for (; pair[0] != -1; pair += 2) {
            if (pair[1] == GetBits23To25At0x2f4(self->f150)) {
                obj->f654 = pair[0];
                break;
            }
        }
    }

    if (obj->f7 != 0) return;

    memset(obj->flags69, 0, 9);
    for (int i = 1; i <= 5; i++) {
        obj->resMin[i] = 0xff;
        obj->resMax[i] = 0;
    }

    void* moveTable2 = GetData02108e10();
    for (int i = 0; i < obj->count; i++) {
        struct Combatant_021f7478* c = obj->list[i];
        int side = c->side;
        if (side < 0) continue;
        if (side >= 3) continue;
        if (c->moveSet == 0) continue;
        struct MoveSet_021f7478* set = c->moveSet;
        for (int j = 0; j < 6; j++) {
            unsigned short moveId = set->moves[j];
            if (IsGlobalU16InRange(gs) && ((struct PartyWork_021f7478*)((struct Battle_021f7478*)obj->battle)->partyWork)->f25 != 0) {
                char* detail = _ZN17ActiveGrottoClass15GetDetailedDataEv((char*)func_02012fe4() + regionalGrottoOffset);
                short kindId = c->kindId;
                unsigned short alt = _ZNK23DetailedTreasureMapData17LegacyBossMapData26MaybeGetCurrentAlternateIDEv(detail + 0x4c);
                if (alt == kindId) {
                    if (!_ZN23DetailedTreasureMapData17LegacyBossMapData17CanUseLevelUpMoveEt(detail + 0x4c, moveId)) continue;
                }
            }
            struct MoveData_021f7478* m = _Z24SearchBothTables02079e2cPci((char*)moveTable2, (short)moveId);
            if (m == 0) continue;
            if (m->flags & 1) obj->flags69[3] = 1;
            if (m->targetKind == 1 || m->targetKind == 3) {
                if (m->flags & 0x400) {
                    if (m->effect == 1) obj->flags69[2] = 1;
                }
            }
            if (m->flags & 4) {
                obj->flags69[4] = 1;
                if (m->effect == 1) obj->flags69[5] = 1;
            }
            if (m->category == 1) obj->flags69[6] = 1;
            if (m->category == 2) obj->flags69[7] = 1;
            if (m->effect == 0x11 || m->element == 0x14 || m->effect == 0x23) obj->flags69[8] = 1;
        }
        res[1] = set->res[0];
        res[2] = set->res[1];
        res[3] = set->res[3] > set->res[2] ? set->res[3] : set->res[2];
        res[4] = set->res[5] > set->res[4] ? set->res[5] : set->res[4];
        res[5] = set->res[6];
        for (int j = 1; j <= 5; j++) {
            if (obj->resMin[j] > res[j]) obj->resMin[j] = res[j];
            if (obj->resMax[j] < res[j]) obj->resMax[j] = res[j];
        }
    }

    int maxBase = 1;
    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(((struct Battle_021f7478*)obj->battle)->partyWork, (unsigned char)i)) continue;
        struct Combatant_021f7478* c = (struct Combatant_021f7478*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, i);
        if (c == 0) continue;
        if (c->baseStats->primaryStats.attack > maxBase) maxBase = c->baseStats->primaryStats.attack;
    }
    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(((struct Battle_021f7478*)obj->battle)->partyWork, (unsigned char)i)) continue;
        struct Combatant_021f7478* c = (struct Combatant_021f7478*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, i);
        if (c == 0) continue;
        obj->levelRatio[i] = (float)c->baseStats->primaryStats.attack / (float)maxBase;
    }

    struct Random* rng = (struct Random*)obj->battle;
    NextRandomFloat01(rng);
    table = data_ov024_021ff084;
    if (obj->mode == 1 || obj->mode == 4) {
        table = data_ov024_021ff0d8;
    } else if (obj->mode == 2) {
        table = data_ov024_021ff12c;
    } else if (obj->mode == 3) {
        table = data_ov024_021ff180;
    }
    obj->table = table;
    for (i = 0; i < 0x15; i++) {
        chance = table[i * 4];
        scale = table[i * 4 + 1];
        if ((unsigned char)NextRandomMax(rng, 100) < chance) obj->enabled[i] = 1;
        if (total < scale * obj->f78 / 10) obj->enabled[i] = 0;
    }
    for (int i = 0; i < 0x15; i++) {
        obj->rolls[i] = NextRandomBetween(rng, table[i * 4 + 2], table[i * 4 + 3]);
    }
    obj->f30 = NextRandomFloatBetween(rng, 0.0f, 0.9f);
}
