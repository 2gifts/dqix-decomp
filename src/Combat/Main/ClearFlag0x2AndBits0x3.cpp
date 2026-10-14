#include <globaldefs.h>

// USA: func_02088598
ARM void ClearFlag0x2AndBits0x3_02088598(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x2;
    *(unsigned short*)(obj + 0x22) &= ~0x3;
}
