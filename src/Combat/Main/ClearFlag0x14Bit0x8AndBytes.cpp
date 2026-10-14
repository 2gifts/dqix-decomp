#include <globaldefs.h>

// USA: func_020882dc
ARM void ClearFlag0x14Bit0x8AndBytes_020882dc(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x8;
    base[0x5c] = 0;
    base[0x7f] = 0;
}
