#include <globaldefs.h>

// USA: func_020890f4
ARM void ClearFlag0x200ClearByte0x78_020890f4(unsigned char* obj) {
    ((unsigned int*)obj)[6] &= ~0x200;
    obj[0x78] = 0;
    obj[0x9b] = 0;
}
