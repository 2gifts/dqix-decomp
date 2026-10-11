#include <globaldefs.h>

#if defined(jpn)
enum { kOwnerOffset = 0x218, kIndexOffset = 0x7c8 };
#else
enum { kOwnerOffset = 0x29c, kIndexOffset = 0x5d8 };
#endif

// JPN: func_ov000_021626cc
// USA: func_ov000_02160f60
ARM void* GetSlotPtr02160f60(void* obj) {
    int count = *(int*)((char*)obj + 0x5000 + kIndexOffset);
    if (count == 0) return 0;
    void* base = *(void**)((char*)obj + kOwnerOffset);
    return base ? (char*)base + 0x21c + 0x8000 + (count - 1) * 0x28 : 0;
}
