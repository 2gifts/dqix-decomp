#include <globaldefs.h>

// USA: func_020a28c4
ARM void SetFlagAt0x240_020a28c4(unsigned char* obj) {
    *(unsigned int*)(obj + 0x240) = 1;
}
