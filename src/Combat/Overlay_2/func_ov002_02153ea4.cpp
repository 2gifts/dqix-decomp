#include <globaldefs.h>
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;

extern "C" int *func_0202ae18(void);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct *arr, int value);
int CheckField0NonZero_0202b7d8(int *p);
int HasPositiveField304Short4_02154a34(void *self, int id);
int HasPositiveField256Short178_02154b94(void *self, int id);

struct Entry02153ea4 {
    unsigned char state;
    unsigned char pad1;
    unsigned short value;
    unsigned char absent;
    unsigned char pad5;
};

struct Info02153ea4 {
    unsigned char pad0[2];
    signed char kind;
    unsigned char count;
    signed char ids[4];
    Entry02153ea4 entries[4];
    Entry02153ea4 altEntries[4];
};

extern "C" void func_ov002_02153e90(Entry02153ea4 *e);
extern "C" int func_ov002_02154a6c(void *self, int id, int kind);
extern "C" unsigned short func_ov002_021549c8(void *self, int id, int mode, Entry02153ea4 *e);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_ov002_02153ea4
extern "C" ARM int func_ov002_02153ea4(void *self, Info02153ea4 *info, int enabled, int alt) {
    if (info == 0) return 0;
    if (enabled == 0) return 0;
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *)GetPtrField0x2a04_02010828(GameState::GetInstance());
    int *g                         = func_0202ae18();
    int changed                    = 0;
    Entry02153ea4 *entries         = info->entries;
    if (alt) entries = info->altEntries;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(&entries[i]);
    }
    for (int i = 0; i < info->count; i++) {
        Entry02153ea4 *e = &entries[i];
        int id           = info->ids[i];
        if (!ArrayContainsByte_02086ef0(party, id)) e->absent = 1;
        if (!func_ov002_02154a6c(self, id, info->kind)) {
            e->state = 1;
            continue;
        }
        if (HasPositiveField256Short178_02154b94(self, id)) {
            e->state = 2;
            continue;
        }
        if (!HasPositiveField304Short4_02154a34(self, id)) continue;
        if (e->absent) {
            e->value = 1;
            e->state = 3;
        } else {
            e->value = func_ov002_021549c8(self, id, 2, e);
        }
        if (e->state == 0) continue;
        if (CheckField0NonZero_0202b7d8(g) && ArrayContainsByte_02086ef0(party, id)) {
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        changed = 1;
    }
    return changed;
}
