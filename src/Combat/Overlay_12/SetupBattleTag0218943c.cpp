#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218943c func_ov012_02189d18
#define func_ov012_021893b4 func_ov012_02189c90
#define func_ov012_021894b4 func_ov012_02189d8c
#endif
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void* obj, int key, int p2, int p3);
extern "C" void func_ov012_021894b4(void* obj, void* buf, int a2);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufStruct0218943c {
#if defined(jpn)
    char pad[0x344];
#else
    char pad[0x374];
#endif
    void* buf;
};

// USA: func_ov012_0218943c  (semantic: SetupBattleTag0218943c)
extern "C" ARM void func_ov012_0218943c(char* base) {
#if defined(jpn)
    unsigned char flag = *(unsigned char*)(base + 0x1000 + 0x341);
#else
    unsigned char flag = *(unsigned char*)(base + 0x1000 + 0x371);
#endif
    func_ov012_021893b4(base, flag, 2, 1);

#if defined(jpn)
    memset(((struct BufStruct0218943c*)(base + 0x1000))->buf, 0, 0x800);
#else
    memset(((struct BufStruct0218943c*)(base + 0x1000))->buf, 0, 0x960);
#endif

    func_ov012_021894b4(base, ((struct BufStruct0218943c*)(base + 0x1000))->buf, 0);

#if defined(jpn)
    func_0205d304(base + 0x90, ((struct BufStruct0218943c*)(base + 0x1000))->buf, 0, 1, 0, 0, 0);
#else
    func_0205d304(base + 0xac, ((struct BufStruct0218943c*)(base + 0x1000))->buf, 0, 1, 0, 0, 0, 0);
#endif
}
