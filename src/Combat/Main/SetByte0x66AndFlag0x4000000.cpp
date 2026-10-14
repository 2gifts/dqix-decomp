#include <globaldefs.h>

// USA: func_02088944
ARM void SetByte0x66AndFlag0x4000000_02088944(unsigned char* obj) {
    obj[0x66] = 5;
    obj[0x89] = 0;
    ((int*)obj)[5] |= 0x4000000;
}
