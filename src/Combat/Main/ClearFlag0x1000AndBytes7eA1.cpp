#include <globaldefs.h>

// USA: func_02088e64
ARM void ClearFlag0x1000AndBytes7eA1_02088e64(unsigned char* obj) {
    *(int*)(obj + 0x18) &= ~0x1000;
    obj[0x7e] = 0;
    obj[0xa1] = 0;
}
