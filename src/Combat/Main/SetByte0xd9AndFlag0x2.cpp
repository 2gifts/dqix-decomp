#include <globaldefs.h>

// USA: func_0205042c
ARM void SetByte0xd9AndFlag0x2_0205042c(unsigned char* obj, unsigned char value) {
    obj[0xd9] = value;
    obj[0xd8] |= 0x2;
}
