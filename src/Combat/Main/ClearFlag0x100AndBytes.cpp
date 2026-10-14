#include <globaldefs.h>

// USA: func_020888c4
ARM void ClearFlag0x100AndBytes_020888c4(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x100;
    obj[0x60] = 0;
    obj[0x83] = 0;
}
