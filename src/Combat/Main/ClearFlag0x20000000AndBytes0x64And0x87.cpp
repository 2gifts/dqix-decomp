#include <globaldefs.h>

// USA: func_02088a54
ARM void ClearFlag0x20000000AndBytes0x64And0x87_02088a54(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x20000000;
    obj[0x64] = 0;
    obj[0x87] = 0;
}
