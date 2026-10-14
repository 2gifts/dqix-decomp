#include <globaldefs.h>

// USA: func_02089144
ARM void ClearFlag0x400AndBytes79And9c_02089144(unsigned char* obj) {
    ((int*)obj)[6] &= ~0x400;
    obj[0x79] = 0;
    obj[0x9c] = 0;
}
