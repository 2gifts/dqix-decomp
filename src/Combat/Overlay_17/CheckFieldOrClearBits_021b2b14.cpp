#include <globaldefs.h>

#if defined(jpn)
#define CheckFieldOrClearBits_021b2b14 func_ov017_021b3224
#endif
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_021a2fa0(int h);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

struct Obj021b2b14 {
    unsigned char pad0[8];
    int f8;
    unsigned char pad1[0x38 - 0xc];
    int f38;
};

// USA: func_ov017_021b2b14
#if defined(jpn)
extern "C"
#endif
ARM int CheckFieldOrClearBits_021b2b14(Obj021b2b14* p) {
    if (((BackgroundLoader*)((void*)(int)BackgroundLoader::GetInstance()))->GetNumQueuedTasks() > 0) {
        return p->f8;
    }
    int h = func_ov017_0218b5b0();
    func_ov017_021a2fa0(h);
    ClearBitsInField4((unsigned int*)h, 8);
    ClearBitsInField4((unsigned int*)h, 0x10);
    p->f38 &= ~2;
    return 3;
}
