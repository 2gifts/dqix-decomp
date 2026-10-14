#include <globaldefs.h>

// USA: func_020a28d0
ARM void ClearFlagAt0x240_020a28d0(unsigned char* obj) {
    *(unsigned int*)(obj + 0x240) = 0;
}
