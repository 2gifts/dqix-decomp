#include <globaldefs.h>

// USA: func_020488cc
ARM void SetBool0x180Clear0x17f_020488cc(unsigned char* obj, int value) {
    obj[0x180] = value != 0;
    if (value) {
        obj[0x17f] = 0;
    }
}
