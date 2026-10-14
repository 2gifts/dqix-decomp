#include <globaldefs.h>

// USA: func_020d3d78
ARM void* GetElementCount0xb4Stride0x24_020d3d78(unsigned char* obj, int index) {
#if defined(jpn)
    if (index < *(int*)(obj + 0xa0)) {
#else
    if (index < *(int*)(obj + 0xb4)) {
#endif
        #if defined(jpn)
        return obj + index * 0x20;
#else
        return obj + index * 0x24;
#endif
    }
    return NULL;
}
