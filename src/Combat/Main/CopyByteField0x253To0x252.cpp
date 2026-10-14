#include <globaldefs.h>

// USA: func_02039830
ARM void CopyByteField0x253To0x252_02039830(void* obj) {
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0x246) = *(unsigned char*)((char*)obj + 0x247);
#else
    *(unsigned char*)((char*)obj + 0x252) = *(unsigned char*)((char*)obj + 0x253);
#endif
}
