#include <globaldefs.h>

// USA: func_02088a04
ARM void ClearFlag0x10000000AndBytes_02088a04(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x10000000;
    base[0x63] = 0;
    base[0x86] = 0;
}
