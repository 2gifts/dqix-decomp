#include <globaldefs.h>

// USA: func_02088964
ARM void ClearFlag0x4000000AndBytes_02088964(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x4000000;
    obj[0x66] = 0;
    obj[0x89] = 0;
}
