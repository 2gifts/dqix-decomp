#include <globaldefs.h>

// USA: func_020890d4
ARM void SetByte0x78SetFlag0x200_020890d4(unsigned char* obj) {
    obj[0x78] = 5;
    obj[0x9b] = 0;
    ((unsigned int*)obj)[6] |= 0x200;
}
