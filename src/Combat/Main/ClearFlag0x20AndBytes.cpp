#include <globaldefs.h>

// USA: func_020883fc
ARM void ClearFlag0x20AndBytes_020883fc(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x20;
    base[0x5e] = 0;
    base[0x81] = 0;
}
