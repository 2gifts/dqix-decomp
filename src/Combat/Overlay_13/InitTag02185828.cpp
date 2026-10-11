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

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

extern "C" void func_ov013_02185900(void* obj, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

extern int data_ov013_02187d94;

// USA: func_ov013_02185828
ARM void InitTag02185828(unsigned char* obj) {
    unsigned char flags6bc = obj[R(0x644,0x6bc)];
    obj[R(0x644,0x6bc)] = flags6bc & ~1;

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + R(0x34,0x38)), 0, 2);

    *(unsigned short*)(obj + R(0xd4,0xd8)) = 0x20;
    *(unsigned short*)(obj + R(0xd6,0xda)) = 9;
    *(unsigned short*)(obj + R(0xd8,0xdc)) = 0;
    *(unsigned short*)(obj + R(0xda,0xde)) = 0xf;
    *(unsigned short*)(obj + R(0xdc,0xe0)) = 0xc;
    *(unsigned short*)(obj + R(0xde,0xe2)) = 0xa;
    *(unsigned short*)(obj + R(0xe0,0xe4)) = 0xc;
    *(unsigned short*)(obj + R(0xe2,0xe6)) = 0x14;
    obj[R(0xe5,0xe9)] = 2;

    if (obj[R(0x5cc,0x640)] != 0) obj[R(0xe9,0xed)] = 0;
    else obj[R(0xe9,0xed)] = 1;

    obj[R(0x5c6,0x63a)] = 0;

    memset(*(void**)(obj + R(0x5e0,0x658)), 0, R(0x800,0x960));

    func_ov013_02185900(obj, *(void**)(obj + R(0x5e0,0x658)));

#if defined(jpn)
    func_0205d304(obj + R(0x34,0x38), *(void**)(obj + R(0x5e0,0x658)), 0, 0, 0, 1, (int)&data_ov013_02187d94);
#else
    func_0205d304(obj + R(0x34,0x38), *(void**)(obj + R(0x5e0,0x658)), 0, 0, 0, 1, (int)&data_ov013_02187d94, 1);
#endif
}
