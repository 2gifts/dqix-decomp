#if defined(jpn)
enum {regionalOffset0=0xc8, regionalOffset1=0x4200, regionalOffset2=0x12};
#else
enum {regionalOffset0=0x2e8, regionalOffset1=0x4400, regionalOffset2=0xc2};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

int GetField0x3acValue(GameState* battleStruct);
void SetBitsInWord(unsigned int* obj, unsigned int mask);

struct Src_021b7104 {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned short f4;
    unsigned char pad6[2];
    unsigned int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char pad13[1];
    unsigned int f14;
};

struct Dst_021b7104 {
    unsigned char pad0[0x20];
    unsigned char f20;
    unsigned char f21;
    unsigned short f22;
    unsigned short f24;
    unsigned short f26;
    unsigned int f28;
    unsigned char pad2c[0x40 - 0x2c];
    unsigned char f40;
    unsigned char f41;
    unsigned char f42;
    unsigned char pad43[1];
    unsigned short f44;
    unsigned char f46;
    unsigned char pad47[1];
    unsigned int f48;
    unsigned char pad4c[0x51 - 0x4c];
    unsigned char f51;
};

// JPN: func_ov017_021b76b4
// USA: func_ov017_021b7104
extern "C" ARM void func_ov017_021b7104(Dst_021b7104* dst, Src_021b7104* src) {
    GameState* battle = GameState::GetInstance();
    GameResources* ov = func_ov017_0218b5b0();

    dst->f22 = src->f1;
    dst->f24 = src->f4;
    dst->f26 = src->f2;
    dst->f20 = src->f0;
    int val;
    if (src->f0 == 0) {
        val = -1;
    } else {
        val = GetField0x3acValue(battle);
    }
    dst->f46 = (unsigned char)val;
    dst->f28 = src->f8;
    dst->f41 = src->fd;
    dst->f40 = src->fc;
    dst->f42 = src->fe;
    dst->f44 = (unsigned short)src->f10;
    dst->f51 = src->ff;
    dst->f48 = src->f14;
    dst->f21 = src->f12;

    if (src->f0 != 0 && src->f14 == 0) {
        SetBitsInWord((unsigned int*)ov, 0x800);
    }

    *((unsigned char*)ov + 0x4000 + regionalOffset0) = 0;
    *(unsigned short*)((char*)ov + regionalOffset1 + regionalOffset2) = 0;
}
