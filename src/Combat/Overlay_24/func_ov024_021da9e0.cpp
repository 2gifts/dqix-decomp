#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Bits8_021da9e0 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

struct Id12_021da9e0 { unsigned int id : 12; unsigned int rest : 20; };
struct Kind5_021da9e0 { unsigned int kind : 5; unsigned int rest : 27; };
struct Pack10_021da9e0 { unsigned int a : 10; unsigned int b : 10; unsigned int c : 10; unsigned int hi : 2; };

struct Rec_021da9e0 {
    char pad0[4];
    struct Id12_021da9e0 f4;
    char pad8[0x10];
    struct Kind5_021da9e0 f18;
    char pad1c[0xc];
    struct Pack10_021da9e0 f28;
};

struct Link_021da9e0 { int f0; struct Link_021da9e0* next; };

struct Entry_021da9e0 {
    unsigned long long flags;
    struct Link_021da9e0* chain;
    char padc[0xa];
    unsigned short f16;
    char pad18[7];
    unsigned char f1f;
    struct Entry_021da9e0* next;
};

struct Node_021da9e0 {
    struct Entry_021da9e0* entries[3];
    char padc[0xc];
    unsigned char counts[3];
    char pad1b;
    struct Bits8_021da9e0 f1c;
    struct Bits8_021da9e0 f1d;
    char pad1e[2];
    unsigned short f20;
};

struct Act_021da9e0 {
    int f0;
    void* list;
    void* f8;
    struct Node_021da9e0* fc;
    void* world;
    int count;
    int f18;
    char pad1c[0x2c];
    struct Node_021da9e0* slots[8];
    struct Entry_021da9e0* f68;
    char pad6c[2];
    unsigned char f6e;
    char pad6f;
    unsigned char f70;
    char pad71[9];
    unsigned char f7a;
};

extern "C" float func_ov024_021db358(GameObject* c);
extern "C" int _Z19ClassifyField0x81fePc(void* world);
extern "C" int func_ov000_0215ffa0(void* node);
void* FindNodeAtDepth0215fff4(void* node, int index, int slot);
extern "C" struct Entry_021da9e0* func_ov000_0215e958(void* world);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* c, int d, unsigned long long e, int g);
void AppendToChainAndIncCount0215ffc4(void* node, void* entry, int v);
extern "C" void _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(struct Act_021da9e0* self, struct Node_021da9e0* n);
extern "C" unsigned long long func_ov024_021e4b14(struct Act_021da9e0* self, int a, int id, struct Rec_021da9e0* rec, int dmg);
extern "C" int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
extern "C" struct Node_021da9e0* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int index);
extern "C" struct Rec_021da9e0* _Z24SearchBothTables02079e2cPci(void* table, int id);
extern "C" short func_ov000_0215a004(void* world, int a, int id, int dmg, void* effects, struct Rec_021da9e0* rec, int flag, int mode);
extern "C" void func_ov000_02159eac(void* world, void* effects, int bit);
void AddEntryAndIncrementCount0215a88c(void* world, void* entry, int v);
extern "C" int func_ov024_021eb08c(struct Act_021da9e0* self, int a, int id, int kind);
extern "C" void func_ov000_0215a908(void* world, int id);
extern "C" unsigned short func_ov024_021e9b24(struct Act_021da9e0* self, int id, struct Rec_021da9e0* rec, int flag);
unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void* world, void* entry, GameObject* c, short a, short b, short d, unsigned long long f, unsigned char h);

static inline int IsPartySlot_021da9e0(int id) {
    return id >= 0 && id <= 3;
}

static inline int IsPartySlotS_021da9e0(short id) {
    return id >= 0 && id <= 3;
}

