#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Struct020dfc40;
struct InitTarget0205cfd4;
struct List0204af64;
struct Struct020a9ea4;

struct Flags0215505c {
    unsigned char b0 : 1;
    unsigned char rest : 7;
};

extern "C" void *_Z20Clear12Bytes020e46c4Pv(void *p);
extern "C" void _Z17ClearObj_021e1318P11Obj021e1318(void *obj);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40 *s);
extern "C" void func_02074af4(void *state);
extern "C" void _Z18InitStruct0205cfd4P18InitTarget0205cfd4(struct InitTarget0205cfd4 *t);
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64 *l);
extern "C" void func_0204c684(void *p);
extern "C" void *memset(void *dst, int value, unsigned int length);
int CopyOutRegion0x5718(char *obj, void *dst);
extern "C" char *func_0205ec34(void);
extern "C" unsigned short _Z20BuildBitmask0206e384Ph(unsigned char *obj);
extern "C" short _Z25GetShortFromTable0206e3d4ii(int unused, int index);
extern "C" void func_ov002_0215b234(char *self);
extern "C" void _Z19ClearStruct020a9ea4P14Struct020a9ea4(struct Struct020a9ea4 *s);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov002_0215b814(char *base);

extern "C" unsigned char data_ov002_0216d3ac;

#define RESET(off) ((SafeAllocator *) (self + (off)))->ResetAllocatorPointer()
#define S16(off) (*(short *) (self + (off)))
#define S32(off) (*(int *) (self + (off)))
#define U8(off) (*(unsigned char *) (self + (off)))
#define S8(off) (*(signed char *) (self + (off)))

