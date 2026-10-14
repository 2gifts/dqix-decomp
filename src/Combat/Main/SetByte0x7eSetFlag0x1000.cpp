#include <globaldefs.h>

// USA: func_02088e48
ARM void SetByte0x7eSetFlag0x1000_02088e48(unsigned char* obj, unsigned char val) {
    obj[0x7e] = val;
    obj[0xa1] = 0;
    *(int*)(obj + 0x18) |= 0x1000;
}
