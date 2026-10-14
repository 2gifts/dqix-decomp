#include <globaldefs.h>

// USA: func_020397c0
ARM void SetByteField0x253_020397c0(void* obj) {
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0x247) = 1;
#else
    *(unsigned char*)((char*)obj + 0x253) = 1;
#endif
}
