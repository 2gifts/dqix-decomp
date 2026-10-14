#include <globaldefs.h>

// USA: func_02089174
ARM void SetByte0x7cAndFlag0x800_02089174(unsigned char* obj) {
    obj[0x7c] = 3;
    obj[0x9f] = 0;
    ((int*)obj)[6] |= 0x800;
}
