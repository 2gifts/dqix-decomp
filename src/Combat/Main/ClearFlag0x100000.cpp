#include <globaldefs.h>

// USA: func_02088aa8
ARM void ClearFlag0x100000_02088aa8(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x100000;
}
