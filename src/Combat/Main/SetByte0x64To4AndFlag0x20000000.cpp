#include <globaldefs.h>

// USA: func_02088a34
ARM void SetByte0x64To4AndFlag0x20000000_02088a34(unsigned char* obj) {
    obj[0x64] = 4;
    obj[0x87] = 0;
    *(int*)(obj + 0x14) |= 0x20000000;
}
