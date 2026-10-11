#if defined(jpn)
#define data_ov015_021942a2 data_ov015_02194f64
#define data_ov015_021943a5 data_ov015_02194f37
#define data_ov015_021943b0 data_ov015_02194f48
#define data_ov015_021943b7 data_ov015_02194f57
#define data_ov015_021943bd data_ov015_02194f71
#define data_ov015_021943c6 data_ov015_02194f7e
#define data_ov015_021943d0 data_ov015_02194f8b
#define data_ov015_021943d9 data_ov015_02194f98
#define data_ov015_021943df data_ov015_02194f9e
#define data_ov015_021943ef data_ov015_02194fb1
#define data_ov015_021943f8 data_ov015_02194fb8
#define data_ov015_021943ff data_ov015_02194fbd
#define data_ov015_0219440c data_ov015_02194fc4
#define data_ov015_0219441a data_ov015_02194fcb
#define data_ov015_02194426 data_ov015_02194fd0
#define data_ov015_02194434 data_ov015_02194fd7
#define data_ov015_0219443d data_ov015_02194fe0
#define data_ov015_02194442 data_ov015_02194fe5
#define data_ov015_0219444b data_ov015_02194fee
#define data_ov015_02194452 data_ov015_02194ff5
#define data_ov015_02194459 data_ov015_02194ffc
#define data_ov015_0219445e data_ov015_02195001
#define data_ov015_02194463 data_ov015_02195006
#define data_ov015_02194470 data_ov015_02195017
#define data_ov015_0219447f data_ov015_0219502e
#define data_ov015_0219448e data_ov015_02195041
#define data_ov015_02194496 data_ov015_02195048
#define data_ov015_0219449e data_ov015_02195053
#define data_ov015_021944a9 data_ov015_0219505a
#define data_ov015_021944b6 data_ov015_0219506e
#define data_ov015_021944c5 data_ov015_02195083
#define data_ov015_021944d4 data_ov015_02195096
#define data_ov015_021944e3 data_ov015_021950b6
#define data_ov015_021944ec data_ov015_021950d0
#define data_ov015_021944f3 data_ov015_021950d7
#define data_ov015_021944fa data_ov015_021950de
#define data_ov015_02194503 data_ov015_021950eb
#define data_ov015_02194508 data_ov015_021950f5
#define data_ov015_0219450f data_ov015_021950fc
#define data_ov015_02194517 data_ov015_02195104
#define data_ov015_0219451b data_ov015_02195109
#define data_ov015_0219451f data_ov015_0219510e
extern const char data_ov015_021950a5[];
extern const char data_ov015_021950c3[];
extern const char data_ov015_021950f0[];
#endif
#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct MenuItem02192700 { char data[0x40]; };

struct MenuList02192700 {
    char pad0[0x62];
    unsigned short visibleCount;
    char pad64[0x6d - 0x64];
    unsigned char flags;
};

struct NamedValue02192700 {
    char pad0[0xc];
    char* name;
};

struct ListNode02192700 {
    struct NamedValue02192700* value;
    struct ListNode02192700* next;
};

struct Entry8_0218bb14 { char* name; int b; };
struct List8_0218bb14 { void* f0; struct Entry8_0218bb14* arr; void* f8; int count; };

struct MenuEntry02192700 {
    char* name;
    int f4;
    short key;
};

struct SearchResult02192700 {
    int f0;
    int f4;
};

struct Element020dedd0 {
    int f0;
    char* name;
};

struct BCFG;

struct HolderNode02192700 {
    int f0;
    char bcfg[0x24];
    struct HolderNode02192700* next;
};

