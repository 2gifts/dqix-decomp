#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue12FC_118C = 0x118c };
enum { kRegionValue1310_11A0 = 0x11a0 };
enum { kRegionValue126C_10FC = 0x10fc };
#else
enum { kRegionValue12FC_118C = 0x12fc };
enum { kRegionValue1310_11A0 = 0x1310 };
enum { kRegionValue126C_10FC = 0x126c };
#endif


void EmptyDestructor0205a494(void* obj);

// USA: func_ov003_0216d77c  (semantic: DestroyOverlayAllocatorsAndSetDispcnt_0216d77c)
// JPN: func_ov003_0216d258
extern "C" ARM void func_ov003_0216d77c(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    if (((SafeAllocator*)(o + kRegionValue12FC_118C))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + kRegionValue12FC_118C))->Destroy();
    }
    if (((SafeAllocator*)(o + kRegionValue1310_11A0))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + kRegionValue1310_11A0))->Destroy();
    }
    EmptyDestructor0205a494(o + kRegionValue126C_10FC);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | ((unsigned int)*(int*)o << 8);
}
