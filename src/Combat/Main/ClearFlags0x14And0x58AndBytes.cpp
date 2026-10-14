#include <globaldefs.h>

// USA: func_02087efc
ARM void ClearFlags0x14And0x58AndBytes_02087efc(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x20000;
    *(int*)(obj + 0x58) &= ~0xe00000;
    obj[0x75] = 0;
    obj[0x98] = 0;
}
