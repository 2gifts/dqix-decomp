// JPN: func_ov017_021cab8c
#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x3508 };
#else
enum { kRegionalFieldOffset = 0x3718 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct SlotBits_021ca6dc {
    unsigned short field0 : 2;
    unsigned short field2 : 4;
    unsigned short field6 : 3;
    unsigned short field9 : 3;
    unsigned short field12 : 2;
    unsigned short field14 : 2;
};

struct SlotObj_021ca6dc {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short field0xa;
    char pad1[0x22 - 0xc];
    struct SlotBits_021ca6dc bits;
    unsigned char field0x24;
    unsigned char field0x25;
};

struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

struct EventSrc_021ca6dc {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    struct SlotBits_021ca6dc bits8;
    unsigned char field0xa;
    unsigned char field0xb;
    unsigned short field0xc;
    unsigned short field0xe;
    unsigned short field0x10;
    unsigned short field0x12;
};

// USA: func_ov017_021ca6dc
extern "C" ARM void func_ov017_021ca6dc(void* unused0, struct EventSrc_021ca6dc* src, GameState* battleStruct, char* data) {
    void* p1c = func_ov017_021b8478(*(void**)(data + kRegionalFieldOffset));
    if (!p1c) {
        return;
    }
    int val = GetField0x3acValue(battleStruct);
    if (*(signed char*)((char*)p1c + 0x2a) == val) {
        return;
    }
    if (*(unsigned short*)((char*)p1c + 0x8) != src->field4) {
        return;
    }
    int idx = src->field6 - 0xc0;
    if (idx < 0) {
        return;
    }
    if (idx >= 8) {
        return;
    }
    struct SlotObj_021ca6dc* slot = (struct SlotObj_021ca6dc*)((char*)p1c + 0x158 + idx * 0xa4);
    unsigned char f0 = src->bits8.field0;
    slot->bits.field0 = f0;
    unsigned char f2 = src->bits8.field2;
    slot->bits.field2 = f2;
    unsigned char f6 = src->bits8.field6;
    slot->bits.field6 = f6;
    unsigned char f9 = src->bits8.field9;
    SetStateAndByte0x6a((struct Obj02088818*)slot, f9);
    unsigned char f12 = src->bits8.field12;
    slot->bits.field12 = f12;
    slot->field0x24 = src->field0xa;
    slot->field0x25 = src->field0xb;
    slot->field4 = src->field0xc;
    slot->field6 = src->field0xe;
    slot->field8 = src->field0x10;
    slot->field0xa = src->field0x12;
}
