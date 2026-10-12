#include <globaldefs.h>
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/NSBXX/NSBXX.h"

struct Obj0207a6a4;

extern "C" void _ZN20AtmosphericEffectSet14ProcessArchiveEPS_P13SafeAllocatorPv(void* a, void* b, int c, int d);

extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);

#if defined(jpn)
#define AccumulateHandleStats0201498c func_02014758
extern "C" ARM int func_02014758(void* objRaw);
enum { kHandleOffset = 0x114, kAllocatorOffset = 0x88, kResourceOffset = 0x70, kBlock1Offset = 0x858, kBlock4Offset = 0x85c };
#else
enum { kHandleOffset = 0xf4, kAllocatorOffset = 0x68, kResourceOffset = 0x50, kBlock1Offset = 0x838, kBlock4Offset = 0x83c };
#endif

// USA: func_0201498c
ARM int AccumulateHandleStats0201498c(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    struct Obj0207a6a4* handle = (struct Obj0207a6a4*)(obj + kHandleOffset);

    if (!((AtmosphericEffectSet*)(handle))->IsArchiveLoaded()) {
        return 0;
    }

    _ZN20AtmosphericEffectSet14ProcessArchiveEPS_P13SafeAllocatorPv(handle, handle, *(int*)(obj + kAllocatorOffset), *(int*)(obj + kResourceOffset));

    void* node = (void*)(int)((AtmosphericEffectSet*)((int*)handle))->GetFirstEffect();
    while (node != NULL) {
        void* p = *(void**)((char*)node + 0x8);
        if (p != NULL) {
            int val = _ZN7Model3D7GetTEX0Ev(p);
            if (val != 0) {
                *(int*)(obj + kBlock1Offset) += NSBXX_Tex_GetBlock1Length((NSBXXTex*)val);
                *(int*)(obj + kBlock4Offset) += (int)NSBXX_Tex_GetBlock4Length((NSBXXTex*)val);
            }
        }
        node = *(void**)((char*)node + 0x100);
    }
    return 1;
}
