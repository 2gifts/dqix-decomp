#if defined(jpn)
#define R(j,u) (j)
#define _Z22SetupBattleTag02189d68Pc func_ov012_0218a804
#define _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20 func_ov023_021e7184
#define data_ov009_0218ac04 data_ov009_0218bb6c
#define data_ov013_02187d94 data_ov013_02188cd0
#define func_ov008_02187278 func_ov008_02188140
#define func_ov008_02187b20 func_ov008_021888fc
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov013_02185900 func_ov013_02186aec
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov008_02187b20(void* obj, void* ptr, int arg2);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

struct Manager02187a70 {
    char pad0[0xb8];
    void* ptrB8;
    char pad1[0x1d0 - 0xbc];
    unsigned short f1d0;
    unsigned short f1d2;
    unsigned short f1d4;
    unsigned short f1d6;
    unsigned short f1d8;
    unsigned short f1da;
    unsigned short f1dc;
    unsigned short f1de;
    char pad2[0x1e1 - 0x1e0];
    unsigned char f1e1;
    char pad3[0x1e5 - 0x1e2];
    unsigned char f1e5;
    unsigned char f1e6;
    unsigned char f1e7;
};

// USA: func_ov008_02187a70  (semantic: InitConfig02187a70)
extern "C" ARM void func_ov008_02187a70(Manager02187a70* obj, int arg1) {
    obj->f1d0 = 0x12;
    obj->f1d2 = R(0xc,0xb);
    obj->f1d4 = 0xd;
    obj->f1d6 = 3;
    obj->f1d8 = 2;
    obj->f1da = 1;
    obj->f1dc = 0xa;
    obj->f1de = 0xf;
    obj->f1e7 = 0xa;
    obj->f1e1 = 3;
    obj->f1e5 = 1;
    obj->f1e6 = 1;
    memset(obj->ptrB8, 0, R(0x800,0x960));
    func_ov008_02187b20(obj, obj->ptrB8, arg1);
#if defined(jpn)
    func_0205d304((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0);
#else
    func_0205d304((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0, 0);
#endif
}