static inline unsigned short CurrMP_021da9e0(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov024_021da9e0
extern "C" ARM struct Entry_021da9e0* func_ov024_021da9e0(struct Act_021da9e0* obj, short a, int id, struct Rec_021da9e0* rec, int dmg, int* flags, unsigned char cnt) {
    GameObject* c = GetCombatantByID((int)obj->world, id);
    if (!c) return 0;
    float ratio = func_ov024_021db358(c);
    unsigned short code = rec->f4.id;
    if (code == 0x150) dmg = 0;
    if (_Z19ClassifyField0x81fePc(obj->world) != 0 && code == 1 && id == 0) {
        GameObject* g = GetCombatantWithFlag0x100(GameState::GetInstance(), 0);
        if (g) {
            if (_Z19ClassifyField0x81fePc(obj->world) == 1) {
                unsigned short hp = c->currentStats_->primaryStats.currHP;
                dmg = (int)(0.9f * (float)hp);
                if (hp <= dmg) dmg = hp - 1;
                if (dmg <= 0) dmg = 1;
            } else if (_Z19ClassifyField0x81fePc(obj->world) == 2) {
                dmg = g->currentStats_->primaryStats.currHP;
            }
        }
    }
    if (obj->f7a != 0 || obj->f18 != 0) {
        int found = 0;
        for (int i = 0; i < 8; i++) {
            struct Node_021da9e0* n = obj->slots[i];
            if (!n) continue;
            if (n == obj->fc) {
                obj->slots[i] = 0;
                continue;
            }
            if (n && func_ov000_0215ffa0(n) == id) {
                for (int j = 1; j <= 2; j++) {
                    struct Entry_021da9e0* e = n->entries[j];
                    if (!e) continue;
                    struct Entry_021da9e0** link = &n->entries[j];
                    struct Entry_021da9e0* dst = 0;
                    if (obj->fc->counts[1] != 0)
                        dst = (struct Entry_021da9e0*)FindNodeAtDepth0215fff4(obj->fc, obj->fc->counts[1] - 1, 1);
                    while (e) {
                        struct Link_021da9e0* x = e->chain;
                        if (x) {
                            if (!dst) {
                                dst = func_ov000_0215e958(obj->world);
                                if (!dst) return 0;
                                func_ov000_0215cd44(obj->world, dst, c, 0, 0, 0);
                                AppendToChainAndIncCount0215ffc4(obj->fc, dst, 1);
                                ((unsigned char*)obj->world)[0x8e02]++;
                            }
                            struct Link_021da9e0** p = &dst->chain;
                            while (*p) p = &(*p)->next;
                            *p = x;
                            dst->f1f += e->f1f;
                            e->chain = 0;
                            e->f1f = 0;
                            if (e->flags == 0 && e->f16 == 0) {
                                *link = e->next;
                                n->counts[j]--;
                            }
                            link = &e->next;
                        }
                        e = e->next;
                    }
                }
                obj->slots[i] = 0;
                found = 1;
            }
        }
        if (found) _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(obj, obj->fc);
    }
    union { struct { int lo; int hi; }; unsigned long long value; } effects;
    effects.lo = 0;
    effects.hi = 0;
    int apply = 1;
    if (rec->f18.kind == 0x14 && cnt == 0) apply = 0;
    if (apply) effects.value = func_ov024_021e4b14(obj, a, id, rec, dmg);
    if (func_ov000_02159f18(obj->world, effects.value, 0xe) || func_ov000_02159f18(obj->world, effects.value, 0x17))
        obj->f70 = 0;
    struct Entry_021da9e0* entry = func_ov000_0215e958(obj->world);
    if (!entry) return 0;
    short hp = 0;
    if (!func_ov000_02159f18(obj->world, effects.value, 0xd) && !func_ov000_02159f18(obj->world, effects.value, 0x29)) {
        struct Rec_021da9e0* r = rec;
        if (obj->list) {
            struct Node_021da9e0* first = _Z22GetNodeAtIndex02160094P12List02160094i(obj->list, 0);
            if (first) {
                if (first->f20 != a) r = 0;
                unsigned int k = rec->f4.id;
                if (k == 1 || k == 2 || k == 0xdb || k == 0xdf || k == 0xe0 || obj->fc->f1d.b0)
                    r = _Z24SearchBothTables02079e2cPci(GetData02108e10(), 1);
            }
        }
        hp = func_ov000_0215a004(obj->world, a, id, dmg, &effects, r, obj->fc->f1c.b7 != 0, 0);
    }
    if (dmg > 0) obj->count++;
    else func_ov000_02159eac(obj->world, &effects, 4);
    if (func_ov000_02159f18(obj->world, effects.value, 2) || func_ov000_02159f18(obj->world, effects.value, 0xd)) {
        *flags |= 2;
        obj->fc->entries[1] = 0;
        obj->fc->counts[1] = 0;
        obj->fc->entries[2] = 0;
        obj->fc->counts[2] = 0;
        if (obj->list && func_ov000_02159f18(obj->world, effects.value, 2) && rec->f4.id != 0x61) {
            if (IsPartySlot_021da9e0(id))
                AddEntryAndIncrementCount0215a88c(obj->world, entry, (unsigned short)rec->f28.a);
            obj->f68 = entry;
        }
    } else if (!func_ov000_02159f18(obj->world, effects.value, 0x29)) {
        if (!IsPartySlot_021da9e0(id) && IsPartySlotS_021da9e0(a) && dmg > 0) {
            int ok = 0;
            float now = func_ov024_021db358(c);
            if (ratio >= 0.25f && now < 0.25f) {
                if (func_ov024_021eb08c(obj, a, id, 4)) ok = 1;
            } else if (ratio >= 0.5f && now < 0.5f) {
                if (func_ov024_021eb08c(obj, a, id, 3)) ok = 1;
            }
            if (ok) func_ov000_0215a908(obj->world, id);
        }
    }
    if (rec->f4.id == 0x61) {
        if (obj->f18 > 0) AddEntryAndIncrementCount0215a88c(obj->world, entry, 0x1f0);
        unsigned short sel;
        if (dmg > 0) {
            sel = func_ov024_021e9b24(obj, id, rec, 0);
        } else {
            struct Node_021da9e0* fc = obj->fc;
            if (fc && (fc->f1c.b1 || fc->f1c.b2 || fc->f1c.b3 || fc->f1c.b4 || fc->f1c.b5 || fc->f1c.b6))
                sel = 0;
            else
                sel = SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
        }
        if (sel) AddEntryAndIncrementCount0215a88c(obj->world, entry, sel);
        if (obj->list && func_ov000_02159f18(obj->world, effects.value, 2)) {
            if (IsPartySlot_021da9e0(id))
                AddEntryAndIncrementCount0215a88c(obj->world, entry, (unsigned short)rec->f28.a);
            else
                AddEntryAndIncrementCount0215a88c(obj->world, entry, (unsigned short)rec->f28.b);
            *flags |= 2;
            obj->fc->entries[1] = 0;
            obj->fc->counts[1] = 0;
            obj->fc->entries[2] = 0;
            obj->fc->counts[2] = 0;
        }
    }
    if (func_ov000_02159f18(obj->world, effects.value, 0xd)) {
        dmg = 0;
        hp = 0;
        if (IsPartySlot_021da9e0(id))
            AddEntryAndIncrementCount0215a88c(obj->world, entry, 8);
        else
            AddEntryAndIncrementCount0215a88c(obj->world, entry, 0x45);
        obj->f6e = 1;
    } else if (func_ov000_02159f18(obj->world, effects.value, 0x29)) {
        dmg = 0;
        hp = 1;
        AddEntryAndIncrementCount0215a88c(obj->world, entry, 0xc8);
        obj->f6e = 1;
    }
    _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(obj->world, entry, c, dmg, hp, CurrMP_021da9e0(c), effects.value, obj->fc->f1c.b7 != 0);
    return entry;
}
