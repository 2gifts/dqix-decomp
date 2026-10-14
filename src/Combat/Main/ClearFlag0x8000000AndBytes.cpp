#include <globaldefs.h>

// USA: func_020889b4
ARM void ClearFlag0x8000000AndBytes_020889b4(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x8000000;
    base[0x62] = 0;
    base[0x85] = 0;
}
