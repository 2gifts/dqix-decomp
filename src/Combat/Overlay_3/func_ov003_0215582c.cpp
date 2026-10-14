#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020dedd0;
struct KeyedList0207c484;
struct Field150Holder02052e14;
struct Field150Holder02052e2c;
struct S_a06ec;
struct S_a0258;

struct ItemSlot0215582c {
    char pad0[8];
    unsigned int kind : 4;
    unsigned int rest : 28;
    char padC[0x18 - 0xc];
    short itemId;
    char pad1a[0x20 - 0x1a];
};

struct ItemFlags0215582c {
    unsigned int f0;
    unsigned int : 27;
    unsigned int allowedMale : 1;
    unsigned int allowedFemale : 1;
    unsigned int keep : 1;
    unsigned int : 2;
};

struct ItemEntry0215582c {
    struct ItemFlags0215582c* data;
};

struct EquipState0215582c {
    int f0[10];
    short id;
    short pad2a;
};

struct CombatantData0215582c {
    char pad0[0x194];
    struct ItemSlot0215582c slots[1];
    char pad1b4[0x49c - 0x1b4];
    unsigned char female : 1;
    unsigned char : 7;
    char pad49d[0x950 - 0x49d];
    int equipSet;
};

struct Stats0215582c {
    char pad0[0x2f4];
    struct EquipState0215582c equip[8];
    char pad454[0x4a4 - 0x454];
    short sets[12][8];
};

struct CurStats0215582c {
    char pad0[4];
    unsigned short hp;
    unsigned short mp;
};

struct BaseStats0215582c {
    char pad0[0x30];
    unsigned short maxHp;
    unsigned short maxMp;
};

struct Combatant0215582c {
    char pad0[4];
    short id;
    char pad6[0x130 - 6];
    struct CurStats0215582c* curStats;
    struct BaseStats0215582c* baseStats;
    char pad138[0x150 - 0x138];
    struct CombatantData0215582c* data;
};

struct Self0215582c {
    char pad0[0x90];
    char f90[0xcc - 0x90];
    char fcc[0x178 - 0xcc];
    char list[0x1f7 - 0x178];
    signed char combatantId;
    char pad1f8[0x1fc - 0x1f8];
    int flags;
    char pad200[0x330 - 0x200];
    float hpRatio;
    float mpRatio;
};

struct Word569c0215582c {
    int f0;
    int : 19;
    int id : 11;
    int : 2;
};

struct Party0215582c {
    char pad0[0x1d4];
    char bag[1];
};

void* GetPtrField0x2a04(GameState* battleStruct);
struct Stats0215582c* GetFieldAt0x150(unsigned char* obj);
int OffsetByIndexTimes16_02155e14(int base, int idx);
short* GetField150Ptr0x488(struct Field150Holder02052e14* obj);
extern "C" int func_0207c378(void* obj, int value, int amount, int key);
int GetArrayEntryByIndex_02156034(void* obj);
void SetBit0x954StoreIndex0x950(unsigned char* obj, int index);
int GetField0x3acValue(GameState* battleStruct);
int LoadBattleBlock020ac4c0(void* dst);
void AddClamped10BitFieldHighAt0x28(struct S_a06ec* p, unsigned int amount);
void AddClamped10BitFieldAt0x1c(struct S_a0258* p, unsigned int amount);
int CopyInBattleField0x7540(void* src);
extern "C" int func_0207c7a0(void* map, int value, int key);
struct ItemEntry0215582c* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
extern "C" void func_02052d7c(void* obj, int index, int value);
int DecrementKeyedStackAmount0207c484(struct KeyedList0207c484* obj, int value, int amount, int key);
short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void func_02083738(void* o, int a1);
extern "C" void func_02083cbc(void* a, void* obj, void* tail);
void SetBitInArray0x910(unsigned char* obj, int index);
extern "C" void* func_0202ae18(void);
extern "C" void func_ov017_0218f5a4(void* self, int combatantId, int flag2, int flag3, int flag4);

extern const unsigned char data_ov003_0217f2c4[];
extern const unsigned char data_ov003_0217f2b4[];
extern const unsigned char data_ov003_0217f2bc[];

static inline int IsValidKind(unsigned int kind) {
    return kind <= 7;
}

