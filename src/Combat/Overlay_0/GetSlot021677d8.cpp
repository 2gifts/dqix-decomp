#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x5b00
#else
#define REGION_OFFSET_0 0x5910
#endif


// USA: func_ov000_021677d8
ARM void* GetSlot021677d8(void* work, int idx) {
    if (idx >= 0) {
        if (idx < 4) {
            return (char*)work + REGION_OFFSET_0 + idx * 0x10;
        }
    }
    return (void*)0;
}
