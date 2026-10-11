#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218943c func_ov012_02189d18
#endif
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void* obj, int key, int p2, int p3);
extern "C" void func_ov012_021894b4(void* obj, void* buf, int a2);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BufStruct0218943c { char pad[0x374]; void* buf; };

// USA: func_ov012_0218943c  (semantic: SetupBattleTag0218943c)
extern "C" ARM void func_ov012_0218943c(char* base) {
    unsigned char flag = *(unsigned char*)(base + 0x1000 + 0x371);
    func_ov012_021893b4(base, flag, 2, 1);

    memset(((struct BufStruct0218943c*)(base + 0x1000))->buf, 0, 0x960);

    func_ov012_021894b4(base, ((struct BufStruct0218943c*)(base + 0x1000))->buf, 0);

    func_0205d304(base + 0xac, ((struct BufStruct0218943c*)(base + 0x1000))->buf, 0, 1, 0, 0, 0, 0);
}
