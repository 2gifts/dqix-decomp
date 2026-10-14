#include <globaldefs.h>

// USA: func_020120a0
ARM void* GetField0x74deForValidIndex_020120a0(char* base, unsigned int index) {
    if (index < 4) {
#if defined(jpn)
        return base + 0x729e + index * 8;
#else
        return base + 0x74de + index * 8;
#endif
    }
    return NULL;
}
