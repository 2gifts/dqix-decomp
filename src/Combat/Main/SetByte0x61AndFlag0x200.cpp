#include <globaldefs.h>

// USA: func_020888f4
ARM void SetByte0x61AndFlag0x200_020888f4(unsigned char* obj) {
    obj[0x61] = 5;
    obj[0x84] = 0;
    ((int*)obj)[5] |= 0x200;
}
