#include <globaldefs.h>

// USA: func_020a2ca0
ARM void ResetFields0x2c4SetByte0x2c5_020a2ca0(unsigned char* obj) {
    obj[0x2c4] = 0;
    *(unsigned short*)(obj + 0x2c6) = 0;
    obj[0x2c5] = 1;
}
