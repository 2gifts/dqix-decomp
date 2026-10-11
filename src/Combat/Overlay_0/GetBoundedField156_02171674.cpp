#include <globaldefs.h>

#if defined(jpn)
enum { boundedFieldOffset = 0xdc };
#else
enum { boundedFieldOffset = 0x9c };
#endif

// USA: func_ov000_02171674
// JPN: func_ov000_0217305c
ARM int GetBoundedField156_02171674(void* obj, int index) {
    if (index < 0 || index >= 0x42) return 0;
    return *(int*)((char*)obj + boundedFieldOffset + (index << 2));
}
