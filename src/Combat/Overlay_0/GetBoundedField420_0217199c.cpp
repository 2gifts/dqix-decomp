#include <globaldefs.h>

#if defined(jpn)
enum { boundedFieldOffset = 0x1e4 };
#else
enum { boundedFieldOffset = 0x1a4 };
#endif

// USA: func_ov000_0217199c
// JPN: func_ov000_021732ec
ARM int GetBoundedField420_0217199c(void* obj, int index) {
    if (index < 0 || index >= 0x93) return 0;
    return *(int*)((char*)obj + boundedFieldOffset + (index << 2));
}
