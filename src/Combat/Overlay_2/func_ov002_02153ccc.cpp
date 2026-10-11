#include <globaldefs.h>

class GameState;
struct ArrayContainsByteStruct;

extern "C" GameState *_ZN9GameState11GetInstanceEv();
ArrayContainsByteStruct *GetPtrField0x2a04(GameState *gs);
extern "C" int *func_0202ae18(void);
int ArrayContainsByte(ArrayContainsByteStruct *arr, int value);
int CheckField0NonZero(int *p);
extern "C" int _Z34HasPositiveField304Short4_02154a34Pvi(void *self, int id);
extern "C" int _Z36HasPositiveField256Short178_02154b94Pvi(void *self, int id);
extern "C" void *_Z26LookupElementByKey02079ee0Pvi(void *table, int key);

struct Entry02153ccc {
    unsigned char state;
    unsigned char pad1;
    unsigned short value;
    unsigned char absent;
    unsigned char pad5;
};

struct Info02153ccc {
    short type;
    signed char kind;
    unsigned char count;
    signed char ids[4];
    Entry02153ccc entries[4];
    Entry02153ccc altEntries[4];
};

struct Action02153ccc {
    unsigned char pad0[8];
    unsigned int lo : 14;
    unsigned int key : 8;
    unsigned int hi : 10;
};

extern "C" void func_ov002_02153e90(Entry02153ccc *e);
extern "C" int func_ov002_02154a6c(void *self, int id, int kind);
extern "C" int func_ov002_021538e4(void *self, Action02153ccc *action, void *elem, int kind);
extern "C" unsigned short func_ov002_021548c4(void *self, int id, int value, Entry02153ccc *e);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_ov002_02153ccc
extern "C" ARM int func_ov002_02153ccc(void **self, Info02153ccc *info, Action02153ccc *action, int alt) {
    if (info == 0) return 0;
    if (action == 0) return 0;
    ArrayContainsByteStruct *party = GetPtrField0x2a04(_ZN9GameState11GetInstanceEv());
    int *g                         = func_0202ae18();
    Entry02153ccc *entries         = info->entries;
    int changed                    = 0;
    if (alt) entries = info->altEntries;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(&entries[i]);
    }
    for (int i = 0; i < info->count; i++) {
        Entry02153ccc *e = &entries[i];
        int id           = info->ids[i];
        int value;
        if (!ArrayContainsByte(party, id)) e->absent = 1;
        if (!func_ov002_02154a6c(self, id, info->kind)) {
            e->state = 1;
            continue;
        }
        if (_Z36HasPositiveField256Short178_02154b94Pvi(self, id)) {
            e->state = 2;
            continue;
        }
        if (!_Z34HasPositiveField304Short4_02154a34Pvi(self, id)) continue;
        if (info->type == 0x21) {
            value = 999;
        } else {
            void *elem = _Z26LookupElementByKey02079ee0Pvi(*self, action->key);
            if (elem == 0) continue;
            value = func_ov002_021538e4(self, action, elem, info->kind);
        }
        if (e->absent) {
            e->value = value;
            e->state = 3;
        } else {
            e->value = func_ov002_021548c4(self, id, value, e);
        }
        if (e->state == 0) continue;
        if (CheckField0NonZero(g) && ArrayContainsByte(party, id)) {
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        changed = 1;
    }
    return changed;
}
