#include <globaldefs.h>

struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

struct List_020283fc;
int FindListIndexById(struct List_020283fc* list, int id);

extern "C" int _Z29CheckAnySlotMatchesId02073d58iPvi(int a, void* b, int c);

struct Entry_0209bd94;
struct EntryTable0209bd94;
struct MaskEntry02078e60 {
    unsigned short key;
    unsigned short pad2;
    unsigned int type : 3;
    unsigned int rsvd1 : 10;
    unsigned int flags8 : 8;
    unsigned int rsvd2 : 11;
    unsigned char pad8[0x20 - 8];
};
extern "C" struct MaskEntry02078e60* _Z27FindEntryByHalfword0209bd94P18EntryTable0209bd94i(struct EntryTable0209bd94* table, int key);

struct Slot02078e60 {
    unsigned char id;
    unsigned char flags;
};

struct ListEntry_02028430 {
    unsigned char id;
    unsigned char pad1;
    unsigned char count;
    unsigned char pad3[0xc - 3];
    struct Slot02078e60** items;
};
struct ListEntry_02028430* GetListEntryChecked(struct List_02028430* list, int index);

struct Obj02078e60 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0xb8 - 6];
    unsigned short field0xb8;
    char padba[0x168 - 0xba];
    unsigned short field168;
    char pad16a[0x17d - 0x16a];
    unsigned char field17d;
};

extern "C" int rand(void);

// USA: func_02078e60
extern "C" ARM unsigned short func_02078e60(void* obj, char* out) {
    struct Obj02078e60* o = (struct Obj02078e60*)obj;
    struct Entry_02028bd0* table;
    struct Entry_02028bd0* entry;
    struct ListEntry_02028430* le;
    struct MaskEntry02078e60* found;
    struct Slot02078e60* item;
    struct Slot02078e60* picks[16];
    struct Slot02078e60* pick;
    int n;
    int j;
    int any;
    int idx;

    *out = 0;
    table = GetEntryTableBase();
    entry = FindInlineEntryById(table, _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)o));
    if (entry == NULL) {
        return 0;
    }
    le = GetListEntryChecked((struct List_02028430*)((char*)entry + 0x18), o->field0xb8);
    if (le == NULL) {
        return 0;
    }
    if (le->count == 0) {
        return 0;
    }
    if ((o->field17d & 0x40) == 0) {
        if (_Z29CheckAnySlotMatchesId02073d58iPvi(le->id, entry, o->f4) != 0) {
            *out = 1;
            return le->id;
        }
        *out = 0;
        o->field17d |= 0x40;
        return le->id;
    }
    found = _Z27FindEntryByHalfword0209bd94P18EntryTable0209bd94i((struct EntryTable0209bd94*)((char*)entry + 0x60), o->field168);
    n = 0;
    any = 0;
    if (found != NULL) {
        for (j = 0; j < le->count; j++) {
            item = le->items[j];
            if ((item->flags & found->flags8) == 0 && item->flags != 0) {
                continue;
            }
            if (_Z29CheckAnySlotMatchesId02073d58iPvi(item->id, entry, -1) != 0) {
                any = 1;
            } else {
                picks[n++] = le->items[j];
            }
        }
    }
    if (any == 1 && n == 0) {
        idx = FindListIndexById((struct List_020283fc*)((char*)entry + 0x18), le->id);
        if (idx != -1) {
            o->field0xb8 = idx;
        }
        return le->id;
    }
    pick = 0;
    if (n != 0) {
        pick = picks[rand() % n];
    }
    if (pick == 0) {
        idx = FindListIndexById((struct List_020283fc*)((char*)entry + 0x18), le->id);
        if (idx != -1) {
            o->field0xb8 = idx;
        }
        return le->id;
    }
    idx = FindListIndexById((struct List_020283fc*)((char*)entry + 0x18), pick->id);
    if (idx != -1) {
        o->field0xb8 = idx;
    }
    return pick->id;
}
