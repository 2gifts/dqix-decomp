#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Ctx021e2628 {
#if defined(jpn)
    char pad[0xc];
#else
    char pad[0x1c];
#endif
    unsigned int flags;
};
extern struct Ctx021e2628 data_ov025_021ef988;


// USA: func_ov025_021e2628
ARM int SetFlagAndDispatch_021e2628(int a, int b) {
    int r = (int)BackgroundLoader::GetInstance();
    if (!(data_ov025_021ef988.flags & 0x2000)) {
        ((BackgroundLoader*)((unsigned char*)r))->AddFence();
        data_ov025_021ef988.flags |= 0x2000;
    }
    return ((BackgroundLoader*)(r))->QueueLoadFileInGP2((const char*)(a), (const char*)(b), (SafeAllocator*)(0));
}
