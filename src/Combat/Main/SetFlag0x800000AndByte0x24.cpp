#include <globaldefs.h>

// USA: func_02088220
ARM void SetFlag0x800000AndByte0x24_02088220(void* obj, int value) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) |= 0x800000;
    base[0x24] = value;
}
