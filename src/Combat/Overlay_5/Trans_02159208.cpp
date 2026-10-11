#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02155d6c func_ov005_0215735c
#define func_ov005_02159c88 func_ov005_0215b1d4
#define func_ov005_0215a2c8 func_ov005_0215b81c
#define func_ov005_0215a37c func_ov005_0215b8d0
#define func_ov005_0215a3bc func_ov005_0215b910
#define func_ov005_0215a418 func_ov005_0215b96c
#define func_ov005_0215a620 func_ov005_0215bb74
#define func_ov005_0215a720 func_ov005_0215bc6c
#define func_ov005_0215aa44 func_ov005_0215bf64
#define func_ov005_0215ae7c func_ov005_0215c33c
#define func_ov005_0215b0a0 func_ov005_0215c4b4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" unsigned int _Z19GetField1c_021a193cPi(unsigned int);
extern "C" unsigned int _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(unsigned int, unsigned int);
extern "C" unsigned int func_ov005_0215792c(unsigned int, unsigned int);
extern "C" unsigned int func_ov017_0218b5b0(unsigned int, unsigned int);

// USA: func_ov005_02159208  (semantic: Trans_02159208)
extern "C" ARM unsigned int func_ov005_02159208(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = r4 + 0x3000;
    r0 = *(unsigned char*)((char*)r0 + R(0xd54, 0xddc));
    cc = (int)(r0) - (int)(0x0);
    if (cc != 0) { return r0; }
    r0 = r4 + R(0xee0, 0x2e4);
#if !defined(jpn)
    r0 = r0 + 0xc00;
#endif
    r1 = 0x1;
    r0 = (unsigned int)_Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(r0, r1);
    r0 = r4;
    r1 = 0x6;
    r0 = (unsigned int)func_ov005_0215792c(r0, r1);
    r0 = r4 + 0x3000;
    r1 = 0x0;
    *(unsigned char*)((char*)r0 + R(0xd54, 0xddc)) = (unsigned char)r1;
    *(unsigned char*)((char*)r0 + R(0xd56, 0xdde)) = (unsigned char)r1;
    *(unsigned char*)((char*)r0 + R(0xd57, 0xddf)) = (unsigned char)r1;
    r0 = (unsigned int)func_ov017_0218b5b0(r0, r1);
    r0 = r0 + 0x3000;
    r0 = *(unsigned int*)((char*)r0 + R(0x4f8, 0x708));
    r0 = (unsigned int)_Z19GetField1c_021a193cPi(r0);
    r0 = r0 + R(0x500, 0x600);
    r1 = *(unsigned short*)((char*)r0 + R(0x6c, 0x34));
    r1 = r1 | 0x81;
    *(unsigned short*)((char*)r0 + R(0x6c, 0x34)) = (unsigned short)r1;
    return r0;
}
