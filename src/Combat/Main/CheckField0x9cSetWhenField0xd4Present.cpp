#include <globaldefs.h>

// USA: func_0204c7e0
ARM int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char* obj) {
    if (*(int*)(obj + 0xd4) == 0) return 0;
    return *(int*)(obj + 0x9c) != 0;
}
