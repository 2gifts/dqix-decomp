#include <globaldefs.h>

// USA: func_02088adc
ARM void SetFlag0x200000ClearFlag0x100000_02088adc(unsigned char* obj) {
    unsigned int* p = (unsigned int*)(obj + 0x14);
    *p = (*p | 0x200000) & ~0x100000;
}
