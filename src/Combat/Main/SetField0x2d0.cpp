#include <globaldefs.h>

// USA: func_020546a0
ARM void SetField0x2d0(void* obj, unsigned char value) {
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0x2c4) = value;
#else
    *(unsigned char*)((char*)obj + 0x2d0) = value;
#endif
}
