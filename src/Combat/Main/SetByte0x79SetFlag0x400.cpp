#include <globaldefs.h>

// USA: func_02089124
ARM void SetByte0x79SetFlag0x400_02089124(unsigned char* obj) {
    obj[0x79] = 5;
    obj[0x9c] = 0;
    ((unsigned int*)obj)[6] |= 0x400;
}
