#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct BattleMenuState02158dcc {
    char pad00[0xe];
    short selectedId;
    char pad10;
    unsigned char count;
    signed char field_0x12;
    char pad13[0x1e];
    unsigned char resetPos;
    char pad32[0x8];
    short level;
    char pad3c[0xb];
    unsigned char field_0x47;
    char pad48[0x44];
    unsigned char table[1];
};

struct StateHolder02158dcc { char pad[8]; BattleMenuState02158dcc* ptr; };
extern StateHolder02158dcc data_ov004_021707d8;

struct Entry02158dcc {
    short id;
    short pad2;
    unsigned int count : 7;
    unsigned int cost : 25;
};

struct Element02158dcc {
    char pad[8];
    unsigned int kind : 4;
    char padc[0xc];
    short nameId;
};

struct Wallet02158dcc {
    char pad[0xf6c];
    unsigned int gold;
};

struct Message02158dcc {
    char pad[0x18];
    int name;
};

struct Marker02158dcc {
    char pad[0x2c];
    Vector3i pos;
};

struct Container020dedd0;
struct Fields021849e0;

int DispatchNodeIfType7_02156e2c(void* a, int key);
Entry02158dcc* GetEntryFor_021570a4(void* obj, int index);
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
Element02158dcc* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
int CallFunc020e52a0(void* p, int key);
Message02158dcc* GetGlobalField0x1c020421a0(void);
extern "C" int func_ov004_0215799c(void* a, int e, unsigned int kind, int d);
void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov004_0215d6f8(void* obj);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
extern "C" Marker02158dcc* func_ov004_02156ed0(void* obj, int key);
extern "C" void __clear(void* buf, int size);

// USA: func_ov004_02158dcc
extern "C" ARM int func_ov004_02158dcc(void* obj) {
    int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (key < 0) return 0;
    Entry02158dcc* entry = GetEntryFor_021570a4(obj, (unsigned char)key);
    if (!entry) return 0;
    Element02158dcc* elem = FindElementByKey020dedd0(func_ov004_02156fd4(obj, 5), entry->id);
    if (!elem) return 0;
    int name = CallFunc020e52a0(data_ov004_021707d8.ptr->table, elem->nameId);
    GetGlobalField0x1c020421a0()->name = name;
    if (entry->count == 0) return 0;

    Wallet02158dcc* wallet = (Wallet02158dcc*)GetPtrField0x2a04(GameState::GetInstance());
    if (func_ov004_0215799c(wallet, entry->id, elem->kind, data_ov004_021707d8.ptr->level) == 0) {
        SetFieldConditional_021849e0((struct Fields021849e0*)obj, 0);
        func_ov011_021848a0(obj, 0x236b);
        return 0;
    }
    if (wallet->gold < entry->cost) {
        SetFieldConditional_021849e0((struct Fields021849e0*)obj, 0);
        func_ov011_021848a0(obj, 0x2365);
        return 0;
    }

    func_ov011_021848a0(obj, 0x5e);
    data_ov004_021707d8.ptr->selectedId = entry->id;
    data_ov004_021707d8.ptr->count = 1;
    data_ov004_021707d8.ptr->field_0x12 = -1;
    data_ov004_021707d8.ptr->field_0x47 = 0;
    if (entry->count == 1 || (entry->cost <= wallet->gold && wallet->gold < entry->cost * 2)) {
        SetFieldConditional_021849e0((struct Fields021849e0*)obj, 0);
        func_ov004_0215d6f8(obj);
    }
    func_ov023_021f65d4(obj, 0x35, 0x18);
    func_ov023_021f65d4(obj, 0x34, 0x10);
    if (data_ov004_021707d8.ptr->resetPos) {
        Marker02158dcc* marker = func_ov004_02156ed0(obj, 0x5b);
        Vector3i zero;
        __clear(&zero, sizeof(zero));
        Vector3i tmp = zero;
        marker->pos = tmp;
        data_ov004_021707d8.ptr->resetPos = 0;
    }
    return 0;
}
