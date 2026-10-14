#include <globaldefs.h>

// USA: func_02088234
ARM void ClearFlag0x14Bit0x800000AndByte0x24_02088234(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x800000;
    base[0x24] = 0;
}