// USA: func_ov003_0215582c
extern "C" ARM void func_ov003_0215582c(struct Self0215582c* self) {
    GameState* gs = GameState::GetInstance();
    struct Party0215582c* party = (struct Party0215582c*)GetPtrField0x2a04(gs);
    struct Combatant0215582c* c = (struct Combatant0215582c*)gs->GetPartyMemberByIndex(self->combatantId);
    if (c == NULL) {
        return;
    }
    struct Stats0215582c* stats = GetFieldAt0x150((unsigned char*)c);
    if (stats == NULL) {
        return;
    }

    short (*sets)[8] = stats->sets;
    int value;
    if (self->flags & 1) {
        value = c->baseStats->maxHp;
        int hp = c->curStats->hp;
        self->hpRatio = (float)hp / (float)value;
        value = c->baseStats->maxMp;
        int mp = c->curStats->mp;
        self->mpRatio = (float)mp / (float)value;
    }

    short* set = (short*)OffsetByIndexTimes16_02155e14((int)sets, c->data->equipSet);
    short* equipped = GetField150Ptr0x488((struct Field150Holder02052e14*)c);
    if (set != NULL && equipped != NULL) {
        set[0] = equipped[7];
        set[1] = equipped[0];
        set[2] = equipped[8];
        set[3] = equipped[6];
        set[4] = equipped[4];
        set[5] = equipped[1];
        set[6] = equipped[5];
        set[7] = equipped[9];
    }

    for (unsigned short i = 0; data_ov003_0217f2c4[i] != 0xff; i++) {
        struct ItemSlot0215582c* slot = &c->data->slots[data_ov003_0217f2c4[i]];
        if (slot != NULL && IsValidKind(slot->kind)) {
            func_0207c378(party->bag, slot->itemId, 1, slot->kind);
        }
    }

    SetBit0x954StoreIndex0x950((unsigned char*)stats, GetArrayEntryByIndex_02156034(self));

    value = GetField0x3acValue(gs);
    if (value == c->id) {
        GameState* g = GameState::GetInstance();
        struct Word569c0215582c* w = (struct Word569c0215582c*)((char*)g + 0x29c + 0x5400);
        short id = w->id;
        if (id >= 700 && id < 800) {
            struct Combatant0215582c* hero = (struct Combatant0215582c*)g->GetProtagonist();
            int equipSet = hero->data->equipSet;
            int base = 20700;
            if (hero->data->female == 1) {
                base += 50;
            }
            w->id = base - 20000 + equipSet;
        }
        int buf[0x2c];
        LoadBattleBlock020ac4c0(buf);
        AddClamped10BitFieldHighAt0x28((struct S_a06ec*)buf, 1);
        AddClamped10BitFieldAt0x1c((struct S_a0258*)(buf + 0x1a), 1);
        CopyInBattleField0x7540(buf);
    }

    int unchanged = 0;
    set = (short*)OffsetByIndexTimes16_02155e14((int)sets, GetArrayEntryByIndex_02156034(self));
    if (set != NULL) {
        if (set[0] == equipped[7] && set[1] == equipped[0] && set[2] == equipped[8] && set[3] == equipped[6] &&
            set[4] == equipped[4] && set[5] == equipped[1] && set[6] == equipped[5] && set[7] == equipped[9]) {
            unchanged = 1;
        }
    }

    if (set[7] == 0x4680 && func_0207c7a0(party->bag, 0x4680, 7) == 0) {
        bool allowed[2];
        for (int i = 0; i < 7; i++) {
            struct ItemEntry0215582c* e = FindElementByKey020dedd0((struct Container020dedd0*)self->list, set[i]);
            struct ItemFlags0215582c* d;
            if (e != NULL && (d = e->data) != NULL) {
                allowed[0] = d->allowedMale;
                allowed[1] = d->allowedFemale;
                if (allowed[c->data->female] == 0) {
                    if (d->keep == 0) {
                        set[i] = -1;
                    }
                }
            }
        }
    }

    for (unsigned char k = 0; k < 8; k++) {
        int used = 0;
        int item = set[k];
        int kind = data_ov003_0217f2b4[k];
        if (item > 0 && func_0207c7a0(party->bag, item, kind) >= 1) {
            if (data_ov003_0217f2bc[k] != 0xff) {
                func_02052d7c(c, data_ov003_0217f2bc[k], item);
            }
            DecrementKeyedStackAmount0207c484((struct KeyedList0207c484*)party->bag, item, 1, kind);
            used = 1;
            if (data_ov003_0217f2bc[k] == 4) {
                short* p = GetField150Ptr0x488_02052e2c((struct Field150Holder02052e2c*)c);
                p[0xb] = -1;
                if (equipped[0] > 0) {
                    p[0xb] = equipped[0] % 1000 + 14000;
                }
            }
        }
        if (used == 0) {
            if (data_ov003_0217f2bc[k] != 0xff) {
                if (data_ov003_0217f2bc[k] == 0) {
                    GetField150Ptr0x488_02052e2c((struct Field150Holder02052e2c*)c)[0xb] = -1;
                }
                if (data_ov003_0217f2bc[k] == 4) {
                    short* p = GetField150Ptr0x488_02052e2c((struct Field150Holder02052e2c*)c);
                    p[0xb] = -1;
                    if (equipped[0] > 0) {
                        p[0xb] = equipped[0] % 1000 + 14000;
                    }
                }
                if (equipped[data_ov003_0217f2bc[k]] != -1) {
                    struct Stats0215582c* s = GetFieldAt0x150((unsigned char*)c);
                    func_02083738(s, kind);
                    s->equip[k].f0[0] = 0;
                    s->equip[k].f0[1] = 0;
                    s->equip[k].f0[2] = 0;
                    s->equip[k].f0[3] = 0;
                    s->equip[k].f0[4] = 0;
                    s->equip[k].f0[5] = 0;
                    s->equip[k].f0[6] = 0;
                    s->equip[k].f0[7] = 0;
                    s->equip[k].f0[8] = 0;
                    s->equip[k].f0[9] = 0;
                    s->equip[k].id = -1;
                }
                func_02052d7c(c, data_ov003_0217f2bc[k], -1);
            }
        }
    }

    func_02083cbc(stats, self->f90, self->fcc);
    switch (GetArrayEntryByIndex_02156034(self)) {
    case 2:
        SetBitInArray0x910((unsigned char*)stats, 0x1a);
        break;
    case 3:
        SetBitInArray0x910((unsigned char*)stats, 0);
        break;
    }

    if (unchanged == 0) {
        GameResources* ui = func_ov017_0218b5b0();
        func_0202ae18();
        func_ov017_0218f5a4(ui, self->combatantId, 1, 0, 0);
    }
}
