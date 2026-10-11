#include <globaldefs.h>

// USA: func_ov023_021e20c0
ARM void ClearFields_021e20c0(void* p) {
    char* b = (char*)p;
    *(unsigned int*)(b + 0x0) = 0;
    *(unsigned int*)(b + 0x4) = 0;
    *(unsigned int*)(b + 0x8) = 0;
    *(unsigned int*)(b + 0xc) = 0;
    *(unsigned short*)(b + 0x10) = 0;
    *(unsigned short*)(b + 0x12) = 0;
    *(unsigned short*)(b + 0x14) = 0;
    *(unsigned short*)(b + 0x16) = 0;
#if !defined(jpn)
    *(unsigned short*)(b + 0x48) = 0;
    *(unsigned short*)(b + 0x4a) = 0;
#endif
}
