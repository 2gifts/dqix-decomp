#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct Bits11_021cac7c {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char nibble : 4;
};

struct Bits13_021cac7c {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
};

struct SrcEntry_021cac7c {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    short field8;
    short fielda;
    unsigned short fieldc;
    unsigned short fielde;
    unsigned char field10;
    struct Bits11_021cac7c bits11;
    unsigned char field12;
    struct Bits13_021cac7c bits13;
};

// USA: func_ov017_021cac7c
// JPN: func_ov017_021cb12c
extern "C" ARM void func_ov017_021cac7c(int unused0, struct SrcEntry_021cac7c* src, GameState* battleStruct, unsigned char* base) {
#if defined(jpn)
    void* table = *(void**)(base + 0x3000 + 0x508);
#else
    void* table = *(void**)(base + 0x3000 + 0x718);
#endif
    void* obj = GetField6b0_021b8470(table);
    if (obj == NULL) {
        return;
    }
    unsigned char* header = *(unsigned char**)((char*)obj + 0x8000 + 0xe18);
    if (header == NULL) {
        return;
    }
    if (*(signed char*)(header + 0x2a) == GetField0x3acValue(battleStruct)) {
        return;
    }
    if (*(unsigned short*)(header + 8) != src->field4) {
        return;
    }
    int idx = src->field6 - 0xc0;
    if (idx < 0) {
        return;
    }
    if (idx >= 8) {
        return;
    }
    unsigned char* dest = header + 0x158 + idx * 0xa4;
    *(short*)(dest + 0x32) = src->field8;
    *(short*)(dest + 0x34) = src->fielda;
    *(unsigned short*)(dest + 0x30) = src->fielde;
    *(dest + 0x38) = src->field10;
    ((struct Bits11_021cac7c*)(dest + 0x3b))->bit0 = src->bits11.bit0;
    ((struct Bits11_021cac7c*)(dest + 0x3b))->bit1 = src->bits11.bit1;
    ((struct Bits11_021cac7c*)(dest + 0x3b))->bit2 = src->bits11.bit2;
    ((struct Bits11_021cac7c*)(dest + 0x3b))->bit3 = src->bits11.bit3;
    ((struct Bits11_021cac7c*)(dest + 0x3b))->nibble = src->bits11.nibble;
    *(dest + 0x39) = 0;
    ((struct Bits13_021cac7c*)(dest + 0x3c))->bit0 = src->bits13.bit0;
    ((struct Bits13_021cac7c*)(dest + 0x3c))->bit1 = src->bits13.bit1;
    ((struct Bits13_021cac7c*)(dest + 0x3c))->bit2 = src->bits13.bit2;
    ((struct Bits13_021cac7c*)(dest + 0x3c))->bit3 = src->bits13.bit3;
    ((struct Bits13_021cac7c*)(dest + 0x3c))->bit4 = src->bits13.bit4;
    ((struct Bits13_021cac7c*)(dest + 0x3c))->bit5 = src->bits13.bit5;
    ((struct Bits13_021cac7c*)(dest + 0x3c))->bit6 = src->bits13.bit6;
    *(dest + 0x3d) = src->field12;
    *(unsigned short*)(dest + 0xc) = src->fieldc;
}
