#include <globaldefs.h>

// USA: func_02088dc8
ARM void ClearField0x18Flag0x20_02088dc8(unsigned char* obj) {
    *(int*)(obj + 0x18) &= ~0x20;
}