// USA: func_ov002_0215505c
extern "C" ARM void func_ov002_0215505c(char *self) {
    unsigned char buf[4];
    _Z20Clear12Bytes020e46c4Pv(self + 8);
    _Z20Clear12Bytes020e46c4Pv(self + 0x14);
    RESET(0x88c);
    RESET(0x878);
    RESET(0x850);
    RESET(0x864);
    RESET(0x83c);
    RESET(0x828);
    RESET(0x810);
    _Z17ClearObj_021e1318P11Obj021e1318(self + 0x804);
    RESET(0x8a0);
    _Z19ResetStruct020dfc40P14Struct020dfc40((struct Struct020dfc40 *) (self + 0x20));
    U8(0x48) = 0;
    U8(0x49) = 0;
    func_02074af4(self + 0x38);
    S32(0x4c)                            = (*(volatile unsigned int *) 0x4000000 & 0x1f00) >> 8;
    *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1ba4) = -1;
    }
    _Z18InitStruct0205cfd4P18InitTarget0205cfd4((struct InitTarget0205cfd4 *) (self + 0x2c8 + 0xc00));
    for (int i = 0; i < 3; i++) {
        _Z17ResetList0204af64P12List0204af64((struct List0204af64 *) (self + 0x384 + 0xc00 + i * 0x20));
    }
    for (int i = 0; i < 12; i++) {
        func_0204c684(self + 0x3e4 + 0xc00 + i * 0xe0);
    }
    S32(0x1a64) = 0;
    S32(0x1a68) = 0;
    for (int i = 0; i < 4; i++) {
        memset(self + 0xa70 + 0x1000 + i * 0x10, 0, 4);
        memset(self + 0xab0 + 0x1000 + i * 0x3c, 0, 4);
    }
    S32(0x1ba0) = 0;
    S32(0x1bb8) = 0;
    S32(0x1bbc) = 0x2b;
    S32(0x1bc0) = 0;
    S32(0x1bc4) = -1;
    S32(0x2458) = -1;
    S32(0x1bc8) = 0;
    S32(0x1bcc) = 0;
    S32(0x1bd0) = 0;
    S32(0x1bd4) = 0;
    S32(0x1bd8) = 0;
    S32(0x1bdc) = 0;
    for (int i = 0; i < 2; i++) {
        *(int *) (self + i * 4 + 0x2490) = 0;
    }
    S16(0x1be0)         = 0;
    S16(0x1be2)         = -1;
    S16(0x1be4)         = -1;
    S16(0x1be6)         = -1;
    S16(0x1be8)         = -1;
    S16(0x1bea)         = -1;
    S16(0x1bec)         = -1;
    S16(0x1bee)         = -1;
    S16(0x1bf0)         = -1;
    S16(0x1bf2)         = -1;
    S16(0x1bf4)         = -1;
    S16(0x1bf6)         = -1;
    S16(0x1bf8)         = -1;
    S16(0x1bfa)         = -1;
    S16(0x1bfc)         = -1;
    S16(0x1bfe)         = -1;
    S16(0x1c00)         = 1;
    S16(0x1c02)         = -1;
    S16(0x1c04)         = -1;
    S16(0x1c06)         = -1;
    S16(0x1c08)         = -1;
    U8(0x2454)          = 0;
    U8(0x2455)          = 0;
    S16(0x1c0a)         = 0;
    S16(0x1c0c)         = 0;
    S16(0x1c0e)         = 0;
    S16(0x1c10)         = 0;
    S16(0x1c12)         = 0;
    S16(0x1c14)         = 0;
    S16(0x1c16)         = 0;
    S16(0x1c18)         = 0;
    S32(0x1c1c)         = 0;
    U8(0x1cac)          = 0;
    U8(0x1cad)          = 0;
    U8(0x1cb0)          = 0;
    U8(0x1cae)          = 0;
    U8(0x1caf)          = 0;
    U8(0x1cb1)          = 0;
    U8(0x1cc2)          = 0;
    U8(0x1cc5)          = 0;
    S32(0x2448)         = 0;
    S32(0x244c)         = 0;
    S32(0x2450)         = 0;
    U8(0x2456)          = 0;
    S16(0x245c)         = 0;
    S32(0x2460)         = 0;
    S32(0x2464)         = 0;
    S32(0x2468)         = 0;
    S32(0x246c)         = 0;
    U8(0x2470)          = 0;
    U8(0x2471)          = 0;
    U8(0x2472)          = 0;
    S8(0x1c20)          = -1;
    S8(0x1c21)          = -1;
    S16(0x1c22)         = -1;
    S16(0x1c24)         = -1;
    S16(0x1c26)         = -1;
    S16(0x1c2a)         = -1;
    S16(0x1c28)         = S16(0x1c2a);
    U8(0x1c2e)          = 0;
    U8(0x1c2f)          = 0;
    U8(0x1c30)          = 0;
    U8(0x1c31)          = 0;
    U8(0x1c32)          = 0;
    data_ov002_0216d3ac = 0;
    U8(0x1c33)          = 0;
    U8(0x1c34)          = 0;
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1c3c) = -1;
    }
    for (int i = 0; i < 5; i++) {
        *(int *) (self + i * 4 + 0x1c54) = -1;
    }
    for (int i = 0; i < 5; i++) {
        *(unsigned char *) (self + i + 0x1c68) = 0;
    }
    U8(0x1c6d)                              = 0;
    U8(0x1c83)                              = 0;
    U8(0x1c84)                              = 0;
    ((Flags0215505c *) (self + 0x1c85))->b0 = 0;
    U8(0x1c78)                              = 0;
    S32(0x1c74)                             = 0;
    U8(0x1c79)                              = 2;
    U8(0x1c7a)                              = 0;
    U8(0x1c7b)                              = 0;
    S8(0x1c73)                              = 0;
    GameState *gs                           = GameState::GetInstance();
    S32(0x1c38)                             = CopyOutRegion0x5718((char *) gs, buf);
    for (int i = 0; i < S32(0x1c38); i++) {
        *(int *) (self + i * 4 + 0x1c3c) = buf[i];
        GameObject *m                    = gs->GetPartyMemberByIndex(buf[i]);
        if (m != 0 && *(int *) ((char *) m + 0x1c4) == 0) {
            *(unsigned char *) (self + S8(0x1c73) + 0x1c6e) = buf[i];
            S8(0x1c73)++;
        }
    }
    S32(0x1c50) = CopyOutRegion0x5718((char *) gs, buf);
    for (int i = 0; i < S32(0x1c50); i++) {
        *(int *) (self + i * 4 + 0x1c54) = buf[i];
    }
    *(int *) (self + S32(0x1c50) * 4 + 0x1c54) = 4;
    S32(0x1c50) += 1;
    U8(0x1cc3)        = 0;
    U8(0x2478)        = 0;
    U8(0x247a)        = 0;
    char *x           = func_0205ec34();
    unsigned int bits = (_Z20BuildBitmask0206e384Ph((unsigned char *) x) << 16) | 0xffff;
    S32(0x2480)       = 0;
    for (int i = 0; i < 0x20; i++) {
        if (bits & 1) {
            short n = _Z25GetShortFromTable0206e3d4ii((int) x, (short) (i + 1));
            *(unsigned int *) (self + 0x2480) |= 1 << (n - 1);
        }
        bits >>= 1;
    }
    U8(0x2484) = 0;
    memset(self + 0x7c + 0x1c00, -1, 7);
    U8(0x247b)  = 0;
    S32(0x247c) = 0;
    U8(0x2485)  = 0;
    U8(0x2486)  = 0;
    U8(0x2487)  = 0;
    S16(0x2488) = -1;
    U8(0x248a)  = 0;
    U8(0x248c)  = 0;
    U8(0x248d)  = 0;
    U8(0x2521)  = 0;
    U8(0x2522)  = 0;
    U8(0x2523)  = 0;
    memset(self + 0x124 + 0x2400, 0, 0xc);
    S32(0x2530) = 0;
    S32(0x2534) = 0;
    S32(0x2538) = 0;
    func_ov002_0215b234(self);
    RESET(0x810);
    RESET(0x828);
    RESET(0x83c);
    RESET(0x850);
    RESET(0x864);
    RESET(0x878);
    RESET(0x88c);
    _Z19ClearStruct020a9ea4P14Struct020a9ea4((struct Struct020a9ea4 *) (self + 0x98 + 0x2400));
    for (unsigned char j = 0; j < 0x20; j++) {
        *(int *) (self + j * 4 + 0x24a0) = 0;
    }
    U8(0x2520)  = 0;
    S16(0x2548) = 0;
    S16(0x254a) = 0;
    S32(0x254c) = 0;
    func_ov016_0218b5c0(1, -1);
    U8(0x248e) = 0;
    U8(0x248f) = 0;
    func_ov002_0215b814(self);
}
