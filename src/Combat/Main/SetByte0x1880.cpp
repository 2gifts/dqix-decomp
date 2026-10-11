#include <globaldefs.h>

// USA: func_020464dc
// JPN: func_02047394
ARM void SetByte0x1880(void* obj, unsigned char value) {
#if defined(jpn)
    *((unsigned char*)obj + 0x1750) = value;
#else
    *((unsigned char*)obj + 0x1880) = value;
#endif
}
