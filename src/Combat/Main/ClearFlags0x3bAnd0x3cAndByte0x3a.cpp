#include <globaldefs.h>

// USA: func_02089758
ARM void ClearFlags0x3bAnd0x3cAndByte0x3a_02089758(unsigned char* obj) {
    obj[0x3b] &= ~0x2;
    obj[0x3c] &= ~0x40;
    obj[0x3a] = 0;
}
