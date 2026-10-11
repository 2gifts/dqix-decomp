#include <globaldefs.h>
#include "GameState/GameState.h"


struct KeyedList0207c484;
int DecrementKeyedStackAmount0207c484(struct KeyedList0207c484* obj, int value, int amount, int key);
struct KeyMap020a0a08;
int DecrementKeyValue020a0a08(struct KeyMap020a0a08* map, int key, int amount);
int GetFieldAt0x150(unsigned char* obj);
struct Slots020838c4;
int RemoveSlotValueAndCompact020838c4(struct Slots020838c4* s, int value);
void* ResetCombatantFields_0215a2f8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Struct021707d8_0215b1d4 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215b1d4 data_ov004_021707d8;

struct Bits0xc_0215b1d4 { unsigned short low13 : 13; unsigned short high3 : 3; };

#if defined(jpn)
extern "C" void* GetPtrField0x2a04(GameState*);
extern "C" GameObject* GetCombatantWithFlag0x100(GameState*, int);

#else
#endif
// USA: func_ov004_0215b1d4
// JPN: func_ov004_0215c208
extern "C" ARM int func_ov004_0215b1d4(void* obj) {
    GameState* bs = GameState::GetInstance();
#if defined(jpn)
    char* base = (char*)bs + 0xc + 0x5c00;
#else
    char* base = (char*)bs + 0x26c + 0x5c00;
#endif

    *(short*)(base + 0xf8) = *(short*)(data_ov004_021707d8.ptr + 0x6c);
    *(short*)(base + 0xfa) = *(unsigned char*)(data_ov004_021707d8.ptr + 0x6e);
    *(short*)(base + 0xfc) = *(int*)(data_ov004_021707d8.ptr + 0x78);

    int cnt = *(int*)(data_ov004_021707d8.ptr + 0x74);
    if (cnt >= 0) {
        void* result = GetPtrField0x2a04(bs);
        if (!result) return 0;
        short key = *(short*)(data_ov004_021707d8.ptr + 0x6c);
        signed char amt = *(signed char*)(data_ov004_021707d8.ptr + 0x6e);
        int key2 = *(int*)(data_ov004_021707d8.ptr + 0x74);
        DecrementKeyedStackAmount0207c484((struct KeyedList0207c484*)((char*)result + 0x1d4), key, amt, key2);
    } else if (*(signed char*)(data_ov004_021707d8.ptr + 0x70) == -1) {
        void* result = GetPtrField0x2a04(bs);
        if (!result) return 0;
        short key = *(short*)(data_ov004_021707d8.ptr + 0x6c);
        signed char amt = *(signed char*)(data_ov004_021707d8.ptr + 0x6e);
        DecrementKeyValue020a0a08((struct KeyMap020a0a08*)result, key, amt);
    } else {
        int combatantId = *(signed char*)(data_ov004_021707d8.ptr + 0x70);
        GameObject* c = GetCombatantWithFlag0x100(bs, combatantId);
        if (!c) return 0;
        int field = GetFieldAt0x150((unsigned char*)c);
        short key = *(short*)(data_ov004_021707d8.ptr + 0x6c);
        RemoveSlotValueAndCompact020838c4((struct Slots020838c4*)field, key);
    }

    ResetCombatantFields_0215a2f8(data_ov004_021707d8.ptr);

    Bits0xc_0215b1d4* bits = (Bits0xc_0215b1d4*)(base + 0x10c);
    bits->low13 |= 0x10;

    unsigned char v = *(data_ov004_021707d8.ptr + 0x6e);
    if (v > 1) {
        func_ov011_021848a0(obj, 0x2423);
    } else {
        func_ov011_021848a0(obj, 0x39d);
    }
    return 0;
}
