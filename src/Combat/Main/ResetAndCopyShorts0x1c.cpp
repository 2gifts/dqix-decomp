#include <globaldefs.h>

// USA: func_020863c4
ARM void ResetAndCopyShorts0x1c_020863c4(unsigned char* obj) {
    *(int*)(obj + 0x18) = 0;
    *(unsigned short*)(obj + 0x1c) = *(unsigned short*)(obj + 0x6c);
    *(unsigned short*)(obj + 0x1e) = *(unsigned short*)(obj + 0x6e);
}
