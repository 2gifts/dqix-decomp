#include <globaldefs.h>

// USA: func_02011628
// JPN: func_02011398
ARM unsigned short GetHalfword0x63da(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    return *(unsigned short*)(base + 0x617a);
#else
    return *(unsigned short*)(base + 0x63da);
#endif
}
