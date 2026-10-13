#if defined(jpn)
#define func_ov005_02158b3c func_ov005_0215a110
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>
#include <Resource/GameResources.h>

struct Element020e0310;
struct Container020e0310 {
    unsigned int count : 12;
    unsigned int flags : 20;
    Element020e0310* entries;
};

extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(void* global);
extern "C" int* _Z19GetField1c_021a193cPi(int* p);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void* obj, int combatantId);
extern "C" void* __clear(void* dst, int count);
extern "C" void _Z20Clear12Bytes020e46c4Pv(void* p);
extern "C" short _Z20GetTableByte0215a930Pvi(void* obj, int index);
extern "C" void _Z31DispatchIfCountPositive020dcf7ciPv(int count, void* buf);
extern "C" char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* c, int key);
extern "C" void func_02046608(void* a, unsigned char b, const char* c, char* d, int e, int f, unsigned char g);

struct CombatantTail {
    char pad[LOW_REGION(0x4f8, 0x4fc)];
    int index;
};

struct Combatant_02158b3c {
    char pad000_[LOW_REGION(0x144, 0x150)];
    void* field150_;
};

struct Entry_02158b3c {
    char pad00_[0x18];
    short count_;
    char pad1a_[0x20 - 0x1a];
};

struct Global_02158b3c {
    char pad00_[0x10];
    void* field10_;
    void* field14_;
    void* field18_;
};

struct Local12_02158b3c {
    void* a_;
    void* b_;
    void* c_;
};

struct Buffers_02158b3c {
    char bufA_[0x80];
    char bufB_[0x80];
};

struct EquipmentSlot {
    short item;
    signed char count;
    unsigned char equipped;
    void* vramState;
    void* model;
    int x;
    int y;
    int offset;
    short loadedItem;
};

struct Menu_02158b3c {
    char pad00_[0xdf8];
    Container020e0310 messages;
    char padAfterMessages[LOW_REGION(0x2d08, 0x2d90) - 0xdf8 - sizeof(Container020e0310)];
    EquipmentSlot slots[24];
    char unknownAfterSlots[0x3dbb - 0x3030];
    signed char selectedSlot;
    unsigned char kind_;
    char pad0dbd_[LOW_REGION(0x3d44, 0x3dcc) - LOW_REGION(0x3d35, 0x3dbd)];
    unsigned int flags_;
    char pad3dd0_[LOW_REGION(0x3d49, 0x3dd1) - LOW_REGION(0x3d48, 0x3dd0)];
    unsigned char sel_;
};

#if defined(jpn)
extern "C" void func_020de968(int value, char* text);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void*, int, char*);
#endif

// USA: func_ov005_02158b3c
extern "C" ARM int func_ov005_02158b3c(void* object, void* buffer) {
    if (buffer == 0) return 0;
    Global_02158b3c* g = (Global_02158b3c*)_Z26GetGlobalField0x1c020421a0v();
    func_02046380(g);
    GameState* game = GameState::GetInstance();
#if defined(jpn)
    int id = ((CombatantTail*)_Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]))->index;
#else
    CombatantTail* tail = (CombatantTail*)_Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    int id = tail->index;
#endif
    Combatant_02158b3c* combatant = (Combatant_02158b3c*)GetCombatantWithFlag0x100(game, id);
    if (combatant == 0) return 0;

#if defined(jpn)
    _Z22SetIndexedName02046574P11Obj02046574iPc(g, 1, *(char**)((char*)combatant + 0x134));
#else
    Local12_02158b3c obj;
    _Z30InitObjFromCombatantId020e4bf4Pvi(&obj, id);
    g->field10_ = &obj;
    Buffers_02158b3c bufs;
    __clear(bufs.bufB_, 0x80);
    __clear(bufs.bufA_, 0x80);
    Local12_02158b3c s;
    _Z20Clear12Bytes020e46c4Pv(&s);
    s.a_ = bufs.bufB_;
    s.b_ = bufs.bufA_;

#endif
    Menu_02158b3c* menu = (Menu_02158b3c*)object;
    if (menu->flags_ & 0x8000) {
        unsigned char pick = _Z20GetTableByte0215a930Pvi(object, menu->kind_);
        Entry_02158b3c* e = (Entry_02158b3c*)((char*)combatant->field150_ + 0x194) + pick;
        if (e) {
            func_02046380(g);
#if defined(jpn)
            char name[0x40];
            __clear(name, 0x40);
            func_020de968(e->count_, name);
            _Z22SetIndexedName02046574P11Obj02046574iPc(g, 0, name);
#else
            _Z31DispatchIfCountPositive020dcf7ciPv(e->count_, &s);
            g->field18_ = &s;
#endif
        }
        menu->flags_ &= ~0x8000;
    } else {
        signed char slot = menu->selectedSlot;
        short value = menu->slots[slot].item;
#if defined(jpn)
        char name[0x40];
        __clear(name, 0x40);
        func_020de968(value, name);
        _Z22SetIndexedName02046574P11Obj02046574iPc(g, 0, name);
#else
        _Z31DispatchIfCountPositive020dcf7ciPv(value, &s);
        g->field18_ = &s;
#endif
    }

    int w = 0xe3;
    unsigned char sel = menu->sel_;
    int v = -1;
    if (sel <= 7) w = 0xb4;
    switch (sel) {
    case 0: break;
    case 2: v = 0x2711; break;
    case 3: v = 0x2712; break;
    case 1: v = 0x2713; break;
    case 4: v = 0x2714; break;
    case 5: v = 0x2715; break;
    case 6: v = 0x2716; break;
    case 7: v = 0x2717; break;
    case 8: v = 0x2af8; break;
    case 9: v = 0x2af9; break;
    case 10: v = 0x2afa; break;
    case 11: v = 0x2afb; break;
    case 12: v = 0x2afc; break;
    case 13: v = 0x2afd; break;
    case 14: v = 0x2afe; break;
    }

    if (v >= 0) {
        sprintf((char*)buffer, _Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, v));
    }
#if !defined(jpn)
    char text[0x800];
    __clear(text, 0x800);
    func_02046608(g, 10, (const char*)buffer, text, w, 0, 0);
    sprintf((char*)buffer, text);

#endif
    if (v >= 0x2af8) {
        if (v <= 0x2afe) return 1;
    }
    return 0;
}