struct Obj02192700 {
    char pad0[0x2c];
    struct ListNode02192700* list;
    void* field30;
    struct NamedValue02192700* field34;
    char pad38[0x3c - 0x38];
    struct List8_0218bb14 entries;
    char container[0x64 - 0x4c];
    char search[0x194 - 0x64];
    int field194;
    char pad198[0x19c - 0x198];
    unsigned char marks[5];
    char pad1a1[0x1a4 - 0x1a1];
    int state;
    char pad1a8[0x268 - 0x1a8];
    short cursors[(0x2c4 - 0x268) / 2];
    struct MenuList02192700 menu;
    char pad332[0x344 - 0x332];
    struct MenuItem02192700* items;
    int barSize;
    float barStep;
    unsigned char barReady;
    char pad351[0x354 - 0x351];
    int field354;
};

extern "C" void __clear(void* buf, int n);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern "C" void* _Z16AllocateAligned4P14AllocatorUnionj(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z21SetState0x6cAndInvokeP17Callback_0202a91c(struct MenuList02192700* menu);
extern "C" void func_02029568(struct MenuList02192700* menu);
extern "C" void func_020294cc(void* self, const char* src);
extern "C" void _Z12Init0202949cPc(struct MenuItem02192700* item);
extern "C" const char* _Z28CallFunc020e0434With02153694i(int id);
extern "C" void _Z24AppendNodeToList0202a944P16ListHead0202a944P16ListNode0202a944(struct MenuList02192700* menu, struct MenuItem02192700* item);
extern "C" struct Entry8_0218bb14* _Z18GetEntry8_0218bb14P14List8_0218bb14i(struct List8_0218bb14* list, int idx);
extern "C" struct MenuEntry02192700* func_ov015_02193160(struct Obj02192700* obj, int state, int* pIdx);
extern "C" struct SearchResult02192700* _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(void* s, int key);
extern "C" int func_ov015_02190d08(struct Obj02192700* obj);
extern "C" struct Element020dedd0* _Z24FindElementByKey020dedd0P17Container020dedd0i(void* c, int key);
extern "C" void _Z22SetShortFields0219313cP14Struct0219313css(struct MenuList02192700* menu, int a, int b);
extern "C" void _Z23AddToShortField02193150P14Struct02193150i(struct MenuList02192700* menu, int v);
extern "C" void func_0202a6c4(struct MenuList02192700* menu);
extern "C" void _Z18Deactivate0202a8ccPci(struct MenuList02192700* menu, int flag);
extern "C" struct HolderNode02192700* func_ov015_0218f344(void* obj);
extern "C" int _ZNK4BCFG16GetNumAnimationsEv(struct BCFG* bcfg);
extern "C" const char* _ZN4BCFG18GetAnimationRecordEi(struct BCFG* bcfg, int index);

extern AllocatorUnion data_02114e20;
extern const char data_ov015_021942a2[];
extern const char data_ov015_021943a5[];
extern const char data_ov015_021943b0[];
extern const char data_ov015_021943b7[];
extern const char data_ov015_021943bd[];
extern const char data_ov015_021943c6[];
extern const char data_ov015_021943d0[];
extern const char data_ov015_021943d9[];
extern const char data_ov015_021943df[];
extern const char data_ov015_021943ef[];
extern const char data_ov015_021943f8[];
extern const char data_ov015_021943ff[];
extern const char data_ov015_0219440c[];
extern const char data_ov015_0219441a[];
extern const char data_ov015_02194426[];
extern const char data_ov015_02194434[];
extern const char data_ov015_0219443d[];
extern const char data_ov015_02194442[];
extern const char data_ov015_0219444b[];
extern const char data_ov015_02194452[];
extern const char data_ov015_02194459[];
extern const char data_ov015_0219445e[];
extern const char data_ov015_02194463[];
extern const char data_ov015_02194470[];
extern const char data_ov015_0219447f[];
extern const char data_ov015_0219448e[];
extern const char data_ov015_02194496[];
extern const char data_ov015_0219449e[];
extern const char data_ov015_021944a9[];
extern const char data_ov015_021944b6[];
extern const char data_ov015_021944c5[];
extern const char data_ov015_021944d4[];
extern const char data_ov015_021944e3[];
extern const char data_ov015_021944ec[];
extern const char data_ov015_021944f3[];
extern const char data_ov015_021944fa[];
extern const char data_ov015_02194503[];
extern const char data_ov015_02194508[];
extern const char data_ov015_0219450f[];
extern const char data_ov015_02194517[];
extern const char data_ov015_0219451b[];
extern const char data_ov015_0219451f[];

static inline const char* GetName(struct NamedValue02192700* value) {
    return value->name;
}

// USA: func_ov015_02192700
extern "C" ARM void func_ov015_02192700(struct Obj02192700* obj, int a1) {
    char title[0x80];
    char line[0x100];
    char marked[0x80];
    int idx;
    int count;

    if (obj->items != 0) {
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, obj->items);
        obj->items = 0;
    }
    obj->field354 = a1;
    __clear(title, 0x80);
    _Z21SetState0x6cAndInvokeP17Callback_0202a91c(&obj->menu);
    func_02029568(&obj->menu);
    obj->menu.flags |= 6;

    if (obj->field194 == 0 || obj->field194 == 2) {
        switch (obj->state) {
        case 0:
            func_020294cc(&obj->menu, data_ov015_021943a5);
            break;
        case 1:
            func_020294cc(&obj->menu, data_ov015_021943b0);
            break;
        case 2:
            func_020294cc(&obj->menu, data_ov015_021943b7);
            break;
        case 3:
            func_020294cc(&obj->menu, data_ov015_021942a2);
            break;
        case 4:
            func_020294cc(&obj->menu, data_ov015_021943bd);
            break;
        case 6:
            func_020294cc(&obj->menu, data_ov015_021943c6);
            break;
        case 7:
            func_020294cc(&obj->menu, data_ov015_021943d0);
            break;
        case 5:
            func_020294cc(&obj->menu, data_ov015_021943d9);
            break;
        case 8:
            func_020294cc(&obj->menu, data_ov015_021943df);
            break;
        case 15:
            func_020294cc(&obj->menu, data_ov015_021943ef);
            break;
        case 17:
            func_020294cc(&obj->menu, data_ov015_021943f8);
            break;
        case 18:
            func_020294cc(&obj->menu, data_ov015_021943ff);
            break;
        case 19:
            func_020294cc(&obj->menu, data_ov015_0219440c);
            break;
        case 20:
            func_020294cc(&obj->menu, data_ov015_0219441a);
            break;
        case 21:
            func_020294cc(&obj->menu, data_ov015_02194426);
            break;
        case 23:
            func_020294cc(&obj->menu, data_ov015_02194434);
            break;
        case 24:
            func_020294cc(&obj->menu, data_ov015_0219443d);
            break;
        case 25:
            func_020294cc(&obj->menu, data_ov015_02194442);
            break;
        case 26:
            func_020294cc(&obj->menu, data_ov015_0219444b);
            break;
        case 27:
            func_020294cc(&obj->menu, data_ov015_02194452);
            break;
        case 28:
            func_020294cc(&obj->menu, data_ov015_02194459);
            break;
        case 22:
            func_020294cc(&obj->menu, data_ov015_0219445e);
            break;
        case 29:
            func_020294cc(&obj->menu, data_ov015_02194463);
            break;
        case 30:
            func_020294cc(&obj->menu, data_ov015_02194470);
            break;
        case 31:
            func_020294cc(&obj->menu, data_ov015_0219447f);
            break;
        case 16:
            func_020294cc(&obj->menu, data_ov015_0219448e);
            break;
        case 11:
            func_020294cc(&obj->menu, data_ov015_02194496);
            break;
        case 12:
            func_020294cc(&obj->menu, data_ov015_0219449e);
            break;
        case 33:
            func_020294cc(&obj->menu, data_ov015_021944a9);
            break;
        case 32:
            func_020294cc(&obj->menu, data_ov015_021944b6);
            break;
        case 13:
            func_020294cc(&obj->menu, data_ov015_021944c5);
            break;
        case 14:
            func_020294cc(&obj->menu, data_ov015_021944d4);
            break;
        case 34:
#if defined(jpn)
            func_020294cc(&obj->menu, data_ov015_021950a5);
#else
            func_020294cc(&obj->menu, data_ov015_021942a2);
#endif
            break;
        case 35:
            func_020294cc(&obj->menu, data_ov015_021944e3);
            break;
        case 36:
#if defined(jpn)
            func_020294cc(&obj->menu, data_ov015_021950c3);
#else
            func_020294cc(&obj->menu, data_ov015_021942a2);
#endif
            break;
        case 38:
            func_020294cc(&obj->menu, data_ov015_021944ec);
            break;
        case 39:
            func_020294cc(&obj->menu, data_ov015_021944f3);
            break;
        case 40:
            func_020294cc(&obj->menu, data_ov015_021944fa);
            break;
        case 37:
            if (obj->field34 != 0) {
                sprintf(title, data_ov015_02194503, obj->field34->name);
            }
            func_020294cc(&obj->menu, title);
            break;
        }

        count = 0;
        if (obj->state == 2 || obj->state == 3 || obj->state == 36) {
            struct ListNode02192700* it;
            for (it = obj->list; it != 0; it = it->next) {
                count++;
            }
            if (count == 0) {
                obj->items = (struct MenuItem02192700*)_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, sizeof(struct MenuItem02192700));
            } else {
                obj->items = (struct MenuItem02192700*)_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, count * sizeof(struct MenuItem02192700));
            }
            if (count == 0) {
                _Z12Init0202949cPc(obj->items);
#if defined(jpn)
                func_020294cc(obj->items, data_ov015_021950f0);
#else
                func_020294cc(obj->items, _Z28CallFunc020e0434With02153694i(1000));
#endif
                _Z24AppendNodeToList0202a944P16ListHead0202a944P16ListNode0202a944(&obj->menu, obj->items);
                count = 1;
            } else {
                struct ListNode02192700* node = obj->list;
                for (count = 0; node != 0; count++) {
                    _Z12Init0202949cPc(&obj->items[count]);
                    func_020294cc(&obj->items[count], GetName(node->value));
                    _Z24AppendNodeToList0202a944P16ListHead0202a944P16ListNode0202a944(&obj->menu, &obj->items[count]);
                    node = node->next;
                }
            }
        } else if (obj->state == 40) {
            obj->items = (struct MenuItem02192700*)_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, obj->entries.count * sizeof(struct MenuItem02192700));
            for (; count < obj->entries.count; count++) {
                struct Entry8_0218bb14* entry = _Z18GetEntry8_0218bb14P14List8_0218bb14i(&obj->entries, count);
                _Z12Init0202949cPc(&obj->items[count]);
                func_020294cc(&obj->items[count], entry->name);
                _Z24AppendNodeToList0202a944P16ListHead0202a944P16ListNode0202a944(&obj->menu, &obj->items[count]);
            }
        } else {
            struct MenuEntry02192700* entry;

            idx = 0;
            entry = func_ov015_02193160(obj, obj->state, &idx);
            while (entry != 0) {
                idx++;
                count++;
                entry = func_ov015_02193160(obj, obj->state, &idx);
            }
            obj->items = (struct MenuItem02192700*)_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, count * sizeof(struct MenuItem02192700));
            count = 0;
            idx = 0;
            entry = func_ov015_02193160(obj, obj->state, &idx);
            while (entry != 0) {
                _Z12Init0202949cPc(&obj->items[count]);
                if (obj->state == 6) {
                    struct SearchResult02192700* found = _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(obj->search, entry->key);
                    if (found != 0) {
                        __clear(line, 0x100);
                        sprintf(line, data_ov015_02194508, found->f4 + 1, found->f0);
                        func_020294cc(&obj->items[count], line);
                    } else if ((unsigned short)entry->key == 0) {
                        func_020294cc(&obj->items[count], entry->name);
                    } else {
                        func_020294cc(&obj->items[count], data_ov015_0219450f);
                    }
                } else if (func_ov015_02190d08(obj) != 0) {
                    struct Element020dedd0* elem = _Z24FindElementByKey020dedd0P17Container020dedd0i(obj->container, entry->key);
                    if (elem != 0) {
                        if (elem->name != 0) {
                            func_020294cc(&obj->items[count], elem->name);
                        } else {
                            func_020294cc(&obj->items[count], entry->name);
                        }
                    } else {
                        func_020294cc(&obj->items[count], entry->name);
                    }
                } else if (obj->state == 38) {
                    unsigned char mark;

                    __clear(marked, 0x80);
                    mark = 0;
                    switch (count) {
                    case 0:
                        mark = obj->marks[0];
                        break;
                    case 1:
                        mark = obj->marks[1];
                        break;
                    case 2:
                        mark = obj->marks[2];
                        break;
                    case 3:
                        mark = obj->marks[3];
                        break;
                    case 4:
                        mark = obj->marks[4];
                        break;
                    }
                    if (mark != 0) {
                        sprintf(marked, data_ov015_02194517);
                    } else {
                        sprintf(marked, data_ov015_0219451b);
                    }
                    strcat(marked, entry->name);
                    func_020294cc(&obj->items[count], marked);
                } else {
                    func_020294cc(&obj->items[count], entry->name);
                }
                _Z24AppendNodeToList0202a944P16ListHead0202a944P16ListNode0202a944(&obj->menu, &obj->items[count]);
                count++;
                idx++;
                entry = func_ov015_02193160(obj, obj->state, &idx);
            }
        }
        _Z22SetShortFields0219313cP14Struct0219313css(&obj->menu, 0, count - 1);
        _Z23AddToShortField02193150P14Struct02193150i(&obj->menu, obj->cursors[obj->state]);
        func_0202a6c4(&obj->menu);
        _Z18Deactivate0202a8ccPci(&obj->menu, 1);
    } else {
        struct HolderNode02192700* it;
        struct HolderNode02192700* holder;

        func_020294cc(&obj->menu, data_ov015_0219451f);
        count = 0;
        for (it = func_ov015_0218f344(obj->field30); it != 0; it = it->next) {
            struct BCFG* bcfg = (struct BCFG*)it->bcfg;
            if (bcfg != 0) {
                count += _ZNK4BCFG16GetNumAnimationsEv(bcfg);
            }
        }
        obj->items = (struct MenuItem02192700*)_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, count * sizeof(struct MenuItem02192700));
        holder = func_ov015_0218f344(obj->field30);
        idx = 0;
        for (; holder != 0; holder = holder->next) {
            struct BCFG* bcfg = (struct BCFG*)holder->bcfg;
            if (bcfg != 0) {
                int num = _ZNK4BCFG16GetNumAnimationsEv(bcfg);
                for (int i = 0; i < num; i++) {
                    const char* name = _ZN4BCFG18GetAnimationRecordEi(bcfg, i);
                    if (name != 0) {
                        _Z12Init0202949cPc(&obj->items[idx]);
                        func_020294cc(&obj->items[idx], name);
                        _Z24AppendNodeToList0202a944P16ListHead0202a944P16ListNode0202a944(&obj->menu, &obj->items[idx++]);
                    }
                }
            }
        }
        _Z22SetShortFields0219313cP14Struct0219313css(&obj->menu, 0, count - 1);
        _Z23AddToShortField02193150P14Struct02193150i(&obj->menu, 0);
        func_0202a6c4(&obj->menu);
        _Z18Deactivate0202a8ccPci(&obj->menu, 1);
    }

    int visible = obj->menu.visibleCount;
    float ratio = (float)visible / (float)count;
    if (ratio > 1.0f) {
        ratio = 1.0f;
    }
    obj->barSize = (int)(156.0f * ratio);
    int hidden = count - visible;
    obj->barStep = (float)(156 - obj->barSize) / (float)hidden;
    if (obj->barSize < 4) {
        obj->barStep -= (float)(4 - obj->barSize) / (float)hidden;
        obj->barSize = 4;
    }
    obj->barReady = 1;
}
