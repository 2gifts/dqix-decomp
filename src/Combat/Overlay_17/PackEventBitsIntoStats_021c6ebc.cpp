// JPN: func_ov017_021c736c
#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x508 };
#else
enum { kRegionalFieldOffset = 0x718 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);
struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

struct PackedBits021c6ebc {
    unsigned short fieldA : 2;
    unsigned short fieldB : 4;
    unsigned short fieldC : 3;
    unsigned short state : 3;
    unsigned short : 4;
};

struct SrcEntry021c6ebc {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    struct PackedBits021c6ebc bits8;
    unsigned char fielda;
    unsigned char pad_b;
    unsigned short fieldc;
    unsigned short fielde;
};

// USA: func_ov017_021c6ebc  (semantic: PackEventBitsIntoStats_021c6ebc)
extern "C" ARM void func_ov017_021c6ebc(int unused0, struct SrcEntry021c6ebc* src, GameState* battleStruct, unsigned char* base) {
    unsigned char* table = *(unsigned char**)(base + 0x3000 + kRegionalFieldOffset);
    unsigned char* obj = (unsigned char*)func_ov017_021b8478(table);
    if (obj == 0) {
        return;
    }
    if (func_ov017_021b8468(table) == 0) {
        return;
    }
    if (GetField6b0_021b8470(table) == 0) {
        return;
    }
    if (*(signed char*)(obj + 0x2a) == GetField0x3acValue(battleStruct)) {
        return;
    }
    if (*(unsigned short*)(obj + 8) != src->field4) {
        return;
    }
    GameObject* combatant = battleStruct->GetCombatantByIndex(src->field6);
    if (combatant == 0) {
        return;
    }
    struct PackedBits021c6ebc* dst;
    unsigned char a = src->bits8.fieldA;
    dst = (struct PackedBits021c6ebc*)((unsigned char*)combatant->currentStats_ + 0x22);
    dst->fieldA = a;
    unsigned char b = src->bits8.fieldB;
    dst = (struct PackedBits021c6ebc*)((unsigned char*)combatant->currentStats_ + 0x22);
    dst->fieldB = b;
    unsigned char c = src->bits8.fieldC;
    dst = (struct PackedBits021c6ebc*)((unsigned char*)combatant->currentStats_ + 0x22);
    dst->fieldC = c;
    unsigned char st = src->bits8.state;
    SetStateAndByte0x6a((struct Obj02088818*)combatant->currentStats_, st);
    *((unsigned char*)combatant->currentStats_ + 0x24) = src->fielda;
    *(unsigned short*)((unsigned char*)combatant->currentStats_ + 4) = src->fieldc;
    *(unsigned short*)((unsigned char*)combatant->currentStats_ + 6) = src->fielde;
}
