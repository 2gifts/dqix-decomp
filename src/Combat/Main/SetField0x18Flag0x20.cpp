#include <globaldefs.h>

// USA: func_02088db8
ARM void SetField0x18Flag0x20_02088db8(unsigned char* obj) {
    *(int*)(obj + 0x18) |= 0x20;
}
