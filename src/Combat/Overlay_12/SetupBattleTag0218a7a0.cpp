#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void* obj, int a1, int a2, int a3);
extern "C" void func_ov012_0218a844(void* obj, void* buf, int a2);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufStruct0218a7a0 { char pad[LOW_REGION(0x344, 0x374)]; void* buf; };

// USA: func_ov012_0218a7a0
#if defined(jpn)
extern "C" ARM void func_ov012_0218b234(char* base)
#else
ARM void SetupBattleTag0218a7a0(char* base)
#endif
 {
    unsigned char flag = *(unsigned char*)(base + 0x1000 + LOW_REGION(0x341, 0x371));
    func_ov012_021893b4(base, flag, LOW_REGION(3, 0), 1);

    memset(((struct BufStruct0218a7a0*)(base + 0x1000))->buf, 0, LOW_REGION(0x800, 0x960));

    func_ov012_0218a844(base, ((struct BufStruct0218a7a0*)(base + 0x1000))->buf, 0);

    unsigned short raw = *(unsigned short*)(base + LOW_REGION(0x1400 + 0x1c, 0x1300 + 0xc4));
    unsigned int t = ((unsigned int)raw << 16) >> 21;
    int tm1 = t - 1;
#if defined(jpn)
    if ((tm1 / 16) > 0)
        func_0205d304(base + 0x90, ((struct BufStruct0218a7a0*)(base + 0x1000))->buf, 0, 0, 1, 1, 0);
    else
        func_0205d304(base + 0x90, ((struct BufStruct0218a7a0*)(base + 0x1000))->buf, 0, 0, 0, 1, 0);
#else
    int flag2 = ((tm1 / 16) > 0) ? 1 : 0;

    func_0205d304(base + 0xac, ((struct BufStruct0218a7a0*)(base + 0x1000))->buf, 0, 0, flag2, 1, 0, 0);
#endif
}
