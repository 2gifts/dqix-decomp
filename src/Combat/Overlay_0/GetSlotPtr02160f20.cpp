#include <globaldefs.h>

#if defined(jpn)
enum { kOwnerOffset = 0x218, kCachedOffset = 0x8fc, kIndexOffset = 0x7c8 };
#else
enum { kOwnerOffset = 0x29c, kCachedOffset = 0x70c, kIndexOffset = 0x5d8 };
#endif

// JPN: func_ov000_0216268c
// USA: func_ov000_02160f20
ARM void* GetSlotPtr02160f20(void* obj) {
    void* base = *(void**)((char*)obj + kOwnerOffset);
    void* cached;
    if (base == 0) return 0;
    cached = *(void**)((char*)obj + 0x7000 + kCachedOffset);
    if (cached == 0) {
        int count = *(int*)((char*)obj + 0x5000 + kIndexOffset);
        cached = (char*)base + 0x21c + 0x8000 + count * 0x28;
    }
    return cached;
}
