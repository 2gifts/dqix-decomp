#include <globaldefs.h>

// USA: func_ov003_021685cc
ARM void SetFlag2At_021685cc(void* obj) {
#if defined(jpn)
    *((unsigned char*)obj + 0x59b) |= 0x2;
#else
    *((unsigned char*)obj + 0x59f) |= 0x2;
#endif
}
