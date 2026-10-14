#include <globaldefs.h>

// USA: func_0202c778
ARM void OrByte0x1029With0x30ClearField0x1034_0202c778(unsigned char* obj) {
    *(unsigned char*)(obj + 0x1029) |= 0x30;
    *(int*)(obj + 0x1034) = 0;
}
