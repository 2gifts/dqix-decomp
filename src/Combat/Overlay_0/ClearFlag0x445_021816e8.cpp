#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x485
#else
#define REGION_OFFSET_0 0x445
#endif


extern "C" void* func_ov000_02161318(void* obj, int index);

// USA: func_ov000_021816e8
ARM void ClearFlag_021816e8_021816e8(void* obj, int index) {
    void* p;
    int i;
    if (index < 0) {
        for (i = 0; i < 4; i++) {
            p = func_ov000_02161318(obj, i);
            if (p != 0) *((char*)p + REGION_OFFSET_0) = 0;
        }
    } else {
        p = func_ov000_02161318(obj, index);
        if (p != 0) *((char*)p + REGION_OFFSET_0) = 0;
    }
}
