#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);

struct Obj02092aa4 {
    SafeAllocator allocator;
    char pad14[0x2c - 0x14];
    int field2c;
    short field30;
    short field32;
    unsigned char field34;
    unsigned char field35;
    unsigned char field36;
    unsigned char field37;
    unsigned char field38;
    unsigned char field39;
    unsigned char field3a;
    unsigned char field3b;
};

// USA: func_02092aa4
ARM void InitObj02092aa4(Obj02092aa4* obj, int param) {
    obj->allocator.ResetAllocatorPointer();
    ResetStruct020dfc40((struct Struct020dfc40*)((char*)obj + 0x14));

    obj->field2c = -1;
    obj->field30 = -1;
    obj->field32 = 0;
    obj->field34 = 0;
    obj->field35 = 0;
    obj->field36 = 0;
    obj->field37 = 0;
    obj->field38 = param;
    obj->field39 = 0;
    obj->field3a = 0;
    obj->field3b = 0;

    unsigned char* base = (unsigned char*)GetPtrField0x2a04(GameState::GetInstance());
    unsigned char i;
    for (i = 0; i < base[0xf7c]; i++) {
        unsigned char* entry = base + i;
        if (entry[0xf78] == 0) {
            obj->field37 |= 1;
            return;
        }
    }
}
