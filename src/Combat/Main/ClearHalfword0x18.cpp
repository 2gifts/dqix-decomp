#include <globaldefs.h>

// USA: func_0209bffc
ARM void ClearHalfword0x18_0209bffc(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(unsigned short*)(base + 0x18) = 0;
}
