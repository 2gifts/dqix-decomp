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

extern "C" unsigned char* _Z19GetField1c_021a193cPi(int);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(unsigned char*, int);
extern "C" void func_ov005_0215792c(unsigned char*, int);
extern "C" unsigned char* func_ov017_0218b5b0(void);

// USA: func_ov005_02159208  (semantic: Trans_02159208)
extern "C" ARM void func_ov005_02159208(unsigned char* self) {
    if (self[R(0x3d54, 0x3ddc)] != 0) {
        return;
    }
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(self + R(0xee0, 0xee4), 1);
    func_ov005_0215792c(self, 6);
    self[R(0x3d54, 0x3ddc)] = 0;
    self[R(0x3d56, 0x3dde)] = 0;
    self[R(0x3d57, 0x3ddf)] = 0;
    *(unsigned short*)(_Z19GetField1c_021a193cPi(*(int*)(func_ov017_0218b5b0() + R(0x34f8, 0x3708))) + R(0x56c, 0x634)) |= 0x81;
}
