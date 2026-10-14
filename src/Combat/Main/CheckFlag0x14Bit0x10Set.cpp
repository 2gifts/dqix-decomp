#include <globaldefs.h>

// USA: func_020882f8
ARM int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj) {
    return (*(int*)(obj + 0x14) & 0x10) != 0;
}
