#include <globaldefs.h>

// USA: func_02087df0
ARM void ClearFlagsAndBytes_02087df0(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x10000;
    *(int*)(base + 0x58) &= ~0x1c0000;
    base[0x74] = 0;
    base[0x97] = 0;
}
