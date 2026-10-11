#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x47e
#else
#define REGION_OFFSET_0 0x43e
#endif


extern "C" void* func_ov000_02161318(void* obj, int index);

// USA: func_ov000_02176054
ARM void ClearFlag0x43e02176054(void* obj) {
    int i;
    for (i = 0; i < 4; i++) {
        void* p = func_ov000_02161318(obj, i);
        if (p != 0) {
            *((char*)p + REGION_OFFSET_0) = 0;
        }
    }
}
