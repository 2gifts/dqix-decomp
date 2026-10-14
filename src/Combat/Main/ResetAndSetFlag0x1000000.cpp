#include <globaldefs.h>

// USA: func_02088150
ARM void ResetAndSetFlag0x1000000_02088150(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x800000;
    base[0x24] = 0;
    *(int*)(base + 0x14) &= ~0x2;
    *(unsigned short*)(base + 0x22) &= ~0x3;
    *(int*)(base + 0x14) &= ~0x2;
    *(unsigned short*)(base + 0x22) &= ~0x3;
    *(int*)(base + 0x14) |= 0x1000000;
    base[0x24] = 4;
}
