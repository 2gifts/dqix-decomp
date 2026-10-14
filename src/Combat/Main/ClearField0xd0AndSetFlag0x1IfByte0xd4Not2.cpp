#include <globaldefs.h>

// USA: func_0208be94
ARM void ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94(unsigned char* obj) {
    if (obj[0xd4] != 2) {
        *(unsigned short*)(obj + 0xd0) = 0;
        *(unsigned short*)(obj + 0xda) |= 1;
    }
}
