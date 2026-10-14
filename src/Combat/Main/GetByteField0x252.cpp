#include <globaldefs.h>

// USA: func_02039820
ARM unsigned char GetByteField0x252_02039820(void* obj) {
#if defined(jpn)
    return *((unsigned char*)obj + 0x246);
#else
    return *((unsigned char*)obj + 0x252);
#endif
}
