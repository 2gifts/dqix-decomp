#include <globaldefs.h>

// USA: func_02088d7c
ARM void SetByte0x7dSetFlag0x100_02088d7c(unsigned char* obj) {
    obj[0x7d] = 5;
    obj[0xa0] = 0;
    *(int*)(obj + 0x18) |= 0x100;
}
