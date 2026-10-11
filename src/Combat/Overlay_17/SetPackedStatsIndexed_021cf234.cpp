// JPN: func_ov017_021cf6e0
#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_02083e28(void* a, int arg2);

struct Idx8_cf234 {
    unsigned int idx : 8;
    unsigned int rest : 24;
};

struct Packed3c_cf234 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int fieldD : 2;
};

struct Src021cf234 {
    char pad[4];
    struct Packed3c_cf234 field4;
    struct Packed3c_cf234 field8;
    struct Packed3c_cf234 fieldc;
    unsigned int field10;
};

#if defined(jpn)
enum { PackedSlotOffset = 0x7b8 };
#else
enum { PackedSlotOffset = 0x850 };
#endif

// USA: func_ov017_021cf234  (semantic: SetPackedStatsIndexed_021cf234)
extern "C" ARM void func_ov017_021cf234(int unused0, struct Src021cf234* src, GameState* battleStruct) {
    unsigned int id = (src->field10 << 21) >> 29;
    GameObject* c = GetCombatantWithFlag0x100(battleStruct, id);
    if (!c) return;
    unsigned char* p = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
    if (!p) return;

    unsigned int idxWide = ((struct Idx8_cf234*)&src->field10)->idx;
    unsigned char idx = (unsigned char)idxWide;
    unsigned char* base = p + PackedSlotOffset + idx * 0xc;
    ((struct Packed3c_cf234*)(base + 0))->fieldA = src->field4.fieldA;
    ((struct Packed3c_cf234*)(base + 0))->fieldB = src->field4.fieldB;
    ((struct Packed3c_cf234*)(base + 0))->fieldC = src->field4.fieldC;
    ((struct Packed3c_cf234*)(base + 4))->fieldA = src->field8.fieldA;
    ((struct Packed3c_cf234*)(base + 4))->fieldB = src->field8.fieldB;
    ((struct Packed3c_cf234*)(base + 4))->fieldC = src->field8.fieldC;
    ((struct Packed3c_cf234*)(base + 8))->fieldA = src->fieldc.fieldA;
    ((struct Packed3c_cf234*)(base + 8))->fieldB = src->fieldc.fieldB;
    ((struct Packed3c_cf234*)(base + 8))->fieldC = src->fieldc.fieldC;

    unsigned int flag = (src->field10 << 20) >> 31;
    if (flag) {
        func_02083e28(p, 0);
    }
}
