#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Struct02170fd0;
extern "C" void _Z28UpdateSlotStatField_02175754Pv(void* obj);
extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
extern "C" void _Z27CallHandlerIfF38Set02170fd0P14Struct02170fd0i(struct Struct02170fd0* obj, int b);

struct Slot_0217fa60 {
    char pad0[0x24];
    unsigned char field24;
    char pad25[0x4c - 0x25];
    int field4c;
    char pad50[0x87 - 0x50];
    unsigned char active;
    char pad88[0x445 - 0x88];
    unsigned char field445;
    char pad446[0x448 - 0x446];
};

struct Party_0217fa60 {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Owner_0217fa60 {
    char pad0[0x6c];
    signed char order[4];
    char pad70[0x17c - 0x70];
    int selected;
    char pad180[0x958 - 0x180];
    struct Slot_0217fa60 slots[4];
};

static inline struct Slot_0217fa60* GetSlot(struct Owner_0217fa60* obj, int index) {
    return &obj->slots[index];
}

static inline int IsValidSlotIndex(int index) {
    return index >= 0 && index <= 3;
}

// USA: func_ov000_0217fa60
extern "C" ARM void func_ov000_0217fa60(struct Owner_0217fa60* obj) {
    _Z28UpdateSlotStatField_02175754Pv(obj);
    for (unsigned char i = 0; i < 4; i++) {
        GetSlot(obj, obj->order[i])->active = 0;
    }
    struct Party_0217fa60* party = (struct Party_0217fa60*)GetPtrField0x2a04(GameState::GetInstance());
    for (unsigned char i = 0; i < party->count; i++) {
        GetSlot(obj, party->ids[i])->active = 1;
    }
    struct Slot_0217fa60* slot;
    int first = -1;
    for (int i = 0; i < 4; i++) {
        slot = &obj->slots[obj->order[i]];
        if (slot->field4c < 0) continue;
        if (slot->active == 0) continue;
        if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)slot)) continue;
        if (slot->field445 == 0) continue;
        _Z27CallHandlerIfF38Set02170fd0P14Struct02170fd0i((struct Struct02170fd0*)slot, 0);
        slot->field24 &= ~4;
        if (first < 0) {
            first = slot->field4c;
        }
    }
    if (IsValidSlotIndex(first)) {
        obj->selected = first;
    }
}
