#include <globaldefs.h>

// USA: func_020177a8
ARM void* GetElementStride0x24_020177a8(unsigned char* obj, int index) {
#if defined(jpn)
    if (index < 0 || obj[0x497] <= index) {
#else
    if (index < 0 || obj[0x477] <= index) {
#endif
        return NULL;
    }
#if defined(jpn)
    return *(unsigned char**)(obj + 0x49c) + index * 0x24;
#else
    return *(unsigned char**)(obj + 0x47c) + index * 0x24;
#endif
}
