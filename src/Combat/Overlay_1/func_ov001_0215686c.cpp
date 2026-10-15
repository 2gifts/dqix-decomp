#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "System/BGBases.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

struct Q0215686c {
    char pad[0xd2];
    short v;
};

struct Obj0215686c {
    char pad0[0xa];
    unsigned short fa;
    char padc[0x16 - 0xc];
    unsigned short f16;
    char pad18[0x50 - 0x18];
    unsigned short f50;
    char pad52[0xcf - 0x52];
    unsigned char fcf;
    char padd0[0x104 - 0xd0];
    unsigned char f104;
    char pad105[4];
    unsigned char f109;
    char pad10a[0x120 - 0x10a];
    Q0215686c* q;
};

struct Holder0215686c {
    char pad[0x734];
    Obj0215686c* o;
};

struct ResPtr0215686c {
    char pad[0x2c];
    unsigned char* p2c;
};

int GetBitsInField0_0203b4c4(unsigned int* p, unsigned int bits);
int GetSignedField020c39c8(volatile unsigned short* p);
struct AxisFloats0203b57c;
int GetAxisIntValue(AxisFloats0203b57c*, int);
extern "C" void* func_0202ae18(void);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
void OrGlobalFlag0x40_020dc2bc();
void ResetList0204af64(struct List0204af64* obj);

static inline unsigned int GetEntryMode(Obj0215686c* o) {
    return o->fa;
}

// USA: func_ov001_0215686c
extern "C" ARM void func_ov001_0215686c(void) {
    struct List0204af64 list;
    char buf[0x20];

    int vbl = (*(unsigned short*)0x4000304 & 0x8000) >> 15;
    int flag = 1;
    if (vbl == 1) {
        flag = 0;
    }

    GameResources* res = func_ov017_0218b5b0();
    int axis = GetAxisIntValue((AxisFloats0203b57c*)res, 1);
    if (flag == 0) {
        axis = GetSignedField020c39c8((volatile unsigned short*)0x0400006c);
    }

    if (axis != -0x10 && axis != 0x10) {
        return;
    }
    if (flag == 0) {
        return;
    }

    Obj0215686c* o = ((struct Holder0215686c*)((char*)res + 0x3000))->o;
    Q0215686c* q = o->q;
    func_0202ae18();

    if (!(o->f50 & 0x20)) {
        if (GetBitsInField0_0203b4c4((unsigned int*)res, 0x1000) == 0) {
            goto cont;
        }
    }
    if (o->f50 & 0x100) {
        goto cont;
    }
    if ((o->f50 & 2) && q != 0) {
        if (q->v < 0) {
            goto cont;
        }
    }
    if (o->fa != 5) {
        return;
    }
cont:
    if (o->f16 == 0xc69a || o->f16 == 0xc9e1) {
        return;
    }
    if (o->f16 == 1 && o->fcf == 2) {
        if (o->f109 != 0) {
            return;
        }
    }

    OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 1);
    OrGlobalFlag0x40_020dc2bc();

    volatile unsigned int* r32 = (volatile unsigned int*)0x4001000;
    volatile unsigned short* r16 = (volatile unsigned short*)0x4001000;
    *r32 = (*r32 & ~0x1f00) | 0x1800;
    r16[7] = (r16[7] & 0x43) | 0xd00;
    r16[4] = r16[4] & ~3;
    r16[5] = (r16[5] & ~3) | 2;
    r16[6] = (r16[6] & ~3) | 3;
    r16[7] = (r16[7] & ~3) | 1;
    r32[4] = 0;
    r32[5] = 0;
    r32[6] = 0;
    r32[7] = 0;
    r16[0x28] = 0;

    ResetList0204af64(&list);
    list.b1c_lo = 3;

    unsigned char* p = ((struct ResPtr0215686c*)res)->p2c;
    CleanInvalidateCacheRange(p + 0xc, 0x20);
    LoadToSubBGStandardPalette(p + 0xc, 0, 0x20);
    CleanCacheRange(p + 0xc, 0x20);

    memset(buf, 0xff, 0x20);
    if (axis == -0x10) {
        memset(buf, 0x11, 0x20);
    }
    CleanInvalidateCacheRange(buf, 0x20);
    LoadToSubBG3CharacterData(buf, 0x6000, 0x20);
    CleanCacheRange(buf, 0x20);

    unsigned short* scr = (unsigned short*)GetSubBG3ScreenBase();
    for (unsigned short i = 0; i < 0x300; i++) {
        *scr++ = 0x300;
    }

    o->f104 = 1;

    unsigned int fa;
    int t = (q == 0 || (q != 0 && q->v < 0)) ? 1 : 0;
    fa = GetEntryMode(o);
    if (fa >= 3 && t != 0) {
        SetSubBrightness(res, 0, 0);
        o->f109 = 1;
    }
}
