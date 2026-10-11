#include <globaldefs.h>

// USA: func_02039874
ARM int GetSignedByte0x1c9(void* obj) {
#if defined(jpn)
    return *(signed char*)((char*)obj + 0x1bd);
#else
    return *(signed char*)((char*)obj + 0x1c9);
#endif
}
