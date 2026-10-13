#include <globaldefs.h>

#if defined(jpn)
enum { kEntryFieldOffset = 0x9c };
#else
enum { kEntryFieldOffset = 0xa0 };
#endif

// USA: func_ov017_021bbbe4
ARM void* GetFieldPtrA0_021bbbe4(void* obj) {
    return (char*)obj + kEntryFieldOffset;
}
