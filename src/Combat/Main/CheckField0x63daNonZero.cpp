#include <globaldefs.h>

// USA: func_02011610
ARM int CheckField0x63daNonZero(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    return *(unsigned short*)(base + 0x617a) != 0;
#else
    return *(unsigned short*)(base + 0x63da) != 0;
#endif
}
