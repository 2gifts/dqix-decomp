#include <globaldefs.h>

// USA: func_020888a4
ARM void SetFlag0x100AndBytes_020888a4(unsigned char* obj) {
    obj[0x60] = 6;
    obj[0x83] = 0;
    *(int*)(obj + 0x14) |= 0x100;
}
