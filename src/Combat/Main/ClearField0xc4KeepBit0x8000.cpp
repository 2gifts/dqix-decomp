#include <globaldefs.h>

// USA: func_0203409c
ARM void ClearField0xc4KeepBit0x8000_0203409c(unsigned char* obj) {
    *(unsigned short*)(obj + 0xc4) &= 0xFFFF8000;
}
