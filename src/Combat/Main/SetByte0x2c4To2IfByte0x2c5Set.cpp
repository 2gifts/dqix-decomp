#include <globaldefs.h>

// USA: func_020a2c8c
ARM void SetByte0x2c4To2IfByte0x2c5Set_020a2c8c(unsigned char* obj) {
    if (obj[0x2c5] != 0) {
        obj[0x2c4] = 2;
    }
}
